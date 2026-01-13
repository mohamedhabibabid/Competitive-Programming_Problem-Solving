class Solution {
public:
    long long change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if(i-coin>=0)
                    dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};
