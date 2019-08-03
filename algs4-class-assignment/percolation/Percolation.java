/**
 * To model a percolation system using an N-by-N grid of sites.
 * Each site is either open or blocked. A full site is an open site that can
 * be connected to an open site in the top row via a chain of neighboring
 * (left, right, up, down) open sites. The system percolates if there
 * is a full site in the bottom row. In other words, a system percolates if
 * we fill all open sites connected to the top row and that process fills
 * some open site on the bottom row.
 */

/**
 * @author njxfma
 * 
 */
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private static final int[][] OP = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    private final int totalRow;
    private final int totalCol;
    private final int gridSize;
    private boolean[][] grids;
    private int totalOpen = 0;
    private final WeightedQuickUnionUF  wUF; 
    
    public Percolation(int n) {
        if (n <= 0) 
            throw new IllegalArgumentException("Size is not correct " + n);
        
        totalRow = n;
        totalCol = n;
        gridSize = n * n;
        wUF = new WeightedQuickUnionUF(gridSize + 2);
        grids = new boolean[totalRow][totalCol];
    }
        
    public    void open(int row, int col) {
        row = row - 1;
        col = col - 1;
        checkbounder(row, col);

        if (grids[row][col]) return;
        
        int curId = row * totalCol + col;
        grids[row][col] = true;
        totalOpen++;
        for (int i = 0; i < OP.length; i++) {
            int nr = row + OP[i][0];
            int nc = col + OP[i][1];
            int nId = nr * totalCol + nc;
            
            if (nc < 0 || nc >= totalCol) continue;
            if (nr < 0) nId = gridSize;
            if (nr >= totalRow) nId = gridSize + 1;
            
            if (nr < 0 || nr >= totalRow || grids[nr][nc]) {
                wUF.union(curId, nId);
            }
        }
    }
    
    public boolean isOpen(int row, int col) {
        row = row - 1;
        col = col - 1;
        checkbounder(row, col);
        
        return grids[row][col];
    }
    
    public boolean isFull(int row, int col) {
        row = row - 1;
        col = col - 1;
        checkbounder(row, col);
        
        if (!grids[row][col]) return false;
        else
            return wUF.find(row * totalCol + col) == wUF.find(gridSize);
    }
    
    public     int numberOfOpenSites() {
        return totalOpen;
    }
    
    public boolean percolates() {
        return wUF.find(gridSize) == wUF.find(gridSize + 1);

    }

    private void checkbounder(int row, int col) {
       if (row < 0 || row >= totalRow || col < 0 || col >= totalCol) 
           throw new IllegalArgumentException("out of range for "
                                                  + row + " " + col);
    }
    
    public static void main(String[] args) {
        Percolation p = new Percolation(5);
        p.open(1, 2);
        p.open(2, 3);
        p.open(4, 4);
        p.open(2, 1);
        System.out.println("(0, 0) is open : "+ p.isFull(0, 2));
        System.out.println("percolation? : "+ p.percolates());
        System.out.println("number of open? : "+ p.numberOfOpenSites());
    }
}