// https://cses.fi/problemset/task/1652
#include <iostream>
#include <vector>
using namespace std;
 
#define all(v) v.begin(),v.end()
#define int long long
 
void FileIO() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}
 
void FastIO() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}
 
 
// void PrintMatrix(vector <vector<int>> &matrix) {
//     for (int i = 1 ; i <= n ; i++) {
//         for (int j = 1 ; j <= m; j++) {
//             cout << matrix[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }
 
 
void solve() {
    int n , q;
    cin >> n >> q;
    vector <vector<int>> matrix(n + 1 , vector <int> (n + 1));
 
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n; j++) {
            char c; cin >> c;
            if(c == '*') matrix[i][j] = 1;
            else matrix[i][j] = 0;
        }
    }
 
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            matrix[i][j] += matrix[i - 1][j];
        }
    }
 
    while (q--) {
        int x1 , y1 , x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
 
        int ans = matrix[x2][y2] - matrix[x1 - 1][y2] - matrix[x2][y1 - 1];
        ans += matrix[x1 - 1][y1 - 1];
 
        cout << ans << '\n';
    }
}
 
signed main() {
    FastIO();
    FileIO();
 
    int t = 1;
 //   cin >> t;
    while (t--) {
        solve();
    }
}
}
