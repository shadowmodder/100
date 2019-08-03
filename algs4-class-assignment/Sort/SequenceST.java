import java.util.Comparator;
import java.util.Queue;
import java.util.LinkedList;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

class SequenceST <Key, Value> {
    private int n = 0;
    private Node first;
    
    private class Node {
        Key key;
        Value value;
        Node next;
        public Node(Key key, Value value, Node next) {
            this.key   = key;
            this.value = value;
            this.next  = next;
        }
    }
    
    public SequenceST() {}
    
    public int size() {
        return n;
    }
    
    public boolean isEmpty() {
        return n == 0;
    }
    
    public Value get(Key k) {
        if (k == null) 
            throw new IllegalArgumentException("first argument to put() is null");
        for (Node x = first; x != null; x = x.next) {
            if (k.equals(x.key)) {
                return x.value;
            }
        }
        return null;
    }
    
    public void put(Key k, Value v) {
        if (k == null) 
            throw new IllegalArgumentException("first argument to put() is null"); 
        
        if (v == null) delete(k);
        
        for (Node x = first; x != null; x = x.next) {
            if (k.equals(x.key)) {
                x.value = v;
            }
        }
        
        first = new Node(k, v, first);
        n++;
    }
    
    public void delete(Key k) {
        if (k == null) 
            throw new IllegalArgumentException("first argument to put() is null");
        first = delete(first, k);
    }
    
    private Node delete(Node x, Key k) {
        if (x == null) return null;
        if (k.equals(x.key)) {
            n--;
            return x.next;
        }
        
        x.next = delete(x.next, k);
        
        return x;
    }
    
    public Iterable<Key> keys() {
        Queue<Key> queue = new LinkedList<Key>();
        for (Node x = first; x != null; x = x.next) {
            queue.add(x.key);
        }
        return queue;
    }
    
    public static void main(String[] args) {
        SequenceST<String, Integer> st = new SequenceST<String, Integer>();
        st.put("hello", 2);
        st.put("word", 3);
        StdOut.println(st.get("hello"));
        for (String s: st.keys()) {
            StdOut.println(s);
        }
    }
}