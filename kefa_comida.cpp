#include <bits/stdc++.h>

#define ullong unsigned long long

using namespace std;

const ullong N = 18;
const ullong MAXLN = (1<<N);

ullong n, m, k, a[N];
ullong c[N][N], dp[MAXLN][N];

ullong solve(ullong mask, ullong last) {
    if (__builtin_popcount(mask) == m) return 0;
    if (dp[mask][last] != -1) return dp[mask][last];

    ullong ans = 0;
    for (ullong i = 0; i < n; i++) {
        if ((mask & (1ULL<<i)) == 0) {
            ullong bonus = (last == n) ? 0 : c[last][i];
            ans = max(ans, solve(mask | (1ULL<<i), i) + a[i] + bonus);
        }
    }
    dp[mask][last] = ans;

    return dp[mask][last];
}

signed main() {

    cin >> n >> m >> k;

    for (ullong i = 0; i < n; i++) cin >> a[i];

    memset(c, 0, sizeof(c));
    for (ullong i = 0; i < k; i++) {
        ullong x, y, z; cin >> x >> y >> z;
        c[x-1][y-1] = z;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, n) << endl;

    return 0;
}




