#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 20;
#define MAXMASK 1 << 30

long long N, A[MAXN+5];
long long dp[MAXN+5][(MAXMASK)+5];

int main() {
    // Leitura da entrada
    cin >> N;
    for(long long i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // Inicialização do DP
    dp[1][A[1]] = 0;

    // Loop principal do DP
    for(long long i = 2; i <= N; i++) {
        for(long long mask = 0; mask < MAXMASK; mask++) {
            dp[i][mask] = dp[i-1][mask];
            dp[i][mask | A[i]] = min(dp[i][mask | A[i]], dp[i-1][mask] ^ A[i]);
        }
    }

    // Impressão da resposta
    cout << dp[N][0] << endl;

    return 0;
}
