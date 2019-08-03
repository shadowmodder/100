import edu.princeton.cs.algs4.Picture;
import edu.princeton.cs.algs4.StdOut;

public class SeamCarver {
    private static final double MAX_ENERGY = 1000.0;
    private Picture pic = null;
    private double[][] energies;
    private double[][] hDistTo;
    private int[][] hEdgeTo;
    private double[][] vDistTo;
    private int[][] vEdgeTo;
    
    public SeamCarver(Picture picture) {
        if (picture == null)
            throw new IllegalArgumentException("picture is null");
        pic = new Picture(picture); 
        
        updateEnergy();
    }

    private void updateEnergy() {
        energies = new double[height()][width()];
        
        for (int x = 0; x < width(); x++)
            for (int y = 0; y < height(); y++)
                energies[y][x] = calEnergy(x, y);
    }
    
    private void calMinVerticalPath() {
        vDistTo = new double[height()][width()];
        vEdgeTo = new int[height()][width()];
         for (int x = 0; x < width(); x++)
            for (int y = 0; y < height(); y++) {
                vDistTo[y][x] = energies[y][x];
        }       
         
        for (int y = height() - 2; y >= 0; y--)
            for (int x = 0; x < width(); x++) {
                double left = (x > 0) ? vDistTo[y + 1][x - 1] :
                                         Double.POSITIVE_INFINITY;
                double right = (x < width() - 1) ? vDistTo[y + 1][x + 1]  
                                         : Double.POSITIVE_INFINITY;
                double bottom = vDistTo[y + 1][x];
            
                int pathIndex = x;
                double minEnergy = bottom;
            
                if (left < minEnergy)  {
                    pathIndex = x - 1;
                    minEnergy = left;
                }
                if (right < minEnergy) {
                    pathIndex = x + 1;
                    minEnergy = right;
                }
            
                vDistTo[y][x] += minEnergy;
                vEdgeTo[y][x] =  pathIndex;
            }
    }
   
    private void calMinHorizontalPath() {
        hDistTo = new double[height()][width()];
        hEdgeTo = new int[height()][width()];
         for (int x = 0; x < width(); x++)
            for (int y = 0; y < height(); y++) {
                hDistTo[y][x] = energies[y][x];
        }
         
        for (int x = width() - 2; x >= 0; x--)
            for (int y = 0; y < height(); y++) {
                double up  = (y > 0) ? hDistTo[y - 1][x + 1] :
                                       Double.POSITIVE_INFINITY;
                double down = (y < height() - 1) ? hDistTo[y + 1][x + 1]  
                                         : Double.POSITIVE_INFINITY;
                double right = hDistTo[y][x + 1];
            
                int pathIndex = y;
                double minEnergy = right;
            
                if (up < minEnergy)  {
                    pathIndex = y - 1;
                    minEnergy = up;
                }
                if (down < minEnergy) {
                    pathIndex = y + 1;
                    minEnergy = down;
                }
            
                hDistTo[y][x] += minEnergy;
                hEdgeTo[y][x] =  pathIndex;
            }
    }
        
    public Picture picture() {
        return new Picture(pic);
    }
    
    public     int width() {
        return pic.width();
    }
    
    public     int height() {
        return pic.height();
    }
    
    public double energy(int x, int y) {
      if (x < 0 || x >= width() || y < 0 || y >= height())
          throw new IllegalArgumentException("x=" + x +
                                             " y=" + y + " out of range"); 
      return energies[y][x];
    }
    
    private double calEnergy(int x, int y) {
        if (x < 0 || x >= width() || y < 0 || y >= height())
            throw new IllegalArgumentException("x, y is out of range");
        
        if (x == 0 || x == width() - 1 || y == 0 || y == height() - 1)
            return MAX_ENERGY;
        
        double deltaX = getDifferatial(pic.getRGB(x - 1, y),
                                       pic.getRGB(x + 1, y));
        double deltaY = getDifferatial(pic.getRGB(x, y - 1),
                                       pic.getRGB(x, y + 1));

        return Math.sqrt(deltaX + deltaY);
    }

    private double getDifferatial(int firstRgb, int secondRgb) {
       return Math.pow(((firstRgb >> 16) & 0xFF) -
                       ((secondRgb >> 16) & 0xFF), 2) + 
              Math.pow(((firstRgb >> 8) & 0xFF) -
                       ((secondRgb >> 8) & 0xFF), 2) +
              Math.pow((firstRgb & 0xFF) - (secondRgb & 0xFF), 2);  
    }

    public   int[] findHorizontalSeam() {
        if (pic == null)
            throw new IllegalArgumentException("picture is null");

        calMinHorizontalPath();   
        
        int[] ret = new int[width()];
        double minPixelEnergy = hDistTo[0][0];
        
        for (int y = 1; y < height(); y++) {
            if (hDistTo[y][0] < minPixelEnergy) {
                ret[0] = y;
                minPixelEnergy = hDistTo[y][0];
            }
        }
        
        for (int x = 1; x < width(); x++) {
            ret[x] = hEdgeTo[ret[x - 1]][x - 1];
        }
        
        if (width() >= 2) {    
            if (ret[width() - 2] == 0) {
                ret[width() - 1] = ret[width() - 2];
            } else {
                ret[width() - 1] = ret[width() - 2] - 1;
            }
        }
         
        return ret;
    }
    
    public   int[] findVerticalSeam() {
        if (pic == null)
            throw new IllegalArgumentException("picture is null");
   
        calMinVerticalPath();
                     
        int[] ret = new int[height()];
        double minPixelEnergy = vDistTo[0][0];
        
        for (int x = 1; x < width(); x++) {
            if (vDistTo[0][x] < minPixelEnergy) {
                ret[0] = x;
                minPixelEnergy = vDistTo[0][x];
            }
        }
        
        for (int y = 1; y < height(); y++) {
            ret[y] = vEdgeTo[y - 1][ret[y - 1]];
        }
        
        if (height() >= 2) {
            if (ret[height() - 2] == 0) {
                 ret[height() - 1] = ret[height() - 2];
            } else {
                 ret[height() - 1] = ret[height() - 2] - 1;
            }
        }
         
        return ret;    
    }
    
    public    void removeHorizontalSeam(int[] seam) {
        if (seam == null)
            throw new IllegalArgumentException("seam is null");
        
        if (!checkSeam(seam, width(), height() - 1))
            throw new IllegalArgumentException("seam is not correct");
        
        Picture newPic = new Picture(width(), height() - 1);
        for (int y = 0; y < height() - 1; y++)
            for (int x = 0; x < width(); x++) {
                int oldY = (y >= seam[x]) ? (y + 1) : y;
                newPic.setRGB(x, y, pic.getRGB(x, oldY));
        }
            
        pic = newPic;
        updateEnergy();
    }

    public    void removeVerticalSeam(int[] seam) {
        if (seam == null)
            throw new IllegalArgumentException("seam is null");
        if (!checkSeam(seam, height(), width() - 1))
            throw new IllegalArgumentException("seam is not correct");
        
        Picture newPic = new Picture(width() - 1, height());
        for (int y = 0; y < height(); y++)
            for (int x = 0; x < width() - 1; x++) {
                int oldX = (x >= seam[y]) ? (x + 1) : x;
                newPic.setRGB(x, y, pic.getRGB(oldX, y));
        }
            
        pic = newPic;
        updateEnergy();
    }
    
    private boolean checkSeam(int[] seam, int size, int maxValue) {
        if (seam.length != size) return false;
        for (int i = 0; i < size; i++) {
            if (seam[i] < 0 || seam[i] > maxValue) return false;
            if (i > 0 && Math.abs(seam[i] - seam[i - 1]) > 1) return false;
        }
        return true;
    }
    
     public static void main(String[] args) {
        Picture picture = new Picture(args[0]);
        StdOut.printf("image is %d columns by %d rows\n",
                      picture.width(), picture.height());
        picture.show();     
        for (int row = 0; row < picture.height(); row++) {
            for (int col = 0; col < picture.width(); col++) {
             StdOut.printf("(%d %d %d) ",
                           (picture.getRGB(col, row) >> 16) & 0xFF,
                           (picture.getRGB(col, row) >> 8) & 0xFF,
                      (picture.getRGB(col, row) >> 16) & 0xFF);
            }
           StdOut.printf("\n");
        }
        
        
        
        SeamCarver sc = new SeamCarver(picture);
        
        StdOut.printf("Displaying energy calculated.\n");
        for (int row = 0; row < sc.height(); row++) {
            for (int col = 0; col < sc.width(); col++) {
                StdOut.printf("%f ", sc.energy(col, row));
            }
            StdOut.printf("\n");
        }
        
        
        StdOut.printf("\nDisplaying horizontal seam calculated.\n");
        int[] hs = sc.findHorizontalSeam();
        for (int i = 0; i < hs.length; i++)
            StdOut.printf("%d ", hs[i]);
        StdOut.printf("\n");

        StdOut.printf("\nDisplaying vertical seam calculated.\n");
        int[] vs = sc.findVerticalSeam();
        for (int i = 0; i < vs.length; i++)
            StdOut.printf("%d ", vs[i]);
        StdOut.printf("\n");


    }
}