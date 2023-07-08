/** @brief
 * A rede de Syrjälä tem N computadores e M cabos de rede entre eles. A rede consiste em componentes de computadores
 * que podem enviar mensagens entre si.
 *
 * Ninguém em Syrjälä entende como a rede funciona. Por esse motivo, se um cabo de rede for arrebentado, ninguém o
 * consertará. Nesta situação, um componente pode ser dividido em dois componentes.
 *
 * Sua tarefa é calcular o número de componentes após cada cabo arrebentado.
 *
 * Input
 * A primeira linha de entrada tem três números ullongeiros N (1≤N≤10⁵), M (1≤M≤2⋅10⁵) e K (1≤K≤M): o número de
 * computadores, conexões e cabos arrebentados. Os computadores são numerados 1,2,…,N.
 *
 * Então, existem M linhas descrevendo os cabos de rede. Cada linha tem dois ullongeiros A e B (1≤A,B≤N): existe uma
 * conexão entre os computadores A e B. Cada conexão é entre dois computadores diferentes e há no máximo uma conexão
 * entre dois computadores.
 *
 * Finalmente, existem K linhas descrevendo os cabos de rede arrebentados. Cada linha tem dois ullongeiros
 * A e B (1≤A,B≤N): o cabo de rede entre os computadores A e B foi arrebentado.
 *
 * Output
 * Após cada cabo de rede arrebentado, imprima o número de componentes.
 **/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5+5;

int parent[MAXN], sz[MAXN], comp;
set<pii> broken_edges;
vector<pii> edges, broken;
vector<int> ans;

int find(int v){
    if(parent[v]==v) return v;
    return parent[v] = find(parent[v]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        comp--;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    comp = n;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
    }
    for(int i=0;i<k;i++){
        int a, b;
        cin >> a >> b;
        broken.push_back({a,b});
        broken_edges.insert({a,b});
        broken_edges.insert({b,a});
    }
    for(auto p: edges){
        int u = p.first, v = p.second;
        if(broken_edges.find({u,v}) == broken_edges.end()){
            join(u,v);
        }
    }
    for(int i=k-1;i>=0;i--){
        ans.push_back(comp);
        join(broken[i].first, broken[i].second);
    }
    for(int i=k-1;i>=0;i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

