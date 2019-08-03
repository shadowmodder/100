import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

public class Outcast {
    
    private final WordNet mWordnet;
    
    public Outcast(WordNet wordnet) {
        mWordnet = wordnet;
    }
    
    public String outcast(String[] nouns) {
        checknull(nouns);
        
        int maxDis = Integer.MIN_VALUE;
        String ret = "";
        
        for (int i = 0; i < nouns.length; i++) {
            int d = 0;
            for (String t: nouns) {
                d += mWordnet.distance(nouns[i], t);
            }
            if (d > maxDis) {
                maxDis = d;
                ret = nouns[i];
            }
        }
        
        return ret;
    }
    
    
    public static void main(String[] args) {
        WordNet wordnet = new WordNet(args[0], args[1]);
        Outcast outcast = new Outcast(wordnet);
        
        for (int t = 2; t < args.length; t++) {
            In in = new In(args[t]);
            String[] nouns = in.readAllStrings();
            StdOut.println(args[t] + ": " + outcast.outcast(nouns));
        }

    }
    
    private void checknull(Object obj) {
       if (obj == null) throw new java.lang.NullPointerException(); 
    }
}