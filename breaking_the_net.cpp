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

#include <bits/stdc++.h>

using namespace std;

#define ullong unsigned long long

vector<set<ullong>> adjList;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int countComponents(int N) {
    int components = 0;
    visited.assign(N + 1, false);

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    return components;
}

void bfs(ullong start) {
    list<ullong> q;
    q.push_back(start);
    visited[start] = true;

    while (!q.empty()) {
        ullong node = q.front();
        q.pop_front();

        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push_back(neighbor);
            }
        }
    }
}

int main() {
    ullong N, M, K;
    cin >> N >> M >> K;

    adjList = vector<set<ullong>>(N + 1);

    for (ullong i = 0; i < M; i++) {
        ullong A, B;
        cin >> A >> B;
        adjList[A].insert(B);
        adjList[B].insert(A);
    }

    for (ullong i = 0; i < K; i++) {
        ullong A, B;
        cin >> A >> B;

        adjList[A].erase(B);
        adjList[B].erase(A);

        ullong components = 0; //countComponents(N);
        visited = vector<bool>(N + 1, false);
        for (ullong j = 1; j <= N; j++) {
            if (!visited[j]) {
                bfs(j);
                components++;
            }
        }
        cout << components << " ";
    }
    cout << endl;

    return 0;
}
