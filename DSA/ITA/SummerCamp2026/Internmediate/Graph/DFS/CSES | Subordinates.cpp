// https://cses.fi/problemset/task/1674/
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
 
void no() {
    cout << "NO" << endl;
}
 
void yes() { 
    cout << "YES" << endl;
}
//---------------dfs------------------//
vector<bool> visited(100005,false);
void dfs(int node, vector<bool> &visited, vector<vcl> &edge) {
    visited[node] = true;
    for (auto neighbor : edge[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, edge);
        }
    }
}
//---------------------------------//
 
 
 
//***************************************** */
 
 
//---------------depth calculation------------------//
// tree DP function that computes the depth (height) of a node in a tree.
vector<int> dp(100005, -1);
int depth(int node,  vector<vcl> &children) {
    if(dp[node] != -1) {
        return dp[node];
    }
    
    dp[node] = 1;
 
    for(auto child : children[node]) {
        dp[node] = max (dp[node], 1 + depth(child, children));
    }
    return dp[node];
}
//---------------------------------//
 
 
 
//***************************************** */
 
 
 
//-------------------------------
vector<int> dpsubnodes(N, -1);
ll dfs(int node, vector<vcl> &children){
    if(dpsubnodes[node] !=-1){
        return dpsubnodes[node];
    }
    dpsubnodes[node]=0;
    for(auto child: children[node]){
        dpsubnodes[node]+=1 + dfs(child, children);
    }
    return dpsubnodes[node];
}
 
//-----------------solve function------------------//
void solve() {
    int n; 
    cin>>n;
    vector<vcl> edge(n+1);
    for(int i=2; i<=n; i++){
        ll boss;
        cin>>boss;
        edge[boss].pb(i);
    }
    for(int i=1; i<=n; i++){
        cout<<dfs(i,edge)<<' ';
    }
}
 
int main() {
    fast;
    int t = 1;
   //if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
