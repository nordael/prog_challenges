#include <bits/stdc++.h>

//BUG

using namespace std;

const int N = 1e4+5;

int n, k, c, a[N], dp[N][N];

int solve(int pos, int l) {
    if(pos > n-1) return 0;
    int& ans = dp[pos][l];
    if(ans != -1) return ans;

    ans = solve(pos+1, l) + a[pos];
    if(l > 0) ans = max(ans, solve(pos+c, l-1));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> c;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    cout << solve(0, k) << endl;
    return 0;
}

