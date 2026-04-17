//   /$$$$$$                       /$$$$$$  /$$ /$$           /$$       /$$      
//  /$__  $$                     /$__  $$|__/|__/          | $$      | $$      
// | $$  \__/  /$$$$$$$  /$$$$$$ | $$  \__/ /$$ /$$ /$$$$$$| $$  /$$$$$$$      
// |  $$$$$$  /$_____/ /$__  $$| $$$$     |$$| $$ /$__  $$| $$ /$__  $$      
//  \____  $$| $$      |$$\ $$|  $_/     |$$| $$| $$$$$$$$| $$| $$  | $$      
//  /$$  \ $$| $$      |$$ | $$|  $$       |$$| $$| $_____/| $$| $$  | $$      
// |  $$$$$$/|  $$$$$$$| $$$$$$/|  $$       |$$| $$|  $$$$$$$| $$|  $$$$$$$      
//  \______/ \_______/\______/|__/       |__/|__/\_______/|__/\___ __/      
                                                                                                                  
//https://codeforces.com/contest/1915/problem/F                                                                           
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
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define rep(i,a,b) for(int i=a ; i<b ; i++)

const ll N=5005;
const ll INF=1e18;
const ll MIN=-1e18;
const ll mod=1e9+7;
const ll MOD=1e9+7;
const ll MAX=1000001;
const double EPS=1e-8;

// ================= ordered_set =================
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
// ================= SOLVE =================
ll n; 
ordered_set st;
void solve() {
    cin>>n;
   vector<pair<ll,ll>> a(n);
   for(int i=0; i<n; i++){
     cin>>a[i].fi>>a[i].se;
   }
   
   sort(all(a));
   
   st.clear();
   ll count=0;
   
   for(auto range : a){
      ll l=range.fi, r=range.se;
      count+=st.size() - st.order_of_key(r);
      
      st.insert(r);
   }
    cout<<count<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
