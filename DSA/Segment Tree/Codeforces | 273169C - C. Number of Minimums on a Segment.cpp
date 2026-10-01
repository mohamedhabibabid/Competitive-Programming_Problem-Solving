//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
//  ███████╗ ██████╗ ██████╗ ███████╗██╗██╗███████╗██╗     ██████╗ 
//  ██╔════╝██╔════╝██╔═══██╗██╔════╝██║██║██╔════╝██║     ██╔══██╗
//  ███████╗██║     ██║   ██║█████╗  ██║██║█████╗  ██║     ██║  ██║
//  ╚════██║██║     ██║   ██║██╔══╝  ██║██║██╔══╝  ██║     ██║  ██║
//  ███████║╚██████╗╚██████╔╝██║     ██║██║███████╗███████╗██████╔╝
//  ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝╚══════╝╚══════╝╚═════╝ 

#include "bits/stdc++.h"
// #include <bit>
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

//===== FenwickTree / BIT=================== 
ll k ; 
struct BIT{ // 1-indexed
int n;
vector<long long> b;

BIT(int _n) {
    n = _n;
    b.assign(n + 1, 0);
}

void add(int idx, int v) { // arr[idx] += v
    while (idx <= n) {
        b[idx] += v;
        idx += idx & -idx;
    }
}

long long get(int idx) { // from 1 to idx
    long long ans = 0;
    while (idx > 0) {
        ans += b[idx];
        idx -= idx & -idx;
    }
    return ans;
}

long long get(int l, int r) { // from l ro r
    return get(r) - get(l - 1);
}

void set(int idx, int v) { // arr[idx] = v
    int old = get(idx, idx);
    cout << old << '\n';
    add(idx, -old + v);
}
};
//==========================================


//=========Sparsetable=====================
struct SparseTable {
    vector<vector<int>> data;
    vector<int> logs;
 
    int merge(int &lf, int &ri) {
        return gcd(lf,ri);// change the operation, must be "op(x, x) = x"
    }
 
    SparseTable(vector<int> &arr) {
        int n = arr.size();
 
        logs.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i)
            logs[i] = logs[i / 2] + 1;
 
        data.assign(logs[n] + 1, vector<int>(n));
        data[0] = arr;
 
        for (int i = 1; i <= logs[n]; ++i) {
            int len = 1 << i;
            for (int j = 0; j + len <= n; ++j)
                data[i][j] = merge(data[i - 1][j], data[i - 1][j + (len >> 1)]);
        }
    }
 
    int get(int l, int r) {
        int len = r - l + 1;
        int level = logs[len];
        return merge(data[level][l], data[level][r - (1 << level) + 1]);
    }
};


// ================= SOLVE =================
struct Node {
    long long mn;
    long long cnt; 
    Node () : mn(2e9), cnt(0){}
    Node (int x) : mn(x), cnt(1){}
};
 
struct SegTree {
    int tree_size;
    vector<Node> SegData;
    SegTree(int n) {
        tree_size = 1;
        while (tree_size < n) tree_size <<= 1;
        SegData.assign(2 * tree_size, Node());
    }
 
    Node merge(const Node &lf, const Node &ri) {
        Node ans = Node();
        if(lf.mn<ri.mn){
            ans=lf;
        }else if(lf.mn>ri.mn){
            ans=ri;
        }else{
            ans.mn=lf.mn;
            ans.cnt=lf.cnt + ri.cnt;
        }
        return ans;
    }
 
    void build(const vector<int> &arr, int node, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < arr.size())
                SegData[node] = Node(arr[lx]);
            return;
        }
        int mid = (lx + rx) >> 1;
        build(arr, 2 * node + 1, lx, mid);
        build(arr, 2 * node + 2, mid, rx);
        SegData[node] = merge(SegData[2 * node + 1], SegData[2 * node + 2]);
    }
    void build(const vector<int> &arr) {
        build(arr, 0, 0, tree_size);
    }
 
    void set(int idx, int val, int node, int lx, int rx) {
        if(rx - lx == 1) {
            SegData[node] = Node(val);
            return;
        }
 
        int mid = (lx + rx) >> 1;
        if(idx < mid)
            set(idx, val, 2 * node + 1, lx, mid);
        else
            set(idx, val, 2 * node + 2, mid, rx);
        SegData[node] = merge(SegData[2 * node + 1], SegData[2 * node + 2]);
    }
    void set(int idx, int val) {
        set(idx, val, 0, 0, tree_size);
    }
 
    Node get_range(int l, int r, int node, int lx, int rx) {
        if(lx >= r || rx <= l)
            return Node();
        if(lx >= l && rx <= r)
            return SegData[node];
 
        int mid = (lx + rx) >> 1;
        Node lf = get_range(l, r, 2 * node + 1, lx, mid);
        Node ri = get_range(l, r, 2 * node + 2, mid, rx);
        return merge(lf, ri);
    }
    void get_range(int l, int r) { // R not included
        cout<<get_range(l, r, 0, 0, tree_size).mn<<' '<<get_range(l, r, 0, 0, tree_size).cnt<<endl;
    }
};
void solve() {
    ll n, m; 
    cin>>n>>m; 
    vector<int> a(n); 
    rep(i,0,n) cin>>a[i];
    SegTree s(n);
    s.build(a);
    while(m--){
        ll x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            s.set(y,z);
        }else{
            s.get_range(y,z);
        }
    }

}

int main() {
    fast;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
