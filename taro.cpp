#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int A[MAXN], B[MAXN], C[MAXN];
int dp[MAXN][3];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    // caso base
    dp[1][0] = A[1];
    dp[1][1] = B[1];
    dp[1][2] = C[1];

    // preenchimento da tabela
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i-1][1] + A[i], dp[i-1][2] + A[i]);
        dp[i][1] = max(dp[i-1][0] + B[i], dp[i-1][2] + B[i]);
        dp[i][2] = max(dp[i-1][0] + C[i], dp[i-1][1] + C[i]);
    }

    // resultado final
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans << endl;

    return 0;
}
