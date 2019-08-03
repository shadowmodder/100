import java.util.Iterator;

import edu.princeton.cs.algs4.StdOut;

public class Deque<Item> implements Iterable<Item> {
    private Node first = null;
    private Node last  = null;
    private int total = 0;
    
    private class Node {
       Item item;
       Node next;
       Node prev;
       
       Node(Item n) {
           item = n;
           next = null;
           prev = null;
       }
    }
    
    public Deque() {
        
    }
    
    public boolean isEmpty() {
        return total == 0;
    }
    
    public int size() {
        return total;
    }
    
    public void addFirst(Item item) {
        checkAugument(item);
        
        Node n = new Node(item);
        n.next = first;

        if (first == null || last == null) {
            first = n;
            last = n;
        } else {
            first.prev = n;
            first = n;
        }
        
        total++;
    }
    
    public void addLast(Item item) {
        checkAugument(item);
        
        Node n = new Node(item);
        if (first == null || last == null) {
            first = n;
            last = n;
        } else {
            n.prev = last;
            last.next = n;
            last = n;
        }
        total++;
    }
    
    public Item removeFirst() {
        if (first == null) 
            throw new java.util.NoSuchElementException("No first element.");
        Item item = first.item;
        first = first.next;
        total--;
        if (isEmpty()) last = null;
        else first.prev = null;
        
        return item;
    }
    
    public Item removeLast() {
        if (last == null) 
            throw new java.util.NoSuchElementException("No last element.");
        
        Item item = last.item;
        if (first == last) {
            first = null;
            last  = null;
        } else {
            last = last.prev;
            last.next = null;
        }
        
        total--;
        return item;
    }
    
    public Iterator<Item> iterator() {
        return new ItemIterator(this, first);
    }
    
    public static void main(String[] args) {
        Deque<String> d = new Deque<String>();
        d.addLast("hello");
        d.addFirst("world");
        StdOut.printf("%s \n", d.removeFirst());
        StdOut.printf("%s \n", d.removeLast());
        Iterator<String> it = d.iterator();
        while (it.hasNext()) {
            StdOut.printf("%s ", it.next());
        }
    }
    
    private void checkAugument(Object obj) {
        if (obj == null)
            throw new java.lang.IllegalArgumentException("Error parameter.");
    }
    
    private class ItemIterator implements Iterator<Item> {
        Deque<Item> cur;
        Node first;
        int iterated = 0;
        public ItemIterator(Deque<Item> d, Node f) {
            cur = d;
            first = f;
        }
        
        public boolean hasNext() {
            return (cur.total  - iterated != 0);
        }
        
        public Item next() {
            if (!this.hasNext())
                throw new java.util.NoSuchElementException("no next item.");
            Item item = first.item;
            first = first.next;
            iterated++;
            return item;
        }
        
        public void remove() {
            throw new java.lang.UnsupportedOperationException("Not support.");
        }
    }
    
}