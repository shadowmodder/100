import java.util.List;
import java.util.ArrayList;

import edu.princeton.cs.algs4.SET;
import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;

public class PointSET {
    private final SET<Point2D> points;
    
    public PointSET() {
        points = new SET<Point2D>();
    }
    
    public boolean isEmpty() {
        return points.isEmpty();
        
    }
    
    public int size() {
        return points.size();
    }
    
    public void insert(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("point is null");
        points.add(p);
    }
    
    public boolean contains(Point2D p) {
        return points.contains(p);
    }
    
    public void draw() {
        for (Point2D p: points)
            p.draw();
    }
    
    public Iterable<Point2D> range(RectHV rect) {
        if (rect == null)
            throw new IllegalArgumentException("rect is null");
        
        List<Point2D> inRange = new ArrayList<Point2D>();
        for (Point2D p: points) {
            if (rect.contains(p))
                inRange.add(p);
        }
        return inRange;
    }
    
    public Point2D nearest(Point2D p) {
        double minDis = Integer.MAX_VALUE;
        Point2D ret = null;
        for (Point2D p0: points) {
            double dist = p0.distanceSquaredTo(p);
            if (dist < minDis) {
                minDis = dist;
                ret = p0;
            }
        }
        return ret;
    }
    
    
}