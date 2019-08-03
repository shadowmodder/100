import java.util.Comparator;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
    
public class Selection {
    public Selection() {
    }
    
    public static void sort(Comparable[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (less(a[j], a[min])) min = j;
            }
            exch(a, i, min);           
        }
    }

    public static void sort(Object[] a, Comparator comparator) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (less(comparator, a[j], a[min])) min = j; 
            }
            exch(a, i, min);
        }
    }
    
    public static void show(Object[] a) {
        for (int i = 0; i < a.length; i++)
            StdOut.println(a[i]);
    }
        
    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }
    
    private static boolean less(Comparator comparator, Object v, Object w) {
        return comparator.compare(v, w) < 0;
    }
    
    private static  void exch(Object[] a, int i, int j) {
        Object temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    public static void main(String args[]) {
        String[] input = StdIn.readAllStrings();
        Integer[] a = new Integer[input.length];
        for (int i = 0; i < input.length; i++)
            a[i] = Integer.valueOf(input[i]);
        
        Selection.sort(a);
        show(a);
    }
}
