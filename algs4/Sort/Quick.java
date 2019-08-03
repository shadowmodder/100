import java.util.Comparator;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Quick {
    public Quick() {
    }
    
    public static void sort(Comparable[] a) {
        StdRandom.shuffle(a);
        sort(a, 0, a.length - 1);
    }
    
    public static void sort(Comparable[] a, int lo, int hi) {
        if (lo >= hi) return;
        
        int j = partition(a, lo, hi);
        sort(a, lo, j - 1);
        sort(a, j + 1, hi);
    }
    
    private static int partition(Comparable[] a, int lo, int hi) {
        int i = lo;
        int j = hi + 1;
        Comparable v = a[lo];
        
        while (true) {
            while (less(a[++i], v)) {
                if (i == hi) break;
            }
            
            while (less(v, a[--j])) {
                if (j == lo) break;
            }
            
            if (i >= j) break;
            
            exch(a, i, j);
        }
        exch(a, lo, j);
        return j;
    }
    
    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    
    private static boolean less(Object v, Object w, Comparator comparator) {
        return comparator.compare(v, w) < 0;
    }
    
    private static boolean less(Comparable[] a, int i, int j) {
        return a[i].compareTo(a[j]) < 0;
    }
    
    private static void exch(Object[] a, int i, int j) {
        Object temp = a[i];
        a[i] = a[j];
        a[j] = a[i];
    }
    
    private static void exch(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    private static void show(Comparable a[]) {
        int n = a.length;
        for (int i = 0; i < n; i++)
            StdOut.println(a[i]);
    }
    
    private static void show(int a[]) {
        int n = a.length;
        for (int i = 0; i < n; i++)
            StdOut.println(a[i]);
    }
    
    public static void main(String[] args) {
        String[] a = StdIn.readAllStrings();
        Quick.sort(a);
        show(a);
    }
    
}