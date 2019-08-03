import edu.princeton.cs.algs4.BinaryStdIn;
import edu.princeton.cs.algs4.BinaryStdOut;

import java.util.ArrayList;
import java.util.List;


public class BurrowsWheeler {
    private static final int TOTAL = 256;
    
    public static void transform() {
        
        String s = BinaryStdIn.readString();
        char[] data = s.toCharArray();
        int len = data.length;
        
        CircularSuffixArray c = new CircularSuffixArray(s);
  
               
        for (int i = 0; i < len; i++) {
            if (c.index(i) == 0) {
                BinaryStdOut.write(i);
                break;
            }
        }
    

        for (int i = 0; i < len; i++) {
            int j = c.index(i) - 1;
            if (j < 0) j = len - 1;
            BinaryStdOut.write(data[j]);
        }
        BinaryStdOut.close();
    }
    
     public static void inverseTransform() {
         int first = BinaryStdIn.readInt();
         
         char[] t = BinaryStdIn.readString().toCharArray();
         int len = t.length;
         
         Target[] arr = new Target[TOTAL];
         for (int i = 0; i < len; i++) {
            char id = t[i];
            if (arr[id] != null) {
                arr[id].list.add(i);
            } else {
                arr[id] = new Target();
                List<Integer> list = new ArrayList<Integer>();
                list.add(i);
                arr[id].addList(list);
            }
        }
 
        int[] next = new int[len];
        char[] firstCol = new char[len];
        int cnt = 0;
        for (int i = 0; i < TOTAL; i++) {
            if (arr[i] != null) {
                for (int j: arr[i].list) {
                    firstCol[cnt] = (char) i;
                    next[cnt++] = j;
                }
            }
        }
        
        
        // for (int i = 0; i < cnt; i++)
        //    StdOut.printf("%d ", next[i]);
         
        
        for (int i = 0, originalIndex = first; i < len; i++) {    
            BinaryStdOut.write(firstCol[originalIndex]);
            originalIndex = next[originalIndex];
            
        }
        
        BinaryStdOut.close();
     }
    
    private static class Target {
        public List<Integer> list;
        
        public Target() {
           list = null;    
        }
        
        public void addList(List<Integer> n) {
            list = new ArrayList<Integer>(n);
        }
    }
    
    public static void main(String[] args) {
        if (args.length == 0)
            throw new IllegalArgumentException("Invalid args");
        
        if (args[0].equals("-")) {
            transform();
        } else if (args[0].equals("+")) {
            inverseTransform();
        }
    }
}