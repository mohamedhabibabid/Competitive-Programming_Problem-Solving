//https://codeforces.com/problemset/problem/1036/C
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

// ================= GCD =================
template<class T>
T gcd(T a, T b) {
    T tmp = 0;
    while (b){
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

// ================= LCM & INV =================
ll lcm(ll a, ll b) {return (a * b)/gcd(a , b);}
ll inv(ll N) {if(N==1) return 1; return (MOD-((MOD / N)*inv(MOD % N))% MOD)%MOD;}

// ================= DEBUG UTILITIES =================
#define dbg(x) cerr << #x << " = " << (x) << endl
#define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl

template<typename T>
void dbgvec(const vector<T>& v) {
    cerr << "[ ";
    for (auto &x : v) cerr << x << " ";
    cerr << "]" << endl;
}

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

bool distin(int n) {
    string year = to_string(n);
    set<char> digits(year.begin(), year.end());
    return digits.size() == year.size();
}

// ================= COMBINATORICS =================
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

// ================= SIEVE =================
const int M = 1e6+1;
vector<bool> marked(M+1,0);
vector<ll> primes;

void sieve() {
    marked[0]=marked[1]=true;
    for (ll i = 2; i <= M; i++) {
        if(!marked[i]){
            primes.pb(i);
            if(i*i <= M)
                for (ll j = i*i; j <= M; j += i)
                    marked[j]=true;
        }
    }
}

// ================= SOLVE =================
ll digits[20];
ll n;
ll dp[20][5][2];     // dp[pos][nonzero_count][tight]
bool visited[20][5][2];

ll solveDp(ll pos, ll nz, ll tight) {
    if (nz > 3) return 0;
    if (pos == n) return 1;
    if (visited[pos][nz][tight]) return dp[pos][nz][tight];

    ll limit = tight ? digits[pos] : 9;
    ll total = 0;

    for (ll d = 0; d <= limit; d++) {
        ll new_nz = nz + (d != 0 ? 1 : 0);
        if (new_nz > 3) continue;
        ll new_tight = (tight && (d == limit)) ? 1 : 0;
        total += solveDp(pos + 1, new_nz, new_tight);
    }

    visited[pos][nz][tight] = true;
    dp[pos][nz][tight] = total;
    return total;
}

ll countClassy(ll x){
    if (x <= 0LL) return 0LL; // no positive classy numbers <= 0

    string s = to_string(x);
    n = s.size();
    for (int i=0;i<n;i++) digits[i]=s[i]-'0';

    memset(visited, false, sizeof(visited));

    ll total = solveDp(0LL, 0LL, 1LL); // start tight = true
    return total - 1;    
}
void solve(){
    ll a, b;
    cin >> a >> b;
    cout << (countClassy(b) - countClassy(a - 1)) << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
