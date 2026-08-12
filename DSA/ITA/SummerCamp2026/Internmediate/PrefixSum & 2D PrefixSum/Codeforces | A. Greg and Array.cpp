// https://codeforces.com/contest/295/problem/A                                                                                                                  
#include "bits/stdc++.h"
#include <bit>
using namespace std;

#define all(v) v.begin(), v.end()
#define int long long


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> l(m + 1);
    vector<int> r(m + 1);
    vector<int> d(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> d[i];
    }

    // Difference array for operations
    vector<int> cnt(m + 2, 0);

    while (k--) {
        int x, y;
        cin >> x >> y;

        cnt[x]++;
        cnt[y + 1]--;
    }
        // each ith operation , number of executions? cque 3andi how much ith d added to the array 
    // Number of times each operation is executed
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }

    // Difference array for the original array
    vector<int> diff(n + 2, 0);  

    for (int i = 1; i <= m; i++) {
        int value = d[i] * cnt[i];

        diff[l[i]] += value;
        diff[r[i] + 1] -= value;
    }

    // Apply all modifications
    int cur = 0;

    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        a[i] += cur;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// naive approach

// void solve() {
//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<int> a(n + 1);

//     for (int i = 1; i <= n; i++)
//         cin >> a[i];


      //definition of the m operations 
      //each operation has left , right , value 
//     vector<int> l(m + 1);
//     vector<int> r(m + 1);
//     vector<int> d(m + 1);

//     for (int i = 1; i <= m; i++)
//         cin >> l[i] >> r[i] >> d[i];

//     while (k--) {
//         int x, y;
//         cin >> x >> y;

//         // Apply every operation in this query
//         for (int i = x; i <= y; i++) {

//             // Apply operation i to every affected element
//             for (int j = l[i]; j <= r[i]; j++) {
//                 a[j] += d[i];
//             }
//         }
//     }

//     for (int i = 1; i <= n; i++)
//         cout << a[i] << ' ';
// }

/*
        Rule of thumb

        Prefix sums accumulate information. Difference arrays delay information.

        Prefix sum: many queries, few/no updates.

        Difference array: many updates, one final reconstruction.


        --------------
        1 2 3 
        op1 : 1 2 1 
        op2 : 1 3 2 
        op3 : 2 3 4 
        queries 
        q1 : apply op1 & op2 
        -> 2 3 3  , 4 5 5 
        q2 : apply op1 & op2 & op3 
        -> 565, 787, 7 12 11 
        q3 : apply op2 & op3 
        -> 9 14 13,  9 18 17  


*/
