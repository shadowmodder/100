import java.util.HashSet;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class BoggleSolver
{
    private static final int MAX_ELEMS = 26;
    private static final int U_INDEX = 'U' - 'A';
    private static final int[] POINTS = {0, 0, 0, 1, 1, 2, 3, 5, 11};
    private static final int[][] OPS = {{0, -1}, {-1, 0}, {0, 1}, {1, 0},
                                        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    private final Node root;
    
    public BoggleSolver(String[] dictionary) {
        if (dictionary == null)
            throw new IllegalArgumentException("Invalid dictionary");
            
        root = new Node();
        for (String word: dictionary) {
            buildTries(root, word);
        }
    }
    
    public Iterable<String> getAllValidWords(BoggleBoard board) {
        if (board == null)
            throw new IllegalArgumentException("Invalid board");
        
        HashSet<String> results = new HashSet<String>();  
        BoggleBoard b = copyBoard(board);
        
        for (int row = 0; row < b.rows(); row++)
            for (int col = 0; col < b.cols(); col++) {
                boolean[][] visited = new boolean[b.rows()][b.cols()];
                visited[row][col] = true;
                depthSearch(b, row, col, visited, results, root);
        }
        
        return results;
    }
    
    public int scoreOf(String word) {
        if (word == null)
            throw new IllegalArgumentException("Invalid word input");
        if (!isInDictionary(word)) return 0;
        
        if (word.length() >= POINTS.length) return POINTS[POINTS.length - 1];
        else return POINTS[word.length()];
    }
    
    private boolean isInDictionary(String word) {
        if (word.length() < 3) return false;
        
        Node cur = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word.charAt(i) - 'A';
            if (cur.child[idx] == null)  return false;
            cur = cur.child[idx];
        }
        
        return cur.isWord;
    }
    
    private void depthSearch(BoggleBoard b, int row, int col,
                     boolean[][] visited,
                     HashSet<String> results,
                     Node tries) {
        int index = b.getLetter(row, col) - 'A';
        Node cur = tries.child[index];
               
        if (cur == null) return;
        
        if (b.getLetter(row, col) == 'Q') {
            cur = cur.child[U_INDEX];
            if (cur == null) return;
        }
        
        if (cur.isWord) {
            results.add(cur.val);
        }
        
        for (int i = 0; i < OPS.length; i++) {
            int nr = row + OPS[i][0];
            int nc = col + OPS[i][1];
            if (nr < 0 || nr >= b.rows() || nc < 0 || nc >= b.cols()) 
                continue;
            
            if (visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            depthSearch(b, nr, nc, visited, results, cur);
            visited[nr][nc] = false;
        }
    }
    
    private class Node {
        String val;
        Node[] child;
        boolean isWord;
        public Node() {
            isWord = false;
            child = new Node[MAX_ELEMS];
            for (int i = 0; i < MAX_ELEMS; i++) {
                child[i] = null;   
            }
        }
    }
    
    private void buildTries(Node r, String word) {
        if (word.length() < 3) return;
        
        Node cur = r;
        for (int i = 0; i < word.length(); i++) {
            int idx = word.charAt(i) - 'A';
            if (cur.child[idx] == null) {
                cur.child[idx] = new Node();
            }
            cur = cur.child[idx];
        }
        cur.val = word;
        cur.isWord = true;
    }
    
    private static BoggleBoard copyBoard(BoggleBoard board) {
        int rows = board.rows();
        int cols = board.cols();
        char[][] b = new char[rows][cols];
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
            b[r][c] = board.getLetter(r, c);    
        }
        return new BoggleBoard(b);
    }
    
    
    public static void main(String[] args) {
        In in = new In(args[0]);
        String[] dictionary = in.readAllStrings();
        BoggleSolver solver = new BoggleSolver(dictionary);
        BoggleBoard board = new BoggleBoard(args[1]);
        
        int score = 0;
        for (String word : solver.getAllValidWords(board)) {
            StdOut.println(word);
            score += solver.scoreOf(word);
        }
        StdOut.println("Score = " + score);
   }

 }