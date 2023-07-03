/**
* Na Nlogônia foi construído um grande sistema de ônibus biarticulados que liga os principais pontos da cidade.
 * Em cada ponto podem ser encontrados estações tubo, que controlam a entrada e a saída do sistema de transporte
 * público. O sistema foi desenhado de forma que para cada estação, existe apenas um caminho entre qualquer outra
 * estação. Algumas estações no sistema são mais transitadas que outras. Podemos ver por exemplo que no caminho do
 * ponto A até o ponto B e no caminho do ponto C até o ponto D podem ser encontradas três estações que obrigatoriamente
 * devem ser transitadas em ambas as viagens.
 * O governo agora está atrás de identificar as estações que são mais transitadas. Para isso, a equipe de engenheiros
 * quer saber quantas estações em comum existem entre duas rotas, dado o mapa do sistema de transporte público.
 *
 * Input
 * A primeira linha contém os números N(4≤N≤10⁵), a quantidade de estações, e Q (1≤Q≤2⋅10⁴), a quantidade de consultas.
 * Cada uma das N−1 linhas seguintes contém dois inteiros distintos U e V (1≤U,V≤N), indicando a existência de uma
 * rota entre as estações U e V. Em seguida seguem Q linhas, cada uma com uma consulta contendo quatro inteiros
 * distintos A, B, C e D (1≤A,B,C,D≤N).
 *
 * Output
 * Imprima as estações em comum nas rotas de A até B e de C até D de cada consulta na mesma ordem da entrada.
*/

//#include<bits/stdc++.h>
//using namespace std;
//
//#define MAXN 100005
//#define LOG 18
//
//vector<int> adj[MAXN];
//int depth[MAXN], parent[LOG][MAXN];
//
//void dfs(int node, int par){
//    parent[0][node] = par;
//    for(int i=1;i<LOG;i++){
//        if(parent[i-1][node] != -1){
//            parent[i][node] = parent[i-1][parent[i-1][node]];
//        }
//    }
//
//    for(int to : adj[node]){
//        if(to == par) continue;
//        depth[to] = depth[node] + 1;
//        dfs(to, node);
//    }
//}
//
//int lca(int u, int v){
//    if(depth[u] < depth[v]) swap(u, v);
//    int diff = depth[u] - depth[v];
//
//    for(int i=0;i<LOG;i++){
//        if((diff>>i)&1){
//            u = parent[i][u];
//        }
//    }
//
//    if(u == v) return u;
//
//    for(int i=LOG-1;i>=0;i--){
//        if(parent[i][u] != parent[i][v]){
//            u = parent[i][u];
//            v = parent[i][v];
//        }
//    }
//    return parent[0][u];
//}
//
//int dist(int u, int v){
//    return depth[u] + depth[v] - 2*depth[lca(u, v)];
//}
//
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n, q;
//    cin >> n >> q;
//
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<LOG;j++){
//            parent[j][i] = -1;
//        }
//    }
//
//    for(int i=0;i<n-1;i++){
//        int u, v;
//        cin >> u >> v;
//        adj[u].push_back(v);
//        adj[v].push_back(u);
//    }
//
//    depth[1] = 0;
//    dfs(1, -1);
//
//    while(q--){
//        int a, b, c, d;
//        cin >> a >> b >> c >> d;
//
//        int x = lca(a, b);
//        int y = lca(c, d);
//        int res = 0;
//
//        if(dist(x, y) % 2 == 0){
//            int z = lca(x, y);
//            res = (dist(x, z) + dist(y, z)) / 2 + 1;
//        }
//        cout << res << "\n";
//    }
//
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LOG 18

vector<int> adj[MAXN];
int depth[MAXN], parent[LOG][MAXN];

void dfs(int node, int par){
    parent[0][node] = par;
    for(int i=1;i<LOG;i++){
        if(parent[i-1][node] != -1){
            parent[i][node] = parent[i-1][parent[i-1][node]];
        }
    }

    for(int to : adj[node]){
        if(to == par) continue;
        depth[to] = depth[node] + 1;
        dfs(to, node);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];

    for(int i=0;i<LOG;i++){
        if((diff>>i)&1){
            u = parent[i][u];
        }
    }

    if(u == v) return u;

    for(int i=LOG-1;i>=0;i--){
        if(parent[i][u] != parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int dist(int u, int v){
    return depth[u] + depth[v] - 2*depth[lca(u, v)];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i=1;i<=n;i++){
        for(int j=0;j<LOG;j++){
            parent[j][i] = -1;
        }
    }

    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, -1);

    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x = lca(a, b);
        int y = lca(c, d);
        int res = 0;

        if(dist(x, y) % 2 == 0){
            int z = lca(x, y);
            res = (dist(x, z) + dist(y, z)) / 2 + 1;
        }
        cout << res << "\n";
    }

    return 0;
}
