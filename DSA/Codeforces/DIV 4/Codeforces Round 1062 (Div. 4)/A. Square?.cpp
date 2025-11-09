#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

const ll mod = 1000000007LL;
const ll N = 2000007LL;
const ll M = 2000007LL;


void solve() {
    int a, b, c, d; cin>>a>>b>>c>>d;
    if(a==b && c==d && a==c){cout<<"YES"<<endl;}
    else{
        cout<<"NO"<<endl;
    }
}

int main() {
    fast;
    int t = 1;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
