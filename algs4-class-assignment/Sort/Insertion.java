import java.util.Comparator;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Insertion {
    public Insertion() {
    }
    
    public static void sort(Comparable[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            for (int j = i; j > 0 && less(a[j], a[j-1]); j--) {
                    exch(a, j, j - 1);
            }
        }
    }
    
    public static void sort(Comparable[] a, int lo, int hi) {
        for (int i = lo; i < hi; i++) {
            for (int j = i; j > lo && less(a[j], a[j-1]); j--) {
                exch(a, j, j - 1);
            }
        }
        
    }
    
    public static void sort(Object[] a, Comparator comprator) {
        int n = a.length;
        for (int i = 0; i < n; i++)
            for (int j = i; j > 0 && less(a[j], a[j-1], comprator); j--)
                exch(a, j, j-1);
    }
    
    public static void sort(Object[] a, int lo, int hi, Comparator comprator) {
        for (int i = lo; i < hi; i++)
            for (int j = i; j > lo && less(a[j], a[j-1], comprator); j--) {
               exch(a, j, j-1);
            }
    }
    
    public static int[] indexSort(Comparable[] a) {
        int n = a.length;
        int[] index = new int[n];
        for (int i = 0; i < n; i++)
            index[i] = i;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j > 0 && less(a, index[j], index[j-1]); j--) {
                exch(index, j, j-1);
            }
        }
        return index;
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
        show(Insertion.indexSort(a));
        show(a);
    }
    
}