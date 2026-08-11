//https://cses.fi/problemset/task/1646


//   /$$$$$$                       /$$$$$$  /$$ /$$           /$$       /$$      
//  /$__  $$                     /$__  $$|__/|__/          | $$      | $$      
// | $$  \__/  /$$$$$$$  /$$$$$$ | $$  \__/ /$$ /$$ /$$$$$$| $$  /$$$$$$$      
// |  $$$$$$  /$_____/ /$__  $$| $$$$     |$$| $$ /$__  $$| $$ /$__  $$      
//  \____  $$| $$      |$$\ $$|  $_/     |$$| $$| $$$$$$$$| $$| $$  | $$      
//  /$$  \ $$| $$      |$$ | $$|  $$       |$$| $$| $_____/| $$| $$  | $$      
// |  $$$$$$/|  $$$$$$$| $$$$$$/|  $$       |$$| $$|  $$$$$$$| $$|  $$$$$$$      
//  \______/ \_______/\______/|__/       |__/|__/\_______/|__/\___ __/      
                                                                                                                  
                                                                              
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
 
// ================= SOLVE =================
void solve() {
    ll n,q; cin>>n>>q; 
    vcl a(n+1) ; rep(i,1,n+1) cin>>a[i];
    vcl prf(n+1); prf[1]=a[1];
 
    rep(i,2,n+1) prf[i]=prf[i-1]+a[i];
    while(q--){
        ll l,r; cin>>l>>r;
        
        cout<<prf[r]-prf[l-1]<<endl;
    }
}
 
int main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
