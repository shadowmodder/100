import edu.princeton.cs.algs4.BinaryStdIn;
import edu.princeton.cs.algs4.BinaryStdOut;

public class MoveToFront {
    private static final int TOTAL = 256;
        
    public static void encode() {
        char[] seq = initSeq();
        while (!BinaryStdIn.isEmpty()) {
            char in = BinaryStdIn.readChar();
            char out = (char) moveFront(seq, in);
            BinaryStdOut.write(out);
        }
        BinaryStdOut.close();
    }
    
    private static int moveFront(char[] seq, char elem) {
        int index = -1;
        
        for (int i = 0; i < TOTAL; i++) {
            if (elem == seq[i]) {
                for (int j = i; j > 0; j--) {
                    seq[j] = seq[j - 1];
                }
                seq[0] = elem;
                index = i;
                break;
            }
        }
        return index;
    }
    
    private static char[] initSeq() {
        char[] seq = new char[TOTAL];
        for (int i = 0; i < TOTAL; i++)
            seq[i] = (char) i;
        return seq;
    }
    
    public static void decode() {
        char[] seq = initSeq();
        while (!BinaryStdIn.isEmpty()) {
            char id = BinaryStdIn.readChar();
            char elem = seq[id];
            BinaryStdOut.write(elem);
            moveFront(seq, elem);
        }
        BinaryStdOut.close();
    }
    
    public static void main(String[] args) {
        if (args.length == 0)
            throw new IllegalArgumentException("Invalid args");
        
        if (args[0].equals("-")) {
            encode();
        } else if (args[0].equals("+")) {
            decode();
        }
    }
}