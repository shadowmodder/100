import java.util.Iterator;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] data;
    private int capacity = 0;
    private int sz = 0;
    
    public RandomizedQueue() {
        data = (Item[]) new Object[1];
        capacity = 1;
    }
    
    public boolean isEmpty() {
        return sz == 0;
    }
    
    public int size() {
        return sz;
    }
    
    public void enqueue(Item item) {
        checkAugument(item);
        
        data[sz] = item;
        sz++;
        increaseCapacity();
    }
    
    public Item dequeue() {
        if (isEmpty())
            throw new java.util.NoSuchElementException("No element.");
        
        int r = StdRandom.uniform(0, sz);
        Item item = data[r];
        sz--;
        data[r] = data[sz];
        decreaseCapacity();
        return item;
    }
    
    public Item sample() {
        if (isEmpty())
            throw new java.util.NoSuchElementException("No element.");
        
        int r = StdRandom.uniform(0, sz);
        return data[r];
    }
    
    public Iterator<Item> iterator() {
        return new ItemIterator(data, sz);   
    }
    
    public static void main(String[] args) {
        
        RandomizedQueue<Integer> d = new RandomizedQueue<Integer>();
        for (int i = 0; i < 10; i++) {
            d.enqueue(i);
        }

        Iterator<Integer> it = d.iterator();
        while (it.hasNext()) {
            StdOut.printf("%s ", it.next());
        }
        
        StdOut.printf("\n");
        
        Iterator<Integer> it2 = d.iterator();
        while (it2.hasNext()) {
            StdOut.printf("%s ", it2.next());
        }
        
        StdOut.printf("\n");
        for (int i = 0; i < 10; i++) {
            StdOut.printf("%d ", d.dequeue());
        }
        
    }
    
    private class ItemIterator implements Iterator<Item> {
        int iterated = 0;
        Item[] data;
        public ItemIterator(Item[] d, int size) {
            data = (Item[]) new Object[size];
            for (int i = 0; i < size; i++) data[i] = d[i];
            sz = size;
        }
        
        public boolean hasNext() {
            return ((sz  - iterated) > 0);
        }
        
        public Item next() {
            if (!this.hasNext())
                throw new java.util.NoSuchElementException("no next item.");
            int r = StdRandom.uniform(0, sz - iterated);
            
            Item item = data[r];
            data[r] = data[sz - iterated - 1];
            data[sz - iterated - 1] = item;
            
            iterated++;
            return item;
        }
        
        public void remove() {
            throw new java.lang.UnsupportedOperationException("Not support.");
        }
    }

    private void checkAugument(Object obj) {
        if (obj == null)
            throw new java.lang.IllegalArgumentException("Error parameter.");
    }
    
    private void increaseCapacity() {
        if (sz >= capacity) {
            capacity = capacity * 2;
            Item[] newData = (Item[]) new Object[capacity];
            for (int i = 0; i < sz; i++) {
                newData[i] = data[i];
            }
            data = newData;
        }
    }
    
    private void decreaseCapacity() {
        if (sz <= capacity / 4) {
            capacity = capacity / 2;
            Item[] newData = (Item[]) new Object[capacity];
            for (int i = 0; i < sz; i++) {
                newData[i] = data[i];
            }
            data = newData;
        }
    }
    
}