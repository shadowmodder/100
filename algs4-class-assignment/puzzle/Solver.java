import java.util.List;
import java.util.ArrayList;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.MinPQ;

public class Solver {
    private List<Board> solutions;
    
    private class BoardWrapper implements Comparable<BoardWrapper> {
        Board block;
        BoardWrapper parent;
        int steps;
        public BoardWrapper(Board c, BoardWrapper p) {
            block = c;
            parent = p;
            steps = (p == null) ? 0 : (p.steps + 1);
        }
        
        public int compareTo(BoardWrapper that) {
            return (block.manhattan() + steps) -
                   (that.block.manhattan() + that.steps);
        }
    }
    
    public Solver(Board initial) {
        if (initial == null)
            throw new IllegalArgumentException("Invalid input blocks");
        
        MinPQ<BoardWrapper> mq = new MinPQ<BoardWrapper>();
        MinPQ<BoardWrapper> twinQ = new MinPQ<BoardWrapper>();
        mq.insert(new BoardWrapper(initial, null));
        twinQ.insert(new BoardWrapper(initial.twin(), null));
        int lockStep = 0;
        
        while (!mq.isEmpty() && !twinQ.isEmpty()) {
            if (lockStep % 2 == 0) {
                BoardWrapper cur = mq.delMin();
                    if (searchBoard(mq, cur)) {
                        solutions = new ArrayList<Board>();
                        getSolutions(cur);
                        break;
                    }
            } else {
                BoardWrapper cur = twinQ.delMin();
                    if (searchBoard(twinQ, cur)) {
                        break;
                    }
            }
            lockStep++;
        }
    }
    
    private boolean searchBoard(MinPQ<BoardWrapper> mq, BoardWrapper cur) {
        if (cur.block.isGoal()) {
            return true;
        }
        for (Board n : cur.block.neighbors()) {
            if (cur.parent == null || !n.equals(cur.parent.block))
                mq.insert(new BoardWrapper(n, cur));
        }
        return false;
    }
    
    private void getSolutions(BoardWrapper target) {
        if (target == null) {
            return;
        }       
        getSolutions(target.parent);
        solutions.add(target.block);
    }
    
    public boolean isSolvable() {
        return solutions != null;
    }
    
    public int moves() {
        int ret = -1;
        
        if (isSolvable()) ret = solutions.size() - 1;
        
        return ret;
    }
    
    public Iterable<Board> solution() {
        return solutions;
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
        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board);
        }
    }
}