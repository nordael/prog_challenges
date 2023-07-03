/**-
 * Uma empresa possui N funcionários, que formam uma árvore hierárquica onde cada funcionário tem um chefe,
 * exceto o diretor geral.
 * Sua tarefa é processar Q consultas do formato: quem é o menor chefe comum dos funcionários A e B na hierarquia?
 *
 * Input
 * A primeira linha de entrada possui dois inteiros N e Q (1≤N,Q≤2⋅10⁵): o número de funcionários e consultas.
 * Os funcionários são numerados 1,2,…,N, e o funcionário 1 é o diretor geral. A próxima linha tem N−1 inteiros
 * E2,E3,…,EN (1≤Ei≤i−1): para cada funcionário 2,3,…,N, seu chefe.
 *
 * Por fim, existem Q linhas descrevendo as consultas. Cada linha tem dois inteiros A e B (1≤A,B≤N): quem é o
 * menor chefe comum dos funcionários A e B?
 *
 * Output
 * Imprima a resposta para cada consulta.
 */

#include<bits/stdc++.h>
using namespace std;

typedef long long llong;

const llong MAXN = 2e5+5, LOG = 20;
llong depth[MAXN], anc[MAXN][LOG];
vector<llong> adj[MAXN];

void dfs(llong v, llong p) {
    depth[v] = depth[p] + 1;
    anc[v][0] = p;
    for(llong i = 1; i < LOG; i++)
        anc[v][i] = anc[anc[v][i-1]][i-1];

    for(llong u : adj[v]) if(u != p)
            dfs(u, v);
}

llong lca(llong u, llong v) {
    if(depth[u] < depth[v]) swap(u, v);

    for(llong i = LOG - 1; i >= 0; i--)
        if(depth[u] - (1<<i) >= depth[v])
            u = anc[u][i];

    if(u == v) return u;

    for(llong i = LOG - 1; i >= 0; i--)
        if(anc[u][i] != anc[v][i])
            u = anc[u][i], v = anc[v][i];

    return anc[u][0];
}

int main() {
    llong n, q;
    cin >> n >> q;
    for(llong i = 2; i <= n; i++) {
        llong boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    dfs(1, 0);

    while(q--) {
        llong a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}
