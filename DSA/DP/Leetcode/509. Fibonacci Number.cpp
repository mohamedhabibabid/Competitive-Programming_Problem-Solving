class Solution {
public:
    int dp[1000]; 

    int fib(int n) {
        dp[0]=0;
        dp[1]=1;
        for(int i=2; i<= n; i++){
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};
