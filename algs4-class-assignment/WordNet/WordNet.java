import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.DirectedCycle;
import edu.princeton.cs.algs4.In;

import java.util.ArrayList;
import java.util.HashMap;

public class WordNet {
    
    private final HashMap<String, ArrayList<Integer>> synmap =
                                     new HashMap<String, ArrayList<Integer>>();
    private final HashMap<Integer, String> idmap =
                                     new HashMap<Integer, String>();
    private final SAP mSap;
    
    public WordNet(String synsets, String hypernyms) {
        checknull(synsets);
        checknull(hypernyms);
        
        In in = new In(synsets);
        int id = 0;
        int totalVertex = 0;
        while (!in.isEmpty()) {
            String line = in.readLine();
            String[] fields = line.split(",");
            for (String word: fields[1].split(" ")) {
                ArrayList<Integer> list = synmap.get(word);
                if (list == null) {
                    list = new ArrayList<Integer>();
                }
                list.add(Integer.valueOf(fields[0]));
                synmap.put(word, list);
            } 
            idmap.put(id++, fields[1]);
            totalVertex++;
        }

        Digraph g = new Digraph(totalVertex);
        In hyperIn = new In(hypernyms);
        while (!hyperIn.isEmpty()) {
            String[] vertexes = (hyperIn.readLine()).split(",");
            int v = Integer.parseInt(vertexes[0]);     
            for (int i = 1; i < vertexes.length; i++) {
                int w = Integer.parseInt(vertexes[i]);
                g.addEdge(v, w);
            }
        }
        
        int rootCnt = 0;
        for (int i = 0; i < g.V(); i++) {
            if (g.outdegree(i) == 0) rootCnt++;
        }
        if (rootCnt > 1) throw new IllegalArgumentException();
        
        DirectedCycle dag = new DirectedCycle(g);
        if (dag.hasCycle())  throw new IllegalArgumentException();
  
        mSap = new SAP(g);
    }
    
    public Iterable<String> nouns() {
        return synmap.keySet();
    }
    
    
    public boolean isNoun(String word) {
        checknull(word);
        return synmap.containsKey(word);
    }
    
    public int distance(String nounA, String nounB) {
        checknouns(nounA);
        checknouns(nounB);
        return mSap.length(synmap.get(nounA), synmap.get(nounB));
    }
    
    public String sap(String nounA, String nounB) {
        checknouns(nounA);
        checknouns(nounB);
        return idmap.get(mSap.ancestor(synmap.get(nounA), synmap.get(nounB)));
    }
    
    private void checknouns(String nounA) {
        if (!isNoun(nounA)) {
            throw new IllegalArgumentException(nounA + " is not a noun.");
        }
    }
    
    private void checknull(Object obj) {
        if (obj == null) {
            throw new IllegalArgumentException();
        }
    }


}