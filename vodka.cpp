#include <bits/stdc++.h>
using namespace std;

//HAS BUGS

const int MAXN = 2005;

int N, M, I, P, C[MAXN], V[MAXN];
int dp[MAXN][MAXN], pre[MAXN][MAXN];

int main() {
    scanf("%d%d%d%d", &N, &M, &I, &P);
    for(int i = 0; i < M; i++) scanf("%d", &C[i]);
    for(int i = 1; i <= M; i++) scanf("%d", &V[i]);

    for(int i = 0; i <= M; i++) dp[1][i] = i*I+P+V[i]-C[i];
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = 1e9;
            for(int k = 0; k <= M; k++) {
                int cost = dp[i-1][k]+j*I+P+V[j]-C[j];
                if(dp[i][j] > cost) {
                    dp[i][j] = cost;
                    pre[i][j] = k;
                }
            }
        }
    }

    int ans = 1e9, idx;
    for(int i = 1; i <= M; i++) {
        if(dp[N][i] < ans) {
            ans = dp[N][i];
            idx = i;
        }
    }

    vector<int> res;
    for(int i = N; i >= 1; i--) {
        res.push_back(idx);
        idx = pre[i][idx];
    }
    reverse(res.begin(), res.end());

    printf("%d\n", ans);
    if(res.empty()) printf("0\n");
    else {
        for(int i = 0; i < res.size(); i++) {
            printf("%d", res[i]);
            if(i != res.size()-1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
