import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import edu.princeton.cs.algs4.StdDraw;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class FastCollinearPoints {
    private final List<LineSegment> segs;
    
    public FastCollinearPoints(Point[] points) {
        if (points == null)
         throw new java.lang.IllegalArgumentException(" Point array is empty");
        
        Point[] copies = new Point[points.length];
        for (int i = 0; i < points.length; i++) {
             copies[i] = points[i];
             if (points[i] == null)
                 throw new java.lang.IllegalArgumentException("Point is null");
        }
        
        Arrays.sort(copies);
        if (hasDuplicated(copies)) {
            throw new java.lang.IllegalArgumentException("Duplicated points");
        }
        
        segs = new ArrayList<LineSegment>();
        
        for (int i = 0; i < copies.length; i++) {
            Arrays.sort(copies);
            Point pivot = copies[i];
            List<Point> copy = new ArrayList<Point>(Arrays.asList(copies));
            copy.remove(i);
            copy.sort(pivot.slopeOrder());
            
            int cnt = 1;
            for (int j = 1; j < copy.size(); j++) {
                if (Double.compare(pivot.slopeTo(copy.get(j)),
                    pivot.slopeTo(copy.get(j - 1))) == 0) {
                    cnt++;
                } else {
                    if (cnt >= 3 &&
                       pivot.compareTo(copy.get(j-cnt)) < 0) {
                       segs.add(new LineSegment(pivot, copy.get(j-1)));  
                    } 
                    cnt = 1;
                }
                            
                if (cnt >= 3 && j == copy.size() - 1 &&
                   pivot.compareTo(copy.get(j-cnt+1)) < 0) {
                   segs.add(new LineSegment(pivot, copy.get(j)));   
                }
            }
        }
        
    }
    
    public           int numberOfSegments() {
        return segs.size();
    }
    

    public LineSegment[] segments() {
        LineSegment[] ret = new LineSegment[segs.size()];
        for (int i = 0; i < segs.size(); i++) {
            ret[i] = segs.get(i);
        }
        return ret;
    }
       
   public static void main(String[] args) {

    In in = new In(args[0]);
    int n = in.readInt();
    Point[] points = new Point[n];
    for (int i = 0; i < n; i++) {
        int x = in.readInt();
        int y = in.readInt();
        points[i] = new Point(x, y);
    }

    StdDraw.setPenRadius(0.005);
    StdDraw.setPenColor(StdDraw.BLUE);
    StdDraw.setScale(0, 25);
    StdDraw.enableDoubleBuffering();
    StdDraw.setXscale(0, 32768);
    StdDraw.setYscale(0, 32768);
    for (Point p : points) {
        p.draw();
    }

    FastCollinearPoints collinear = new FastCollinearPoints(points);
    for (LineSegment segment : collinear.segments()) {
        StdOut.println(segment);
        segment.draw();
    }
    StdDraw.show();
}
   private boolean hasDuplicated(Point[] ps) {
       for (int i = 1; i < ps.length; i++) {
           if (ps[i].compareTo(ps[i-1]) == 0)
               return true;
       }
       return false;
   }
}