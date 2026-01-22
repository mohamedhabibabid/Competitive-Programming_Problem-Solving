//https://codeforces.com/contest/776/problem/B
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

const ll mod = 1e9+7, N = 2e6+7, /*M = 2e6+7*/ INF = INT_MAX/10;

// ================= DEBUG UTILITIES =================
#define dbg(x) cerr << #x << " = " << (x) << endl
#define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl

template<typename T>
void dbgvec(const vector<T>& v) {
    cerr << "[ ";
    for (auto &x : v) cerr << x << " ";
    cerr << "]" << endl;
}
// ===================================================

ll powe(ll x, ll y){
    x = x%mod, y=y%(mod-1);
    ll ans = 1;
    while(y>0){
        if (y&1) ans = (1ll * x * ans)%mod;
        y>>=1;
        x = (1ll * x * x)%mod;
    }
    return ans;
}

template<typename T>
void print(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

// -----------------

bool distin(int n) {
    string year = to_string(n);
    set<char> digits(year.begin(), year.end());
    return digits.size() == year.size();
}

// Combinatorics
const long long MOD = 1'000'000'007;
const int MAXN = 1'000'000;

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

    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
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

// comparator
struct cmp {
    bool operator()(const pair<ll,ll>& a, const pair<ll,ll>& b) const {
        if(a.fi == b.fi) return a.se < b.se;
        return a.fi > b.fi;
    }
};

void add_selfmod(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}
// ========== Sieve  ==========
/*
    number of distinct prime divisors of each number
    if exactly 2 then ++
*/
const int M = 1e6+1;
vector<bool> marked(M+1,0);
vector<ll> cnt_dist_pf(M,0);

// Time: O(M*log(log(M)))
void sieve() {
    marked[0]=marked[1]=true;
    for (ll i = 2; i <=M; i++) {
        if(marked[i]==0)
            for (ll j =2*i; j <= M; j += i)
                marked[j]=true;
    }

    // dbgvec(marked);

}


// ========== SOLVE ==========
void solve() {
    ll n; 
    cin>>n; 
    vcl a(n);
    if(n==1) {
        cout<<1<<endl<<1<<endl;
        return;
    }else if(n==2){
        cout<<1<<endl<<1<<' '<<1<<endl;
        return;
    }
    // rep(i,0,n) cin>>a[i];
    // vcl prices=a;
    // rep(i,0,n) prices[i]++;
    cout<<2<<endl;
    for(int i=2; i<=n+1; i++){
        dbg(marked[i]);
        if(!marked[i]){
            cout<<1<<' ';
        }else{
            cout<<2<<' ';
        }
    }
    cout<<endl;


}
// ===========================

int main() {
    fast;
    int t = 1;
    sieve();
    // is_prime(N, true);
    // cin >> t;
    while (t--) solve();
    return 0;
}
