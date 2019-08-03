import edu.princeton.cs.algs4.FlowNetwork;
import edu.princeton.cs.algs4.FlowEdge;
import edu.princeton.cs.algs4.FordFulkerson;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

public class BaseballElimination {
    private final int totalTeams;
    private final TeamInfo[] teams;
    // private final Map<String, Integer> teamMap;
    private FlowNetwork net;
    private int maxWinTeamId;
    // private Map<Integer, ArrayList<String>> layer1Map;
    
    private class TeamInfo {
       public String name;
       public int  wins;
       public int  losses;
       public int  remainings;
       public int[] adj;
       public TeamInfo(int num) {
           name     = "";
           wins     = 0;
           losses   = 0;
           remainings = 0;
           adj  = new int[num];
       }
    }
    
    public BaseballElimination(String fileName) {
        if (fileName == null)
            throw new IllegalArgumentException("file name is empty");
        In in = new In(fileName);
        totalTeams = in.readInt();
        
        teams = new TeamInfo[totalTeams];
        // teamMap = new LinkedHashMap<String, Integer>();
        
        int i = 0;
        int maxWins = 0;
        while (!in.isEmpty() && i < totalTeams) {
            TeamInfo team = new TeamInfo(totalTeams);
            team.name =       in.readString();
            // teamMap.put(team.name, Integer.valueOf(i));
            team.wins =       in.readInt();
            team.losses =     in.readInt();
            team.remainings = in.readInt();
            for (int vs = 0; vs < totalTeams; vs++) {
                team.adj[vs] = in.readInt();
            }
            
            if (team.wins > maxWins) {
                maxWins = team.wins;
                maxWinTeamId = i;
            }
                        
            teams[i] = team;
            i++;
        }  
    }
    
    public int numberOfTeams() {
        return totalTeams;
    }
    
    public Iterable<String> teams() {
        ArrayList<String> teamList = new ArrayList<String>();
        for (TeamInfo t: teams) teamList.add(t.name);
        return teamList;
    }
    
    public int wins(String team) {
        checkArgument(team, "Team name is empty");
        
        int id = getTeamId(team);
        return teams[id].wins;
    }
    
    public int losses(String team) {
        checkArgument(team, "Team name is empty");
        
        int id = getTeamId(team);
        return teams[id].losses;
    }
    
    public int remaining(String team) {
        checkArgument(team, "Team name is empty");
        
        int id = getTeamId(team);
        return teams[id].remainings;
    }
    
    public int against(String team1, String team2) {
        checkArgument(team1, "Team1 name is empty");
        checkArgument(team2, "Team2 name is empty");
        
        int id1 = getTeamId(team1);
        int id2 = getTeamId(team2);
        return teams[id1].adj[id2];
    }
    
    public boolean isEliminated(String team) {
        checkArgument(team, "Team name is empty");
        
        if (isNonTrivialEliminated(getTeamId(team))) return true;
        
        buildFlowNetwork(getTeamId(team));
        int numOfLayer1 = (totalTeams - 1) * (totalTeams - 2) / 2;
        
        FordFulkerson ff = new FordFulkerson(
                                           net,
                                           0,
                                           numOfLayer1 + 1 + getTeamId(team));
        double startCapacity = 0.0;
        for (FlowEdge e: net.adj(0)) {
            /* print those edges from source node */
            /*
             StdOut.printf("f:%f, c:%f, v:%f\n",
                          e.flow(),
                          e.capacity(),
                          ff.value());
            */
             startCapacity += e.capacity();
        }
        double endCapacity = 0.0;
        for (FlowEdge e: net.adj(numOfLayer1 + 1 + getTeamId(team))) {
            /* print those edges to final target */
            /*
            StdOut.printf("end:f:%f, c:%f, v:%f\n",
                          e.flow(),
                          e.capacity(),
                          ff.value()); */
            endCapacity += e.capacity();
        }
        if (Double.compare(ff.value(), startCapacity) == 0) return false; 
        return true; 
    }
    
    public Iterable<String> certificateOfElimination(String team) {
        checkArgument(team, "Team name is empty");
        if (!isEliminated(team)) return null;
        
        Set<String> ans = new HashSet<String>();
        
        if (isNonTrivialEliminated(getTeamId(team))) {
           ans.add(teams[maxWinTeamId].name);
           return ans;
        }
                       
        int numOfLayer1 = (totalTeams - 1) * (totalTeams - 2) / 2;
        buildFlowNetwork(getTeamId(team));
        FordFulkerson ff = new FordFulkerson(net, 0,
                                             numOfLayer1 + 1 + getTeamId(team));
        /* 
        for (int i = 1; i <= numOfLayer1; i++) {
            if (ff.inCut(i)) {
                ans.add(layer1Map.get(i).get(0));
                ans.add(layer1Map.get(i).get(1));
            }
            
        } */
        
        for (int i = 0; i < totalTeams; i++) {
            if (i == getTeamId(team)) continue;
            int nodeId = numOfLayer1 + 1 + i;
            if (ff.inCut(nodeId)) {
                ans.add(teams[i].name);
            }
        }

        return ans;
    }
    
    private void checkArgument(Object obj, String msg) {
        if (obj == null)
            throw new IllegalArgumentException(msg);
        if (getTeamId((String) obj) == -1)
            throw new IllegalArgumentException(msg);
    }
    
    private int getTeamId(String team) {
        for (int i = 0; i < totalTeams; i++) {
            if (team.equals(teams[i].name))
                return i;
        }
        return -1;
    }
    
    private boolean isNonTrivialEliminated(int id) {
        if (id == maxWinTeamId) return false;
        return ((teams[id].wins + teams[id].remainings) <
               teams[maxWinTeamId].wins);
    }
    
    private void buildFlowNetwork(int id) {
        int numOfLayer1 = (totalTeams - 1) * (totalTeams - 2) / 2;
        int numOfLayer2 = (totalTeams - 1);
        int totalNodes = 1 + numOfLayer1 + numOfLayer2  + 1;
        net = new FlowNetwork(totalNodes);
        // layer1Map = new HashMap<Integer, ArrayList<String>>();
           
        int nodeInLayer1 = 1;
        for (int first = 0; first < teams.length - 1; first++) {
            if (first == id) continue;
            for (int second = first + 1; second < teams.length; second++) {
                if (second == id) continue;
                int weight = teams[second].adj[first];
                
                net.addEdge(new FlowEdge(0, nodeInLayer1, weight));
                net.addEdge(new FlowEdge(nodeInLayer1,
                                         numOfLayer1 + 1 + first,
                                         Integer.MAX_VALUE)); 
                net.addEdge(new FlowEdge(nodeInLayer1,
                                         numOfLayer1 + 1 + second,
                                         Integer.MAX_VALUE));
                /* 
                ArrayList<String> points = new ArrayList<String>();
                points.add(teams[first].name);
                points.add(teams[second].name);
                layer1Map.put(nodeInLayer1, points);
                */
                nodeInLayer1++;
            }
        }

       for (int i = 0; i < teams.length; i++) {
           if (i == id) continue;
           int weight = teams[id].wins + teams[id].remainings
                        - teams[i].wins;
            if (weight < 0) weight = 0;
            net.addEdge(new FlowEdge(numOfLayer1 + 1 + i,
                                     numOfLayer1 + 1 + id,
                                     weight));
       }
       
    }
    
    public static void main(String[] args) {
    BaseballElimination division = new BaseballElimination(args[0]);
    for (String team : division.teams()) {
        StdOut.println(team);
    }
    for (String team : division.teams()) {
        if (division.isEliminated(team)) {
            StdOut.print(team + " is eliminated by the subset R = { ");
            for (String t : division.certificateOfElimination(team)) {
                StdOut.print(t + " ");
            }
            StdOut.println("}");
        }
        else {
            StdOut.println(team + " is not eliminated");
        }
    }
}
}