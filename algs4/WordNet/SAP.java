import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class SAP {
    private final Digraph g;
      
    public SAP(Digraph G) {
        g = new Digraph(G);
    }
    
    public int length(int v, int w) {
        validateVertex(v);
        validateVertex(w);
        int minLen = Integer.MAX_VALUE;
        HashMap<Integer, Integer> vpath = bfs(v);
        HashMap<Integer, Integer> wpath = bfs(w);
        
        for (int wnode: wpath.keySet()) { 
            if (vpath.get(wnode) != null) {
                int curLen = vpath.get(wnode) + wpath.get(wnode);
                if (minLen > curLen) minLen = curLen;
            }
        }
        
        if (minLen == Integer.MAX_VALUE) return -1;
        return minLen;
    }
    
    public int ancestor(int v, int w) {
        validateVertex(v);
        validateVertex(w);
        
        HashMap<Integer, Integer> vpath = bfs(v);
        HashMap<Integer, Integer> wpath = bfs(w);
        int minLen = Integer.MAX_VALUE;
        int ancNode = -1;
        
        for (int wnode: wpath.keySet()) {
            if (vpath.get(wnode) != null) {
                int curLen = vpath.get(wnode) + wpath.get(wnode);
                if (minLen > curLen) {
                    minLen = curLen;
                    ancNode = wnode;
                }
            }
        }
        
        return ancNode;
    }
    
    public int length(Iterable<Integer> v, Iterable<Integer> w) {
        if (v == null || w == null)
            throw new IllegalArgumentException("vertex is not valid.");
        
        int minLen = Integer.MAX_VALUE;
        for (int x : v) {
            for (int y: w) {
                int len = length(x, y);
                if (len != -1 && len < minLen) {
                    minLen = len;
                }   
            }
        }
        
        if (minLen == Integer.MAX_VALUE) return -1;
        
        return minLen;
    }
    
    public int ancestor(Iterable<Integer> v, Iterable<Integer> w) {
        if (v == null || w == null)
            throw new IllegalArgumentException("vertex is not valid.");
        
        int minLen = Integer.MAX_VALUE;
        int anc = -1;
        for (int x : v) {
            for (int y: w) {
                int len = length(x, y);
                if (len != -1 && len < minLen) {
                    minLen = len;
                    anc = ancestor(x, y);
                }
            }
        }
        
        return anc;
    }
    
    public static void main(String[] args) {
        In in = new In(args[0]);
        Digraph G = new Digraph(in);
        
        SAP sap = new SAP(G);
        while (!StdIn.isEmpty()) {
            int v = StdIn.readInt();
            int w = StdIn.readInt();
            int length   = sap.length(v, w);
            int ancestor = sap.ancestor(v, w);
            StdOut.printf("length = %d, ancestor = %d\n", length, ancestor);
        }
    }
 
    private void validateVertex(int v) {
        if (v < 0 || v >= g.V())
            throw new IllegalArgumentException("vertex is not valid.");
    }
       
     private HashMap<Integer, Integer> bfs(int v) {
        HashMap<Integer, Integer> path = new HashMap<Integer, Integer>();
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[g.V()];
        int level = 0;
        
        if (!q.offer(v)) {
            throw new IllegalArgumentException();
        }
        visited[v] = true;
        path.put(v, level++);
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int p = q.poll();
                for (int neighbor: g.adj(p)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        if (!q.offer(neighbor))
                            throw new IllegalArgumentException();
                        path.put(neighbor, level);
                    }
                }
            }
            level++;
        }
        
        return path;
    }
}