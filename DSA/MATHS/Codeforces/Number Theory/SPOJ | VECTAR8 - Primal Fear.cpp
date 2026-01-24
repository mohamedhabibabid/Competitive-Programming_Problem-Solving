//https://www.spoj.com/problems/VECTAR8/
#include "bits/stdc++.h"
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vcl vector<int>
#define str string
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define rep(i,a,b) for(int i=a ; i<b ; i++)

const int M = 1e6;
vector<bool> marked(M+1,false);
vector<int> fairyprimenumbers(M+1,0);

// Check if a number contains digit 0
bool contains0(int n){
    while(n){
        if(n%10==0) return true;
        n/=10;
    }
    return false;
}

// Sieve of Eratosthenes
void sieve() {
    marked[0] = marked[1] = true;
    for (int i = 2; i * i <= M; i++) {
        if(!marked[i]){
            for (int j = i*i; j <= M; j += i)
                marked[j] = true;
        }
    }
}

// Check if all left-truncations are prime
bool alltruncsareprime(int n){
    string s=to_string(n);
    string vari="";
    while(n > 0){
        if(marked[n]) return false;
        s=to_string(n);
        vari=s[0];
        n-=stoi(vari)*pow(10,s.size()-1);
    }
    return true;
}

// Fill the prefix sum array
void fillfairy(){
    for(int i = 2; i <= M; i++){
        if(!marked[i] && !contains0(i) && alltruncsareprime(i))
            fairyprimenumbers[i] = fairyprimenumbers[i-1] + 1;
        else
            fairyprimenumbers[i] = fairyprimenumbers[i-1];
    }
}

// Solve each query
void solve() {
    int n; cin >> n;
    cout << fairyprimenumbers[n] << "\n";
}

int main() {
    fast;
    sieve();
    fillfairy();

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
