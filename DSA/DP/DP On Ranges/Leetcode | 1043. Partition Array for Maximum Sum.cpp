//https://leetcode.com/problems/partition-array-for-maximum-sum/description/
class Solution {
public:
    static const int N=501;
    int dp[N][N];
    bool vis[N][N];

    int func(int l, int r, int maxa, int k, vector<int> &arr){
        int n=arr.size();
        if(r-l+1>k){ // already took K elements => r-l+1>k
            return 0; 
        }

        if(r==n-1){
            return (r-l+1)*maxa;
        }
        

        if(vis[l][r]){
            return dp[l][r];
        }

        vis[l][r]=1;
        // 2 choices
        // choix 1 : mazel yejm yzid el range <=> r-l+1 <=k
        // choix 2 : cut the segment, move to a new one and add the current gain
        int choix_1 = func(l,r+1,max(maxa,arr[r+1]),k,arr);
        int choix_2 = func(r+1,r+1,arr[r+1],k,arr)+maxa*(r-l+1);

        return dp[l][r]=max(choix_1,choix_2);

    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return func(0,0,arr[0],k,arr);
    }

};
