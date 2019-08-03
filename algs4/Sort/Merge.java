import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import java.util.Comparator;

public class Merge {
    public Merge() {
    }
    
    public static void sort(Comparable a[]) {
        Comparable aux[];
        aux = new Comparable[a.length];
        sort(a, aux, 0, a.length - 1);
    }
    
    public static int[] indexSort(Comparable a[]) {
        int n = a.length;
        int index[] = new int[n];
        int aux[] = new int[n];
        
        for (int i = 0; i < n; i++) index[i] = i;
        
        indexSort(a, index, aux, 0, n-1);
        return index;
    }
    
    
    private static void sort(Comparable[] a, Comparable[] aux, int lo, int hi) {
        if (lo >= hi) return;
        
        int mid = lo + (hi - lo) / 2;
        sort(a, aux, lo, mid);
        sort(a, aux, mid + 1, hi);
        merge(a, aux, lo, mid, hi);
    }
    
    private static void merge(Comparable[] a, Comparable[] aux, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) 
            aux[i] = a[i];
        
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) a[k] = aux[j++];
            else if (j > hi) a[k] = aux[i++];
            else if (less(a[i], a[j])) a[k] = a[i++];
            else a[k] = a[j++];
        }
    }

    
     private static void indexSort(Comparable[] a, int[] index, int[] aux, int lo, int hi) {
        if (lo >= hi) return;
        
        int mid = lo + (hi - lo) / 2;
        indexSort(a, index, aux, lo, mid);
        indexSort(a, index, aux, mid + 1, hi);
        merge(a, index, aux, lo, mid, hi);
    }   
    private static void merge(Comparable[] a, int[] index, int[] aux, int lo, int mid, int hi) {
       int n = index.length;
       for (int i = 0; i < n; i++)
           aux[i] = index[i];
       
       int i = lo, j = mid + 1;
       for (int k = i; k <= hi; k++) {
           if (i > mid) aux[k] = index[j++];
           else if (j > hi) aux[k]= index[i++];
           else if (less(a[index[i]], a[index[j]])) aux[k] = index[i++];
           else aux[k] = index[j++];
       }
    }
        
    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    
    private static void show(Comparable[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++)
            StdOut.println(a[i]);
    }
    
    private static void show(int[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++)
            StdOut.println(a[i]);
    }
    
    public static void main(String[] args) {
        String[] a = StdIn.readAllStrings();
        show(Merge.indexSort(a));
        show(a);
    }
}