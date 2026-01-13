vector<long long> dp(1001,-1); 
class Solution {
public:
//  recursive
    int dfs(vector<int>& nums, int target, vector<long long> &dp ) {
        // static vector<long long> dp(1001, -1);
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (dp[target] != -1) return dp[target];

            dp[target] = 0;
            for (int num : nums) {
                dp[target] += dfs(nums, target-num,dp);
            }
        return dp[target];
        }

        int combinationSum4(vector<int>& nums, int target) {
            vector<long long> dp(1001, -1);
            
            return dfs(nums, target, dp);;
        }
    
};

//--- iterative
// int combinationSum4(vector<int>& nums, int target) {
//         unsigned long long dp[1001]; 
//         dp[0]=1; 
//         for(int i=1; i<= target ; i++){
//             for(auto num : nums ) {
//                 if(i-num>=0)
//                     dp[i]+=dp[i-num]; 
//             }
//         }
//         return dp[target]; 
//     }
