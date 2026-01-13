class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // int dp[1000];
        vector<int> dp(amount + 1, 1e9);
        dp[0]=0;
        for(int i=1; i<= amount ; i++){
            for(auto coin : coins ){
                if(i-coin>=0){
                    dp[i]=min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
