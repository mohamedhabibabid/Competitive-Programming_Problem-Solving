#include <bits/stdc++.h>
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


void solve(){
   ll n; 
   cin>>n;
   if(n%2==0){
        cout<<gcd(n,n/2)<<endl;
   }
   else cout<<gcd(n-1,(n-1)/2)<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
