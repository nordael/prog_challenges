/**
 * Os cupins são um dos insetos mais bem-sucedidos do mundo! Eles colonizaram praticamente toda a Terra
 * (excluindo a Antártica), provavelmente porque como nós, eles são animais sociais. Os cupins formam ninhos que
 * podem chegar a 8 metros de altura e com mais de 2 milhões de integrantes! Esse ninhos criam uma espécie de
 * "microclima" que regula a temperatura, umidade e ventilação do ambiente simulando um clima de floresta tropical,
 * permitindo que seja possível eles sobreviverem em quase qualquer clima, sustentando inclusive a sobrevivência de
 * um fungo exclusivo aos seus ninhos que permite a digestão da celulose.
 * Devido a esse microclima criado, é necessário que o acesso ao mundo externo seja feito de forma ordeira.
 * Geralmente os cupins criam túneis debaixo da terra que levam ao cupinzeiro, existindo uma gama de diferentes
 * tipos de túneis que lhes permitem explorar o ambiente ou facilitar o transporte do alimento de volta para o
 * ninho. O procedimento feito por um cupim é de criar um túnel para um novo lugar partindo de um lugar já existente.
 * Isso acabou por gerar uma rede complexa de túneis subterrâneos, que começam no ninho, o lugar 0. Então os cupins
 * pedem a sua ajuda para otimizar o seu trabalho! Qual a menor distância entre um par de lugares?
 *
 * Input
 * A primeira linha contém um inteiro N(2≤N≤10⁵) representando a quantidade de lugares. Seguem então N−1 linhas,
 * com dois inteiros que descrevem a construção de um novo túnel. A construção de um novo túnel com origem no lugar
 * i (1≤i≤N−1) contém os inteiros Ai (0≤Ai≤i−1), o lugar de destino do túnel e Ci (1≤Ci≤10⁹), o comprimento do túnel.
 * Em seguida segue um inteiro Q (1≤Q≤10⁵), a quantidade de consultas. Em seguida seguem Q consultas, cada uma em
 * uma linha, com dois inteiros distintos A e B (0≤A,B≤N−1), os dois lugares que se quer saber a menor distância.
 *
 * Output
 * Imprima a resposta para cada consulta na mesma ordem que aparece na entrada.
 *
 * @brief Combina de BFS (Breadth-First Search) para calcular o custo de cada caminho e um algoritmo para
 * processamento de consulta de intervalo mínimo (RMQ),
*/


#include<bits/stdc++.h>
using namespace std;
typedef  long long llong;

const llong MAXN = 1e5+5;
const llong LOGN = 20;
vector<pair<llong,llong>> g[MAXN];
llong depth[MAXN], dp[LOGN][MAXN];
long long dist[MAXN];
llong N, Q;

void dfs(llong v, llong p) {
    dp[0][v] = p;
    for(auto e : g[v]) {
        llong u = e.first;
        llong w = e.second;
        if(u == p) continue;
        depth[u] = depth[v] + 1;
        dist[u] = dist[v] + w;
        dfs(u, v);
    }
}

llong lca(llong a, llong b) {
    if(depth[a] < depth[b]) swap(a, b);
    llong dif = depth[a] - depth[b];
    for(llong i = LOGN-1; i >= 0; i--) {
        if(dif & (1 << i)) {
            a = dp[i][a];
        }
    }
    if(a == b) return a;
    for(llong i = LOGN-1; i >= 0; i--) {
        if(dp[i][a] != dp[i][b]) {
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[0][a];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> N;
    for(llong i = 1; i < N; i++) {
        llong A, C;
        cin >> A >> C;
        g[i].push_back({A, C});
        g[A].push_back({i, C});
    }
    dfs(0, 0);
    for(llong i = 1; i < LOGN; i++) {
        for(llong j = 0; j < N; j++) {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    cin >> Q;
    while(Q--) {
        llong A, B;
        cin >> A >> B;
        llong LCA = lca(A, B);
        cout << dist[A] + dist[B] - 2*dist[LCA] << "\n";
    }
    return 0;
}
