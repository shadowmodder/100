import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private final double meanVal;
    private final double stddevVal;
    private final double confidenceloVal;
    private final double confidencehiVal;

    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0) 
            throw new IllegalArgumentException("Size or trial is not correct "
                                                   + n + " " + trials);
        
        double[] x = new double[trials];
        for (int i = 0; i < trials; i++) {
            Percolation p = new Percolation(n);
            while (!p.percolates()) {
                int r = StdRandom.uniform(1, n+1);
                int c = StdRandom.uniform(1, n+1);
                p.open(r, c);
            }
            x[i] = (p.numberOfOpenSites() * 1.0) / (n * n);
        }
        meanVal = StdStats.mean(x);
        stddevVal = StdStats.stddev(x);
        double std = 1.96 * stddevVal / Math.sqrt(trials);
        confidenceloVal = meanVal - std;
        confidencehiVal = meanVal + std;
    }

    public double mean() {
        return meanVal;
    }
    
    public double stddev() {
        return stddevVal;
    }
    
    public double confidenceLo() {
        return confidenceloVal;
    }
    
    public double confidenceHi() {
        return confidencehiVal;
    }

    public static void main(String[] args) {
        PercolationStats p = new PercolationStats(200, 100);
        System.out.println("mean is " + p.mean());
        System.out.println("stddev is " + p.stddev());
        System.out.println("lo is " + p.confidenceLo());
        System.out.println("hi is " + p.confidenceHi());
        
    }
}