/**
  *@brief
  *
  * O prefeito Edsger está recebendo muitas reclamações das empresas privadas que cuidam de estradas. O que acontece
  * é que as pessoas tendem a ir pelos mesmos caminhos para economizar gasolina, mas isso acaba desgastando algumas
  * estradas muito mais rápido que outras!
  * Edsger tem um plano para lidar com isso, e quer que você verifique que ele de fato funcionará. Para cada parada
  * (que serve de passagem por pedágio), é atribuído um valor de lotação L; sempre que alguém quiser ir de uma parada
  * a outra, deve pagar a diferença das lotações (Ldestino−Lorigem) em Pedês (a moeda local). Só que alguém disse que
  * isso não vai fazer o menor sentido — alguma coisa com a pessoa receber dinheiro em vez de pagar — que foi o motivo
  * de você ser contactado.
  * Edsger fixou uma parada de origem (a de número 1). Tendo o mapa de estradas e paradas e uma lista de paradas de
  * destino, descubra qual o menor valor que alguém pagará (menor lucro dos pedágios) para chegar lá saindo da primeira.
  * Além disso, avise ao prefeito se realmente não fizer sentido o projeto.
  *
  * Input
  * A primeira linha da entrada contém o ullongeiro N (2≤N≤10⁴), o número de paradas. A próxima linha contém N ullongeiros
  * Li (1≤Li≤8000), que indicam a lotação da i -ésima parada. A terceira linha contém o ullongeiro M
  * (N−1≤M≤min(N*(N−1),10⁴)), o número de estradas que conectam paradas diretamente. As próximas M linhas contém cada
  * uma dois ullongeiros X e Y (1≤X,Y≤N), indicando que existe uma estrada de X a Y (estradas são de mão única). Não
  * existem estradas duplicadas e é garantido que todas as paradas estão conectadas por estradas se for ignorado
  * sentido de cada estrada. Finalmente, é dado um ullongeiro Q (1≤Q≤10³), o número de consultas a serem realizadas,
  * e a próxima linha possui Q ullongeiros X (1≤X≤N), indicando a parada de destino da consulta.
  *
  * Output
  * Para cada consulta imprima "Não, Edsger...", caso o lucro mínimo seja menor que 3, ou um número A, o menor preço
  * que alguém vai pagar se fizer um passeio da primeira parada (identificada por 1) até o dado destino.
 **/

#include <bits/stdc++.h>

#define ullong unsigned long long

using namespace std;

//const ullong INF = numeric_limits<ullong>::max();
//
//struct Edge {
//    ullong destination;
//    ullong cost;
//};
//
//vector<ullong> findMinimumCost(ullong start, const vector<vector<Edge>>& graph) {
//    ullong n = graph.size();
//    vector<ullong> dist(n, INF);
//    priority_queue<pair<ullong, ullong>, vector<pair<ullong, ullong>>, greater<pair<ullong, ullong>>> pq;
//    dist[start] = 0;
//    pq.push({0, start});
//
//    while (!pq.empty()) {
//        ullong u = pq.top().second;
//        ullong curr_dist = pq.top().first;
//        pq.pop();
//
//        if (curr_dist > dist[u])
//            continue;
//
//        for (const Edge& edge : graph[u]) {
//            ullong v = edge.destination;
//            ullong cost = edge.cost;
//            if (dist[u] + cost < dist[v]) {
//                dist[v] = dist[u] + cost;
//                pq.push({dist[v], v});
//            }
//        }
//    }
//
//    return dist;
//}
//
//int main() {
//    ullong N;
//    cin >> N;
//
//    vector<ullong> lotacoes(N);
//    for (ullong i = 0; i < N; i++)
//        cin >> lotacoes[i];
//
//    ullong M;
//    cin >> M;
//
//    vector<vector<Edge>> graph(N);
//    for (ullong i = 0; i < M; i++) {
//        ullong X, Y;
//        cin >> X >> Y;
//        X--; // Convert to 0-based index
//        Y--; // Convert to 0-based index
//        graph[X].push_back({Y, lotacoes[Y] - lotacoes[X]});
//    }
//
//    ullong Q;
//    cin >> Q;
//
//    vector<ullong> destinations(Q);
//    for (ullong i = 0; i < Q; i++)
//        cin >> destinations[i];
//
//    vector<ullong> dist = findMinimumCost(0, graph);
//
//    for (ullong i = 0; i < Q; i++) {
//        ullong destination = destinations[i] - 1; // Convert to 0-based index
//        ullong min_price = dist[destination];
//        if (min_price < 3)
//            cout << "Não, Edsger...";
//        else
//            cout << min_price;
//        cout << endl;
//    }
//
//    return 0;
//}

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination;
    int weight;
};

vector<int> findMinimumCost(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    int n;
    cin >> n;

    vector<int> lotacoes(n);
    for (int i = 0; i < n; i++) {
        cin >> lotacoes[i];
    }

    int m;
    cin >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--; // Adjusting to 0-based indexing
        graph[x].push_back({y, lotacoes[y] - lotacoes[x]});
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int destination;
        cin >> destination;
        destination--; // Adjusting to 0-based indexing

        vector<int> dist = findMinimumCost(graph, 0); // Finding shortest distances from source (parada 1)

        int minimum_price = dist[destination];
        if (minimum_price < 3) {
            cout << "Não, Edsger...";
        } else {
            cout << minimum_price;
        }
        cout << endl;
    }

    return 0;
}