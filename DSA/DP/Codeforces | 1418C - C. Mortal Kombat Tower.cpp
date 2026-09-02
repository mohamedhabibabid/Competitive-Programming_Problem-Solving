// https://codeforces.com/problemset/problem/1418/C
// ================= SOLVE =================
vector<vector<ll>> dp;
vcl a; 
int n; 

ll solveDp(int i, int j){
    if(i>=n){
        return 0; 
    }

    if(dp[i][j]!=-1)
        return dp[i][j]; 
    
    // choice 1 : 
    ll choice1=(j==0? a[i] : 0) + solveDp(i+1, 1-j);

    ll choice2=INF ;

    if(i+1<n){
        choice2=(j==0? a[i]+a[i+1] : 0) + solveDp(i+2, 1-j);
    }

    return dp[i][j]=min(choice1,choice2);
}

void solve() {
     cin>>n;
    a.resize(n); 

    rep(i,0,n) cin>>a[i];
    dp.assign(n, vector<ll>(2, -1));
   
    cout<< solveDp(0,0)<<endl;
}

int main() {
    // fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
