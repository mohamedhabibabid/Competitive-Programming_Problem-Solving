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
    int n; int p=0, imp=0; cin>>n;
    vector<int> a(n); 
    for(int i=0; i<n; i++){ 
        cin>>a[i];
        if(a[i]%2==0){
            p++;
        }else{
            imp++;
        }
    }
    if(imp!=n && p!=n){
        sort(a.begin(), a.end());
    }
    for(auto x: a){
        cout<< x<<" ";
    }
    cout<<endl;
}

int main() {
    fast;
    int t = 1;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
