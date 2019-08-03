/******************************************************************************
 *  Compilation:  javac Point.java
 *  Execution:    java Point
 *  Dependencies: none
 *  
 *  An immutable data type for points in the plane.
 *  For use on Coursera, Algorithms Part I programming assignment.
 *
 ******************************************************************************/

import java.util.Comparator;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class Point implements Comparable<Point> {

    private final int x;     // x-coordinate of this point
    private final int y;     // y-coordinate of this point

    /**
     * Initializes a new point.
     *
     * @param  x the <em>x</em>-coordinate of the point
     * @param  y the <em>y</em>-coordinate of the point
     */
    public Point(int x, int y) {
        /* DO NOT MODIFY */
        this.x = x;
        this.y = y;
    }

    /**
     * Draws this point to standard draw.
     */
    public void draw() {
        /* DO NOT MODIFY */
        StdDraw.point(x, y);
    }

    /**
     * Draws the line segment between this point and the specified point
     * to standard draw.
     *
     * @param that the other point
     */
    public void drawTo(Point that) {
        /* DO NOT MODIFY */
        StdDraw.line(this.x, this.y, that.x, that.y);
    }

    /**
     * Returns the slope between this point and the specified point.
     * Formally, if the two points are (x0, y0) and (x1, y1), then the slope
     * is (y1 - y0) / (x1 - x0). For completeness, the slope is defined to be
     * +0.0 if the line segment connecting the two points is horizontal;
     * Double.POSITIVE_INFINITY if the line segment is vertical;
     * and Double.NEGATIVE_INFINITY if (x0, y0) and (x1, y1) are equal.
     *
     * @param  that the other point
     * @return the slope between this point and the specified point
     */
    public double slopeTo(Point that) {
        checkParam(that);
        
        if (x == that.x) {
            return (y != that.y) ? Double.POSITIVE_INFINITY
                : Double.NEGATIVE_INFINITY;
        } else if (y == that.y) {
            return 0.0;
        } else {
            return (double) (y - that.y) / (x - that.x);
        }
    }

    /**
     * Compares two points by y-coordinate, breaking ties by x-coordinate.
     * Formally, the invoking point (x0, y0) is less than the argument point
     * (x1, y1) if and only if either y0 < y1 or if y0 = y1 and x0 < x1.
     *
     * @param  that the other point
     * @return the value <tt>0</tt> if this point is equal to the argument
     *         point (x0 = x1 and y0 = y1);
     *         a negative integer if this point is less than the argument
     *         point; and a positive integer if this point is greater than the
     *         argument point
     */
    public int compareTo(Point that) {
        checkParam(that);
            
        int ret = 0;
        
        if (y == that.y) {
            if (x < that.x) ret = -1;
            else if (x == that.x) ret = 0;
            else ret = 1;
        } else {
            ret = (y < that.y) ? -1 : 1;
        }
        
        return ret;
    }

    /**
     * Compares two points by the slope they make with this point.
     * The slope is defined as in the slopeTo() method.
     *
     * @return the Comparator that defines this ordering on points
     */
    public Comparator<Point> slopeOrder() {
        return  new BySlope();
    }


    private class BySlope implements Comparator<Point>
    {
        public int compare(Point p1, Point p2) {
            int ret =  Double.compare(slopeTo(p1), slopeTo(p2));
            if (ret == 0) ret = p1.compareTo(p2);
            return ret;
        }
        
    }
    
    /**
     * Returns a string representation of this point.
     * This method is provide for debugging;
     * your program should not rely on the format of the string representation.
     *
     * @return a string representation of this point
     */
    public String toString() {
        /* DO NOT MODIFY */
        return "(" + x + ", " + y + ")";
    }

    /**
     * Unit tests the Point data type.
     */
    public static void main(String[] args) {
        StdDraw.setPenRadius(0.001);
        StdDraw.setPenColor(StdDraw.BLUE);
        StdDraw.setScale(0, 25);
        Point p0 = new Point(1, 10);
        Point p1 = new Point(1, 20);
        p0.drawTo(p1);
        
         Point[] p = new Point[4];
               p[0] = new Point(10, 3);
               p[1] = new Point(10, 6);
               p[2] = new Point(10, 4);
               p[3] = new Point(10, 20);
        Arrays.sort(p, p[2].slopeOrder());
        for (int i = 0; i < p.length; i++) {
            StdOut.printf("%s ", p[i].toString());
        }

    }
    
    private void checkParam(Point p) {
        if (p == null)
         throw new java.lang.NullPointerException("empty");
    }
}