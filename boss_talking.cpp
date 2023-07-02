/**
* Uma empresa possui N funcionários, que formam uma árvore hierárquica onde cada funcionário tem um chefe,
 * exceto o diretor geral. Sua tarefa é processar Q consultas do formulário: quem é o chefe do funcionário X
 * que está K níveis acima na hierarquia?
 *
 * Input
 * A primeira linha de entrada possui dois inteiros N e Q (1≤N,Q≤2⋅105): o número de funcionários e consultas.
 * Os funcionários são numerados 1,2,…,N, e o funcionário 1 é o diretor geral. A próxima linha tem N−1 inteiros
 * E2,E3,…,EN (1≤Ei≤i−1): para cada funcionário 2,3,…,N seu chefe.
 * Por fim, existem Q linhas descrevendo as consultas. Cada linha tem dois inteiros X e K (1≤X,K≤N): quem é o
 * chefe do funcionário X que está K níveis acima?
 *
 * Output
 * Imprima a resposta para cada consulta. Se um chefe não existir, imprima −1.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long llong;

#define MAXN 200010
#define LOGN 20

vector<llong> g[MAXN];
llong parent[LOGN][MAXN];

void dfs(llong u, llong p){
    parent[0][u] = p;
    for(llong v: g[u]){
        if(v==p) continue;
        dfs(v, u);
    }
}

llong getBoss(llong x, llong k){
    for(llong i = 0; i < LOGN; i++){
        if(k & (1<<i)){
            x = parent[i][x];
            if(x==-1) break;
        }
    }
    return x;
}

int main(){
    llong n, q;
    cin >> n >> q;

    for(llong i = 2; i <= n; i++){
        llong boss;
        cin >> boss;
        g[boss].push_back(i);
    }

    for(llong i = 0; i < LOGN; i++)
        for(llong j = 0; j <= n; j++)
            parent[i][j] = -1;

    dfs(1, -1);

    for(llong i = 1; i < LOGN; i++)
        for(llong j = 1; j <= n; j++)
            if(parent[i-1][j] != -1)
                parent[i][j] = parent[i-1][parent[i-1][j]];

    for(llong i = 0; i < q; i++){
        llong x, k;
        cin >> x >> k;
        cout << getBoss(x, k) << "\n";
    }

    return 0;
}
