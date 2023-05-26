/**
 * @brief
 * Te é dado uma árvore com N vértices.
 * O diâmetro de uma árvore é a maior distância entre dois vértices. Sua tarefa é determinar o diâmetro da árvore.
 *
 * Input
 * A primeira linha da entrada contém um inteiro N (1≤2⋅10⁵): o número de vértices. Os vértices são numerados de 1 até N.
 * Então seguem N−1 linhas descrevendo as arestas. Cada linha contém dois inteiros A e B: existe uma aresta entre os
 * vértices A e B.
 *
 * Output
 * Imprima um inteiro: o diâmetro da árvore.
 **/

#include <bits/stdc++.h>

using namespace std;

// Estrutura para representar um vértice da árvore
struct Node {
    int id;
    vector<int> neighbors;
};

// Função para calcular o diâmetro da árvore
int calculateDiameter(const vector<Node>& tree, int start) {
    // Marcar todos os vértices como não visitados
    vector<bool> visited(tree.size() + 1, false);

    // Fila para realizar a busca em largura (BFS)
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));

    int farthestNode, maxDistance = 0;

    // Executar a BFS para encontrar o vértice mais distante do início
    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();

        visited[node] = true;

        if (distance > maxDistance) {
            maxDistance = distance;
            farthestNode = node;
        }

        for (int neighbor : tree[node].neighbors) {
            if (!visited[neighbor]) {
                q.push(make_pair(neighbor, distance + 1));
            }
        }
    }

    // Reinicializar as variáveis para a segunda BFS
    maxDistance = 0;
    visited.assign(tree.size() + 1, false);

    // Executar a BFS a partir do vértice mais distante encontrado
    q.push(make_pair(farthestNode, 0));

    // Executar a BFS para encontrar o vértice mais distante do vértice mais distante
    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();

        visited[node] = true;

        if (distance > maxDistance) {
            maxDistance = distance;
        }

        for (int neighbor : tree[node].neighbors) {
            if (!visited[neighbor]) {
                q.push(make_pair(neighbor, distance + 1));
            }
        }
    }

    return maxDistance;
}

int main() {
    int N;
    cin >> N;

    // Criação da árvore como um vetor de vértices
    vector<Node> tree(N + 1);

    // Leitura das arestas da árvore
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;

        // Adiciona A como vizinho de B e B como vizinho de A
        tree[A].neighbors.push_back(B);
        tree[B].neighbors.push_back(A);
    }

    // Calcula o diâmetro da árvore a partir de qualquer vértice (neste caso, 1)
    int diameter = calculateDiameter(tree, 1);

    cout << diameter << endl;

    return 0;
}
