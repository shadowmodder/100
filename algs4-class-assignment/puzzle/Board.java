import java.util.List;
import java.util.ArrayList;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;

public class Board {
    private static final int SPACE = 0;
    private final int[][] input;
    private final int spaceX;
    private final int spaceY;
    private int manhattanDist;
    
    public Board(int[][] blocks) {
        if (blocks == null)
            throw new IllegalArgumentException("Invalid input blocks");
        
        manhattanDist = -1;
        int zeroX = 0;
        int zeroY = 0;
        
        input = new int[blocks.length][blocks[0].length];
        for (int i = 0; i < blocks.length; i++)
            for (int j = 0; j < blocks[0].length; j++) {
                input[i][j] = blocks[i][j];
                if (input[i][j] == SPACE) {
                    zeroX = i;
                    zeroY = j;
                }
        }
        
        spaceX = zeroX;
        spaceY = zeroY;
    }
    
    public int dimension() {
        return input.length;
    }
    
    public int hamming() {
        int target = 1;
        int cnt = 0;
        
        for (int i = 0; i < dimension(); i++)
            for (int j = 0; j < dimension(); j++) {
                if (input[i][j] != target) cnt++;
                target++;
        }
        
        return (cnt - 1);
    }
    
    public int manhattan() {
        if (manhattanDist == -1)
            manhattanDist = calManhattan();
        return manhattanDist;
    }
    
    private int calManhattan() {
        int cnt = 0;
        for (int i = 0; i < dimension(); i++)
            for (int j = 0; j < dimension(); j++) {
                if (input[i][j] == 0) continue;
                int correctX = (input[i][j] - 1) / dimension();
                int correctY = (input[i][j] - 1) % dimension();
                cnt += Math.abs(correctX - i) + Math.abs(correctY - j);
        }
        return cnt;
    }
    
    public boolean isGoal() {
        int target = 1;
        int maxElems = dimension() * dimension();
        for (int i = 0; i < dimension(); i++)
            for (int j = 0; j < dimension(); j++) {
                if (input[i][j] != target)
                    return false;
                target++;
                if (target == maxElems)
                    target = 0;
        }
        return true;
    }
    
    public Board twin() {
        int[] swapIndex = new int[] {-1, -1};
        int[][] output = new int[dimension()][dimension()];
        
        copyArray(input, output);
        for (int i = 0; i < dimension(); i++)
            for (int j = 0; j < dimension(); j++) {
            if (input[i][j] != 0) {
                if (swapIndex[0] == -1) {
                    swapIndex[0] = i;
                    swapIndex[1] = j;
                } else {
                    int temp = output[i][j];
                    output[i][j] = output[swapIndex[0]][swapIndex[1]];
                    output[swapIndex[0]][swapIndex[1]] = temp;
                    return new Board(output);
                }
            }
        }
            
        return null;
    }
    
    public boolean equals(Object y) {
        if (y == null || y.getClass() != this.getClass()) 
            return false;
        
        if (((Board) y).input.length != dimension() ||
            ((Board) y).input[0].length != dimension())
            return false;
        
        for (int i = 0; i < dimension(); i++)
            for (int j = 0; j < dimension(); j++) {
                if (input[i][j] != ((Board) y).input[i][j])
                    return false;
        }
        
        return true;
    }
    
    public Iterable<Board> neighbors() {
        int[][] neighbors =
            new int[][] {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        List<Board> ans = new ArrayList<Board>();
        
        for (int i = 0; i < neighbors.length; i++) {
            int nx = spaceX + neighbors[i][0];
            int ny = spaceY + neighbors[i][1];
            if (nx < 0 || nx >= dimension() || ny < 0 || ny >= dimension())
                continue;
            int[][] output = new int[dimension()][dimension()];
            copyArray(input, output);
            output[spaceX][spaceY] = output[nx][ny];
            output[nx][ny] = 0;
            
            int correctX = (input[nx][ny] - 1) / dimension();
            int correctY = (input[nx][ny] - 1) % dimension();
            int delta = Math.abs(correctX - spaceX) +
                        Math.abs(correctY - spaceY) -
                        Math.abs(correctX - nx) - Math.abs(correctY - ny);
            Board neighbor = new Board(output);
            neighbor.manhattanDist = manhattan() + delta; 
            ans.add(neighbor);    
        }
        
        return ans;
    }
    
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(dimension() + "\n");
        for (int i = 0; i < dimension(); i++) {
            for (int j = 0; j < dimension(); j++)
                sb.append(String.valueOf(input[i][j]) + " ");
            sb.append(String.valueOf("\n"));
        }
        
        return sb.toString();
    }

    private void copyArray(int[][] in, int[][] out) {
        if (in.length != out.length ||
            in[0].length != out[0].length)
            return;
        
        for (int i = 0; i < in.length; i++)
            for (int j = 0; j < in[0].length; j++) {
            out[i][j] = in[i][j];
        }
    }
    
    public static void main(String[] args) {

        // create initial board from file
        In in = new In(args[0]);
        int n = in.readInt();
        int[][] blocks = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                blocks[i][j] = in.readInt();
        Board initial = new Board(blocks);
        StdOut.printf("hamming:%d manhattan:%d\n", initial.hamming(), initial.manhattan());
        StdOut.println(initial.toString());
        
        StdOut.println(initial.twin().toString());
        
        for (Board neighbor : initial.neighbors()) {
            StdOut.printf("hamming:%d manhattan:%d\n", neighbor.hamming(), neighbor.manhattan());
            StdOut.println(neighbor.toString());
        }
    }
}