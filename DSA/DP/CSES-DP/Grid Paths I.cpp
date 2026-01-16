#include "bits/stdc++.h"
#include <bit>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vcl vector<ll>
#define str string
 
#define rep(i,a,b) for(int i=a ; i<b ; i++)
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}
 
bool distin(int n) {
    string year = to_string(n);
    set<char> digits(year.begin(), year.end());
    return digits.size() == year.size();  // True if all digits are distinct
}



// Combinatorial functions
const long long MOD = 1'000'000'007;
const int MAXN = 1'000'000;   // change if needed

long long fact[MAXN+1], invfact[MAXN+1];

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void init_combinatorics() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;

    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);  // Fermat inverse
    for (int i = MAXN - 1; i >= 0; i--)
        invfact[i] = invfact[i+1] * (i+1) % MOD;
}

long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

long long nPr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n-r] % MOD;
}
//----------------  



void no() {
    cout << "NO" << endl;
}

void yes() { 
    cout << "YES" << endl;
}


// contigious subsequences /
// t’s subarrays / contiguous subsequences

// There are n(n+1)/2* such sequences.



//--------- lambda comparator -----
struct cmp {
    bool operator()(const pair<ll,ll>& a, const  pair<ll,ll>& b) const {
        if(a.fi == b.fi)
            return a.se < b.se;
        return a.fi > b.fi; 
    }
};
//---------
//Longest Common Subsequence (LCS) -----
// int dp[1001][1001]={{0}};
//     class Solution {
//     public:
//         int lcs(string s1, string s2, int x, int y){
//             for(int i=0; i<=x; i++){
//                 for(int j=0; j<=y; j++){
//                     if(i==0 || j==0){
//                         dp[i][j]=0;
//                     }else{
//                         if(s1[i-1]==s2[j-1]){
//                             dp[i][j]=1+dp[i-1][j-1];
//                         }else{
//                             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                         }
//                     }
//                 }
//             }
//             return dp[x][y];
//         }
//         int longestCommonSubsequence(string text1, string text2) {
//             int x=text1.size(), y=text2.size();
//             return lcs(text1, text2,x,y);
//         }
//     };
//---------
void add_self(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}


//##### SOLVE ##### //
ll dp[1001][1001]   ; // dp[x]= minimum number of steps to get x 
void solve() {
    ll n; cin>>n;
    char grid[n][n];
    for(int i=0; i< n; i++){
        for(int j=0; j< n; j++){
                cin>>grid[i][j];
        }
    }
    char trap='*';
    ll ans=0; 
    dp[0][0]=1;
    if(grid[0][0]==trap){
        cout<<0<<endl;
        return;
    }
    // absolute sum of paths 
        for(int row=0; row< n; row++){
            for(int col=0; col< n; col++){
                if(col+1<n && grid[row][col+1]!=trap){
                    add_self( dp[row][col+1], dp[row][col]);
                }
                if(row+1<n && grid[row+1][col]!=trap) 
                    add_self( dp[row+1][col], dp[row][col]);
            }
        }
    cout<<dp[n-1][n-1]<<endl;   
}
//----- END SOLVE ##### //


int main() {
    fast;
    int t = 1;
    // if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
