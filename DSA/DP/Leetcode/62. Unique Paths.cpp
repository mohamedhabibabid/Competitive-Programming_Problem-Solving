class Solution {
public: 
    int dp[1000][1000];
    int uniquePaths(int m, int n) {
        fill_n(&dp[0][0], 100000, 1);
        swap(n,m);
        for(int i=1; i< n; i++){
            // dp[i][0]=dp[i-1][0]+grid[i][0];
            for(int j=1; j< m; j++){
                dp[i][j]= dp[i-1][j]+dp[i][j-1] ;
            }
        }
        for(int i=0; i< n; i++){
            // dp[i][0]=dp[i-1][0]+grid[i][0];
            for(int j=0; j< m; j++){
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        return dp[n-1][m-1];
    }
}; 
