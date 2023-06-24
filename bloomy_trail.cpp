
/**
 * Para atrair mais visitantes, o gerente de um parque nacional teve a ideia de plantar flores em ambos os lados das
 * trilhas populares, que são as trilhas usadas por pessoas comuns. O cidadão comum só vai da entrada do parque até
 * seu pico mais alto, onde as vistas são de tirar o fôlego, por um caminho mais curto. Então, ele quer saber quantos
 * metros de flores são necessários para materializar sua ideia.
 * A partir de uma descrição do parque, com seus pontos de interesse e trilhas, o objetivo é saber a extensão de flores
 * necessária para cobrir as trilhas populares. É garantido que, para as entradas dadas, existe algum caminho desde a
 * entrada do parque até o pico mais alto.
 *
 * Input
 * A primeira linha da entrada tem dois inteiros: P (1≤P≤10⁴) e T (1≤T≤25⋅10⁴). P é o número de pontos de interesse e
 * T é o número de trilhas. Os pontos p são identificados por números inteiros, variando de 0 a P−1, ou
 * seja 0 <= p < P. O ponto de entrada é p = 0 e o pico mais alto é o ponto p = P−1.
 *
 * Cada uma das seguintes T linhas define uma trilha diferente. Ele contém três números inteiros Ai, Bi (1≤Ai,Bi≤P),
 * e Li (1≤Li≤10³), que indicam que a i-ésima trilha quem liga diretamente os pontos Ai e Bi (não necessariamente
 * distintos) e têm comprimento Li (em metros). Inteiros na mesma linha são separados por um único espaço.
 *
 * Output
 *
 * Imprimir a soma da extensão dos caminhos mais curtos que ligam a entrada ao pico mais alto. Gere um algoritimo em
 * c++ para resolver o problema proposto.
 **/

#include <bits/stdc++.h>
using namespace std;

//typedef pair<int, int> pii;
//typedef vector<vector<pii>> Graph;
//
//const int INF = numeric_limits<int>::max();
//
//int dijkstra(const Graph& graph, int source, int target) {
//    int numVertices = graph.size();
//    vector<int> dist(numVertices, INF);
//    vector<int> numPaths(numVertices, 0);
//    vector<int> flowers(numVertices, 0);
//    priority_queue<pii, vector<pii>, greater<pii>> pq;
//
//    dist[source] = 0;
//    numPaths[source] = 1;
//    flowers[source] = 1;
//    pq.push(make_pair(source, 0));
//
//    while (!pq.empty()) {
//        int u = pq.top().first;
//        int distU = pq.top().second;
//        pq.pop();
//
//        if (distU > dist[u])
//            continue;
//
//        for (const pii& neighbor : graph[u]) {
//            int v = neighbor.first;
//            int weight = neighbor.second;
//
//            if (dist[u] + weight < dist[v]) {
//                dist[v] = dist[u] + weight;
//                numPaths[v] = numPaths[u];
//                flowers[v] = flowers[u];
//                pq.push(make_pair(v, dist[v]));
//            } else if (dist[u] + weight == dist[v]) {
//                numPaths[v] += numPaths[u];
//                flowers[v] += flowers[u];
//            }
//        }
//    }
//
//    return flowers[target];
//}
//
//int main() {
//    int P, T;
//    cin >> P >> T;
//
//    Graph graph(P);
//
//    for (int i = 0; i < T; i++) {
//        int A, B, L;
//        cin >> A >> B >> L;
//        graph[A].push_back(make_pair(B, L));
//        graph[B].push_back(make_pair(A, L));
//    }
//
//    int source = 0;
//    int target = P - 1;
//
//    int totalFlowers = dijkstra(graph, source, target);
//    int totalLength = totalFlowers * 2; // Leve em consideração os dois lados da trilha
//
//    cout << totalLength << endl;
//
//    return 0;
//}

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<int, int> edge;

const int INF = numeric_limits<int>::max();

// Função para criar um par ordenado representando uma aresta
edge makeEdge(int u, int v) {
    if (u > v)
        swap(u, v);
    return {u, v};
}

// Classe para representar um grafo ponderado
class Graph {
    int V; // Número de vértices
    vector<vector<pii>> adj; // Lista de adjacência

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Adicionar uma aresta ao grafo
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Encontrar o menor caminho entre a entrada (0) e o pico mais alto (P-1)
    int findShortestPath() {
        vector<int> dist(V, INF); // Vetor de distâncias
        vector<int> paths(V, 0); // Vetor de caminhos mais curtos
        set<edge> edges; // Conjunto de arestas nos caminhos mais curtos
        priority_queue<piii, vector<piii>, greater<piii>> pq; // Fila de prioridade para Dijkstra

        dist[0] = 0; // Distância da entrada é 0
        paths[0] = 1; // Número de caminhos para a entrada é 1
        pq.push({0, {0, -1}}); // Inserir entrada na fila de prioridade

        while (!pq.empty()) {
            int u = pq.top().second.first;
            int parent = pq.top().second.second;
            int cost = pq.top().first;
            pq.pop();

            // Se o vértice já foi visitado com um custo menor, ignorar
            if (cost > dist[u])
                continue;

            // Atualizar distância para os vizinhos de u
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Verificar se é possível usar a aresta na trilha
                if (parent != -1 && (u == parent || v == parent))
                    weight *= 2;

                // Relaxamento da aresta
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    paths[v] = paths[u];
                    edges.insert(makeEdge(u, v));
                    pq.push({dist[v], {v, u}});
                } else if (dist[u] + weight == dist[v]) {
                    paths[v] += paths[u];
                    edges.insert(makeEdge(u, v));
                }
            }
        }

        // Calcular o comprimento total dos caminhos mais curtos
        int totalLength = 0;
        for (const edge& e : edges) {
            int u = e.first;
            int v = e.second;
            for (const pii& neighbor : adj[u]) {
                if (neighbor.first == v) {
                    totalLength += neighbor.second;
                    break;
                }
            }
        }

        return totalLength;
    }
};

int main() {
    int P, T;
    cin >> P >> T;

    Graph g(P);

    // Ler as informações das trilhas e adicionar ao grafo
    for (int i = 0; i < T; i++) {
        int A, B, L;
        cin >> A >> B >> L;
        g.addEdge(A, B, L);
    }

    int totalLength = g.findShortestPath();

    cout << totalLength << endl;

    return 0;
}

