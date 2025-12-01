#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define f(i,x,n) for(int i = x; i < n; i++)
using pll = pair<ll, ll>;
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const ll dcinq=1e5+5;
const double pii=3.14159265358979323846;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }//
// Created by abdolski on 11/30/25.
//


pair<double,double>  rotate(pair<double,double> p, double theta) {
    double pi =pii;
    double rad = theta*pi/180;
    return mp(
        p.F * cos(rad) - p.S * sin(rad),
        p.F * sin(rad) + p.S * cos(rad)
        );
}

void solve() {
    double xc,yc,xi,yi,thetha;cin>>xi>>yi>>xc>>yc>>thetha;

    xi = xi-xc;yi = yi-yc;
    pair<double,double> ans=rotate(mp(xi,yi),thetha);
    ans.F+=xc;ans.S+=yc;
    //cout<<setprecision(6)<<ans.F<<" "<<ans.S<<endl;
    printf("%.6lf %.6lf\n", ans.first, ans.second);

}



int main() {
    FAST
    //seive();
    // preproc();



    ll t=1;

    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
