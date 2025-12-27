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
//#define mp make_pair
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
 
void no() {
    cout << "NO" << endl;
}
 
void yes() { 
    cout << "YES" << endl;
}

ll dp[N];
int k;
// --- Iterative DP ---- 
int minimum_cost(int n, vcl &h) {
    dp[0]=0;
    for(int i=1; i<n; i++){
        dp[i]=LLONG_MAX;
        for(int j=max(0,i-k); j<i; j++) {
            dp[i]=min(dp[i],dp[j]+abs(h[i]-h[j]));
        }
    }
    return dp[n-1];
}

// --- Recursive DP --- 
// int minimum_cost(int n, vcl &h) {
//     if(n==0){
//         return 0;
//     }
//     if(dp[n]!=-1)
//         return dp[n];

//     dp[n]=LLONG_MAX;
//     for(int j=max(0,n-k); j<n; j++)
//         dp[n]=min(dp[n],minimum_cost(j,h) + abs(h[n]-h[j]));

//     return dp[n];
// }

void solve() {
    memset(dp,-1,sizeof(dp));
    int n; cin>>n;
    cin>>k;
    vcl h(n);
    for(int i=0; i< n; i++) 
        cin>>h[i];
    cout<<minimum_cost(n-1,h)<<endl;
}

int main() {
    fast;
    int t = 1;
    //if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
