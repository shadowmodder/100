import java.util.Iterator;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {
    public Permutation() {
    }
    
    public static void main(String[] args) { 
        RandomizedQueue<String> rq = new RandomizedQueue<String>();  
        
        while (!StdIn.isEmpty()) {
            rq.enqueue(StdIn.readString());
        }
        int k = Integer.parseInt(args[0]);
        if (k <= 0) return;
        
        Iterator<String> it = rq.iterator();
        while (it.hasNext() && k > 0) {
            StdOut.printf("%s\n", it.next());
            k = k - 1;
        }
    }
    
}