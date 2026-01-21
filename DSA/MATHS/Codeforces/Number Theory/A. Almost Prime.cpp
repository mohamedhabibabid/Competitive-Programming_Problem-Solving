// https://codeforces.com/contest/26/problem/A
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


// ========== Sieve  ==========
/*
    number of distinct prime divisors of each number
    if exactly 2 then ++
*/
const int M = 1e6+1;
vector<ll> marked(M+1,0);
vector<ll> cnt_dist_pf(M,0);

// Time: O(M*log(log(M)))
void sieve() {
    for (ll i = 2; i <=M; i++) {
       if(cnt_dist_pf[i]==0)
            for (ll j =i; j <= M; j += i)
                cnt_dist_pf[j]+=1;
    }

    // dbgvec(marked);

}


// ========== SOLVE ==========
void solve() {
    ll n; 
    cin>>n; 
    ll ans=0;
    for(int i=2; i<=n; i++){ 
        if(cnt_dist_pf[i]==2)
            ans++;
    }
    cout<<ans<<endl;


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
