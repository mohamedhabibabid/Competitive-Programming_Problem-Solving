#include <bits/stdc++.h>

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
    int n, q;
    cin >> n >> q;

    vector<int> pref(n + 1, 0);

    // Read array
    for (int i = 1; i <= n; i++) {
        cin >> pref[i];
    }

    // Build prefix sum
    for (int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
    }

    // Queries
    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = pref[r] - pref[l - 1];

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
