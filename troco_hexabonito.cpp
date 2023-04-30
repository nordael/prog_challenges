#include <bits/stdc++.h>
using namespace std;


// lista de valores das moedas em centavos
long troco[5] = {50, 25, 10, 5, 1};
// matriz para memorization
long memo[30001][5];

long countTroco(long valor, long idx) {
    if (valor == 0) return 1; // caso base: troco formado
    if (valor < 0 || idx == 5) return 0; // caso base: impossível formar o troco
    if (memo[valor][idx] != -1) return memo[valor][idx]; // valor já foi calculado

    // considerar e não considerar a moeda atual
    long count = countTroco(valor, idx+1) + countTroco(valor - troco[idx], idx);
    memo[valor][idx] = count;
    return count;
}

int main() {
    long n;
    memset(memo, -1, sizeof memo);

    while (cin >> n) {
        long count = countTroco(n, 0);
        cout << count << endl;
    }
    return 0;
}

//int main() {
//    long coins[] = {1, 5, 10, 25, 50};
//    long n;
//    while (cin >> n) {
//        long dp[n+1] = {0};
//        dp[0] = 1;
//        for (long i = 0; i < 5; i++) {
//            for (long j = coins[i]; j <= n; j++) {
//                dp[j] += dp[j-coins[i]];
//            }
//        }
//        cout << dp[n] << endl;
//    }
//    return 0;
//}