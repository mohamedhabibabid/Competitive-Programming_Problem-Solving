//https://leetcode.com/problems/partition-array-for-maximum-sum/description/
class Solution {
public:
    static const int N=501;
    int dp[N][N];
    bool vis[N][N];

    // taking a segment from l to r
    // maxa = max value inside this segment
    int func(int l, int r, int maxa, int k, vector<int> &arr){
        int n = arr.size();

        // segment bigger than k → invalid case
        if(r - l + 1 > k){
            return 0; 
        }

        // base case : tzid el contribution of last segment 
        if(r == n-1){
            return (r - l + 1) * maxa;
        }
        
        if(vis[l][r]){ 
            return dp[l][r];
        }

        vis[l][r] = 1;

        // option 1: continue expanding the current segment <=> u pick the next right element
        // (We r sure that this is a valid step if size still <= k, cuz handled above)
        int choix_1 = func(l, r+1, max(maxa, arr[r+1]), k, arr);

        // option 2: stop here, take this segment
        // then start a new one from r+1 <=> l & r point to the same element 
        int choix_2 = maxa * (r - l + 1)
                    + func(r+1, r+1, arr[r+1], k, arr);

        return dp[l][r] = max(choix_1, choix_2);
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return func(0, 0, arr[0], k, arr);
    }
};
