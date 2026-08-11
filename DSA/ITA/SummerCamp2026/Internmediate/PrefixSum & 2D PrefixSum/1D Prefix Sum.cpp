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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

    // Read matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> pref[i][j];
        }
    }

    // Prefix rows
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] += pref[i][j - 1];
        }
    }

    // Prefix columns
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] += pref[i - 1][j];
        }
    }

    // Queries
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = pref[x2][y2]
                - pref[x1 - 1][y2]
                - pref[x2][y1 - 1]
                + pref[x1 - 1][y1 - 1];

        cout << ans << '\n';
    }
}

signed main() {
    FastIO();
    FileIO();

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
