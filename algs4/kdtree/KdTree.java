import java.util.List;
import java.util.ArrayList;

import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;

public class KdTree {
    private KdNode root;
    private int setSize;
    
    private class KdNode {
        Point2D point;
        KdNode left;
        KdNode right;
        public KdNode(Point2D k) {
            point = k;
            left = null;
            right = null;
        } 
    }
    
    public KdTree() {
        root = null;
        setSize = 0;
    }
    
    public boolean isEmpty() {
        return size() == 0;
    }
    
    public int size() {
        return setSize;
    }
    
    public boolean contains(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("point is null");
        
        return search(p) != null;
    }
    
    private Point2D search(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("point is null");
        
        return search(root, p, 0);
    }
    
    private Point2D search(KdNode r, Point2D p, int level) {
        if (r == null) return null;
        
        int move = compareKey(p, r.point, level);
        
        if (move == 0) return r.point;
        else if (move < 0) {
            return search(r.left, p, level + 1);
        } else {
            return search(r.right, p, level + 1);
        }
    }
    
    private int compareKey(Point2D first, Point2D second, int level) {
        if (first.equals(second)) return 0;
        
        int ret;
        int xCompare = Double.compare(first.x(), second.x());
        int yCompare = Double.compare(first.y(), second.y());
        
        if (level % 2 == 0) {
            ret = xCompare == 0 ? yCompare : xCompare;
        } else {
            ret = yCompare == 0 ? xCompare : yCompare;
        }
        
        return ret;
    }
    
    public void insert(Point2D p) {
        if (p == null)
            throw new IllegalArgumentException("point is null");
                
        root = insert(root, p, 0);
    }
    
    private KdNode insert(KdNode r, Point2D p, int level) {        
        if (r == null) {
            setSize++;           
            return new KdNode(p);
        }
        
        int move = compareKey(p, r.point, level);
        
        if (move < 0) {
            r.left = insert(r.left, p, level + 1);
        } else if (move > 0) {
            r.right = insert(r.right, p, level + 1);
        }
        
        return r;
    }
    
    public Iterable<Point2D> range(RectHV rect) {
        if (rect == null) 
            throw new IllegalArgumentException("rect is null");
        if (root == null)
            return null;
        
        List<Point2D> points = new ArrayList<Point2D>();
        range(rect, root, points, 0);
        return points;
    }
    
    private void range(RectHV rect, KdNode r, List<Point2D> points, int level) {
        if (r == null) return;

        if (rect.contains(r.point)) {
            points.add(r.point);
        }
        
        if ((level % 2 == 0 && rect.xmax() < r.point.x()) ||
            (level % 2 != 0 && rect.ymax() < r.point.y())) {
            range(rect, r.left, points, level + 1);
        } else if  ((level % 2 == 0 && rect.xmin() > r.point.x()) ||
                    (level % 2 != 0 && rect.ymin() > r.point.y())) {
            range(rect, r.right, points, level + 1);
        } else {
            range(rect, r.left, points, level + 1);
            range(rect, r.right, points, level + 1);
        }
    }
    
    public Point2D nearest(Point2D that) {
        if (that == null)
            throw new IllegalArgumentException("that point is null");
        if (root == null)
            return null;
        
        return nearest(that, root, 0, root.point);
    }
    
    private Point2D nearest(Point2D p, KdNode r,
                         int level, Point2D np) {
        if (r == null) return np;
        
        if (Double.compare(p.distanceSquaredTo(r.point),
                           p.distanceSquaredTo(np)) < 0) {
            np = r.point;
        }
        
        int move = compareKey(p, r.point, level);
        // check near side
        KdNode next = move < 0 ? r.left : r.right;
        
        np = nearest(p, next, level + 1, np);
        
        // other side
        if ((level % 2 == 0 &&
             Double.compare(p.distanceSquaredTo(np),
                            Math.pow(r.point.x() - p.x(), 2)) > 0) ||
             (level % 2 != 0 &&
             Double.compare(p.distanceSquaredTo(np),
                            Math.pow(r.point.y() - p.y(), 2)) > 0))   {
            KdNode other = move < 0 ? r.right : r.left;
            np = nearest(p, other, level + 1, np);
        }
        
        return np;
    }
    

    
    public void draw() {
        if (root == null)
            throw new IllegalArgumentException("Tree is null");
        draw(root);
    }
    
    private void draw(KdNode r) {
        if (r == null) return;
        
        draw(r.left); 
        r.point.draw();
        draw(r.right);
    }
    
}