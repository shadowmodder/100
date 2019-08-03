import java.util.Iterator;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RandomizedQueue2<Item> implements Iterable<Item> {
    private final Deque<Item> dq;
    
    public RandomizedQueue2() {
        dq = new Deque<Item>();
    }
    
    public boolean isEmpty() {
        return dq.isEmpty();
    }
    
    public int size() {
        return dq.size();
    }
    
    public void enqueue(Item item) {
        dq.addFirst(item);
    }
    
    public Item dequeue() {
        int r = StdRandom.uniform(0, dq.size());
        return removeItem(r);
        /*
        Item[] firstPart = (Item[]) new Object[r];
        while (r > 0) {
            firstPart[r] = dq.removeFirst();
            r--;
        }

        for (int i = 1; i <= r; i++) {
            dq.addFrist(firstPart[i]);
        }
        return firstPart[0]; */
    }
    
    public Item sample() {
        int r = StdRandom.uniform(0, dq.size());
        return peekItem(r);
        /*
        Iterator<Item> it = dq.iterator();
        while (r > 0) {
            it.next();
            r--;
        }
        return it.next();
        */
    }
    
    public Iterator<Item> iterator() {
        return new ItemIterator(dq);   
    }
    
    public static void main(String[] args) {
        
        RandomizedQueue<Integer> d = new RandomizedQueue<Integer>();
        for (int i = 0; i < 100; i++) {
            d.enqueue(i);
        }

        Iterator<Integer> it = d.iterator();
        while (it.hasNext()) {
            StdOut.printf("%s ", it.next());
        }
        
    }
    
    private class ItemIterator implements Iterator<Item> {
        int iterated = 0;
        Deque<Item> dq;
        
        public ItemIterator(Deque<Item> d) {
            dq = d;
        }
        
        public boolean hasNext() {
            return ((dq.size()  - iterated) > 0);
        }
        
        public Item next() {
            if (!this.hasNext())
                throw new java.util.NoSuchElementException("no next item.");
            int r = StdRandom.uniform(0, dq.size() - iterated);   
            Item item = removeItem(r);
            dq.addLast(item);
            iterated++;
            return item;
        }
        
        public void remove() {
            throw new java.lang.UnsupportedOperationException("Not support.");
        }
    }
    
    private Item removeItem(int r) {
        if (r < 0 || r > dq.size() - 1) 
            throw new java.util.NoSuchElementException("No " + r + " element.");
        Item result;
        if (r == 0) {
           result = dq.removeFirst();
        } else if (r == dq.size() - 1) {
           result = dq.removeLast();
        } else {
            for (int i = 0; i < r; i++) {
                dq.addLast(dq.removeFirst());
            }
            result = dq.removeFirst();
        }
        return result;
    }
    
    private Item peekItem(int r) {
        if (r < 0 || r > dq.size() - 1) 
            throw new java.util.NoSuchElementException("No " + r + " element.");
                Item result;
        if (r == 0) {
           result = dq.removeFirst();
           dq.addFirst(result);
        } else if (r == dq.size() - 1) {
           result = dq.removeLast();
           dq.addLast(result);
        } else {
            for (int i = 0; i < r; i++) {
                dq.addLast(dq.removeFirst());
            }
            result = dq.removeFirst();
            dq.addFirst(result);
        }
        
        return result;
    }
    
    
}