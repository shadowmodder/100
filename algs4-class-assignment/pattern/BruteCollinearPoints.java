import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class BruteCollinearPoints {
    private final List<LineSegment> segs = new ArrayList<LineSegment>();
    
    public BruteCollinearPoints(Point[] points) {
     if (points == null)
         throw new java.lang.IllegalArgumentException(" Point array is empty");
     
     Point[] copy = new Point[points.length];
     for (int i = 0; i < points.length; i++) {
         if (points[i] == null)
             throw new java.lang.IllegalArgumentException("null point");
         copy[i] = points[i];
     }
     
     Arrays.sort(copy);
     for (int i = 0; i < copy.length - 1; i++) {
         if (copy[i].compareTo(copy[i+1]) == 0)
             throw new java.lang.IllegalArgumentException("Duplicated");
     }
     
     for (int first = 0; first < copy.length; first++)
         for (int second = first + 1; second < copy.length; second++) {
             double slope = copy[first].slopeTo(copy[second]);
               for (int third = second + 1; third < copy.length; third++) {
                   if (Double.compare(slope,
                              copy[first].slopeTo(copy[third])) != 0)
                           continue;
                 for (int forth = third + 1; forth < copy.length; forth++) {
                     if (Double.compare(slope,
                                 copy[first].slopeTo(copy[forth])) == 0) {
                        segs.add(new LineSegment(copy[first], copy[forth]));
                     }
                 }
              }
         }
    }
    
    public           int numberOfSegments() {
        return segs.size();
    }
    
    public LineSegment[] segments() {
        LineSegment[] ls = new LineSegment[segs.size()];
        for (int i = 0; i < segs.size(); i++)
            ls[i] = segs.get(i);
        return ls;
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
   
        BruteCollinearPoints bc = new BruteCollinearPoints(points);
        LineSegment[] ls = bc.segments();
        for (int i = 0; i < bc.numberOfSegments(); i++)
            StdOut.printf(ls[i].toString() + "\n");
    }
}