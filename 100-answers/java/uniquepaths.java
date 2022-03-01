public class uniquepaths {

    public int simpleuniquePaths(int m, int n) {
        int[] dp = new int[n];
        for(int i =0; i< n; i++){
            dp[i] = 1;
        }
        for(int i=1; i < m;i++) {
            for(int j=1;j<n;j++) {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }


    public int uniquePathsWithObstacles(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0) return 0;
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp= new int[m][n];
        for(int k=0; k<n;k++){
            if(grid[0][k] == 0) dp[0][k] = 1;
            else break;
        }
        for(int k=0; k<m;k++){
            if(grid[k][0] == 0) dp[k][0] = 1;
            else break;
        }
        
        for(int i=1; i< m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }

    public static void main(String[] args) {
        uniquepaths up = new uniquepaths();
        int[][] arr = { { 0,0,0 },{0,1,0}, { 0,0,0} };
        System.out.println("is simpleuniquePaths ?: " + (up.uniquePathsWithObstacles(arr)));
      }

}