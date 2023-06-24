/**
 * @brief
 * O sistema rodoviário de um país interliga todas as suas N cidades de modo que, a partir de uma cidade qualquer, é
 * possível chegar a cada uma das outras cidades trafegando pelas estradas existentes. Cada estrada liga duas cidades
 * distintas, tem mão dupla e um único posto de pedágio (o pedágio é pago nos dois sentidos de tráfego). As estradas
 * não se intersectam a não ser nas cidades. Nenhum par de cidades é interligado por duas ou mais estradas.
 *
 * A Transportadora Dias oferece um serviço de transporte de encomendas entre as cidades. Cada encomenda deve ser
 * levada de uma cidade A para uma outra cidade B. A direção da Transportadora Dias define, para cada encomenda, uma
 * rota de serviço, composta por C cidades e C−1 estradas: a primeira cidade da rota de serviço é a origem da encomenda,
 * a última o destino da encomenda. A rota de serviço não passa duas vezes pela mesma cidade, e o veículo escolhido
 * para fazer o transporte de uma encomenda pode trafegar apenas pela rota de serviço definida.
 *
 * Certo dia, no entanto, o veículo que executava uma entrega quebrou e precisou ser levado para conserto em uma cidade
 * que não está entre as cidades de sua rota de serviço. A direção da Transportadora Dias quer saber qual é o menor
 * custo total, em termos de pedágio, para que o veículo entregue a encomenda na cidade destino, a partir da cidade em
 * que foi consertado, mas com uma restrição adicional: se em algum momento o veículo passar por uma das cidades que
 * compõem a sua rota de serviço, ele deve voltar a obedecer a rota de serviço.
 *
 * Input
 * A primeira linha contém quatro inteiros N(4≤N≤250), M(3≤M≤N(N−1)/2), C(2≤C≤N−1) e K (C≤K≤N−1), representando,
 * respectivamente, o número de cidades do país, o número de estradas, o número de cidades na rota de serviço e a
 * cidade em que o veículo foi consertado. As cidades são identificadas por inteiros de 0 a N−1. A rota de serviço
 * é 0,1,…,C−1, ou seja, a origem é 0, de 0 passa para 1, de 1 para 2 e assim por diante, até o destino C−1.
 * As M linhas seguintes descrevem o sistema rodoviário do país. Cada uma dessas linhas descreve uma estrada e contém
 * três inteiros U(0≤U), V(V≤N−1) com U≠V e P (0≤P≤250), indicando que há uma estrada interligando as cidades U e V
 * com custo de pedágio P.
 *
 * Output
 * Para cada caso de teste, o seu programa deve imprimir uma única linha, contendo um único inteiro T, o custo total
 * mínimo necessário, em termos de pedágio, para que o veículo chegue ao destino.
 **/

#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX; // Valor infinito para representar distâncias desconhecidas

struct Edge {
    int to;
    int toll;
};

// Função para encontrar o menor custo total necessário para chegar ao destino
int findMinimumCost(int N, int M, int C, int K, const vector<vector<Edge>>& graph) {
    vector<int> dist(N, INF); // Vetor de distâncias mínimas
    vector<bool> visited(N, false); // Vetor para marcar as cidades visitadas
    dist[K] = 0; // A cidade onde o veículo foi consertado tem distância zero

    // Fila de prioridade para selecionar a cidade com menor distância
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, K}); // Adiciona a cidade inicial na fila de prioridade

    while (!pq.empty()) {
        int u = pq.top().second; // Obtém a cidade com menor distância
        pq.pop();

        if (visited[u]) {
            continue; // Se a cidade já foi visitada, pula para a próxima iteração
        }

        visited[u] = true; // Marca a cidade como visitada

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int toll = edge.toll;

            // Relaxa a aresta se encontrar um caminho mais curto
            if (dist[u] + toll < dist[v]) {
                dist[v] = dist[u] + toll;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[C-1]; // Retorna o custo mínimo para chegar ao destino
}

int main() {
    int N, M, C, K;
    cin >> N >> M >> C >> K;

    vector<vector<Edge>> graph(N);

    for (int i = 0; i < M; i++) {
        int U, V, P;
        cin >> U >> V >> P;
        graph[U].push_back({V, P});
        graph[V].push_back({U, P});
    }

    int minimumCost = findMinimumCost(N, M, C, K, graph);
    cout << minimumCost << endl;

    return 0;
}
