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






//##### SOLVE ##### //
void solve() {
    ll n, k, mxtmp;
    cin>>n>>k>>mxtmp;
    vector<int> a(n);
    for(auto &x: a) cin>>x;
    ll ans=0, curr=0;
    for(int i=0; i< n; i++){
        //cout<<curr<<' ';
        if(a[i]<=mxtmp){
            curr++;
        }else{
                if(curr>=k){
                    ll m=curr-k+1;
                    ans+=m*(m+1)/2;
                    //cout<<'*'<<ans<<endl;
                }
            curr=0;
        }
    }
    if(curr!=0){
        if(curr>=k){
            ll m=curr-k+1;
            ans+=m*(m+1)/2;
        }
    }
    cout<<ans<<endl;
}
//----- END SOLVE ##### //


int main() {
    fast;
    int t = 1;
    init_combinatorics();   
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
