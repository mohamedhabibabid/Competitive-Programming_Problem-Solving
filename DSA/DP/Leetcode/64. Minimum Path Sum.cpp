class Solution {
public:
    int dp[1000][1000];
    int minPathSum(vector<vector<int>>& grid) {
        dp[0][0]=grid[0][0]; // grid n*m 
        int n =grid.size(); // rows
        int m=grid[0].size(); //cols
        dp[0][0]=grid[0][0];
        for(int i=1; i< m; i++){
            cout<<i<<endl;
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int j=1; j< n; j++){
            dp[j][0]=dp[j-1][0]+grid[j][0];
        }
        for(int i=1; i< n; i++){
            // dp[i][0]=dp[i-1][0]+grid[i][0];
            for(int j=1; j< m; j++){
                dp[i][j]=grid[i][j]+ min(dp[i-1][j],dp[i][j-1]);
            }
        }
        // for(int i=0; i< n; i++){
        //     // dp[i][0]=dp[i-1][0]+grid[i][0];
        //     for(int j=0; j< m; j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<dp[0][2];
        return dp[n-1][m-1];
    }
};
