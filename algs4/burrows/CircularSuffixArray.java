import edu.princeton.cs.algs4.StdOut;


public class CircularSuffixArray {
    private final int len;
    private final char[] input;
    private int[] index;
    
    public CircularSuffixArray(String s) {
        if (s == null) throw new IllegalArgumentException("Invalid input");
        
        char[] chars = s.toCharArray();
        input = s.toCharArray();
        len = chars.length;
        index = new int[len];
        
        for (int i = 0; i < len; i++)
            index[i] = i;
        
        mergeSort(chars, 0, len - 1);
    }
    
    public int length() {
        return len;
    }
    
    public int index(int i) {
        if (i < 0 || i >= len)
            throw new IllegalArgumentException("Out of range: " + i +
                                               " range: [0, " + len + "]");
        
        return index[i];
    }
    
    private void mergeSort(char[] chars, int start, int end) {
        if (start >= end) return;
        
        int mid = start + (end - start) / 2;
        mergeSort(chars, start, mid);
        mergeSort(chars, mid + 1, end);
        mergePartitions(chars, start, mid, end);
    }
    
    private void mergePartitions(char[] chars, int s, int m, int e) {
        char[] targetChars = new char[e - s + 1];
        int [] targetIndex = new int[e - s + 1];
        int first = s;
        int second = m + 1;
        int cnt = 0;
        
        while (first <= m && second <= e) {
            if (compareCirucularStr(first, second)) {
                targetIndex[cnt] = index[first];
                targetChars[cnt++] = chars[first++];
            } else {
                targetIndex[cnt] = index[second];
                targetChars[cnt++] = chars[second++];
            }
        }
        
        while (first <= m) {
            targetIndex[cnt] = index[first];
            targetChars[cnt++] = chars[first++];
        }
        
        while (second <= e) {
            targetIndex[cnt] = index[second];
            targetChars[cnt++] = chars[second++];
        }
        
        for (int i = s; i <= e; i++) {
            index[i] = targetIndex[i - s];
            chars[i] = targetChars[i - s];
        }
    }
    
    private boolean compareCirucularStr(int first, int second) {
        int oriFirst = index[first];
        int oriSecond = index[second];
        int cnt = 0;
        while (input[oriFirst] == input[oriSecond] &&
               cnt < len) {
            oriFirst = (oriFirst + 1) % len;
            oriSecond = (oriSecond + 1) % len;
            cnt++;
        }
        return input[oriFirst] <= input[oriSecond];
    }
    
    public static void main(String[] args) {
        String in = "helzlol";
        CircularSuffixArray c = new CircularSuffixArray(in);
        StdOut.println("input String: " + in);
        StdOut.printf("string len: %d\n", c.length());
        for (int i = 0; i < in.length(); i++)
             StdOut.printf("%d ", c.index(i));
             
    } 
}