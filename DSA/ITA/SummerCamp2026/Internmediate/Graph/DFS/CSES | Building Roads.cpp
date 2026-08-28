// https://cses.fi/problemset/task/1666/
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
 
vector<bool> visited(100005,false);
void dfs(int node, vector<bool> &visited, vector<vcl> &edge) {
    visited[node] = true;
    for (auto neighbor : edge[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, edge);
        }
    }
}
void solve() {
    int n,m; cin>>n>>m;
    vector<vcl> edge(n+1);
    for(int i=1; i<=m; i++){
        ll a,b; cin>>a>>b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    int count=0;
    vcl ans;
    dfs(1, visited, edge);
    for(int i=1; i<=n; i++){
        if(visited[i]==false){
            ans.pb(i);
            dfs(i, visited, edge);
        }
         
    }
    cout<<ans.size()<<endl;
    for(auto a: ans)
        cout<<a-1<<" "<<a<<endl;
}
 
int main() {
    fast;
    int t = 1;
   //if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
