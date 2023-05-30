/**
 * @brief
 * Todos os anos, a SBC (Sociedade Brasileira de Caminhoneiros) reúne seus membros em alguma cidade para discutir
 * sobre a profissão. O grande problema desse tipo de encontro é que os membros estão espalhados pelo país, uma vez
 * que a profissão exige que eles viajem para diversos lugares todos os dias. Por isso, a escolha da cidade onde será
 * feita a reunião sempre é feita de modo que não prejudique demais nenhum dos caminhoneiros. O critério para tal é que
 * a maior das distâncias percorridas pelos caminhoneiros para chegar ao local da reunião deve ser a menor possível.
 * Ou seja, a distância percorrida pelo caminhoneiro que vai percorrer a maior distância entre todos os caminhoneiros
 * para chegar à reunião deve ser a menor possível.
 * Dadas as cidades onde se encontram os caminhoneiros e a descrição das estradas que interligam essas cidades,
 * escreva um programa que determina qual será a menor distância máxima percorrida por um caminhoneiro para chegar
 * até o local da reunião. Os caminhoneiros conhecem bem as estradas, e portando sempre fazem o menor caminho possível
 * até a cidade da reunião. Sempre existe um caminho ligando quaisquer duas cidades.
 *
 * Input
 * A primeira linha da entrada possui dois números inteiros N (2≤N≤100) e M(N−1≤M≤10⁴), que representam,
 * respectivamente, o número de cidades e o número de estradas que as interligam. As cidades são identificadas por
 * números inteiros entre 0 e N−1. As próximas M linhas da entrada possuem, cada uma, a descrição de uma estrada.
 * Cada descrição de entrada é composta por três números inteiros: U, V e W, onde U e V representam cidades
 * (0≤U≤N−1 e 0≤V≤N−1) e W representa o comprimento da estrada que une essas duas cidades (todas as estradas são mão
 * dupla, 1≤W≤100). É sempre possível viajar entre qualquer duas cidades com as estradas existentes, mas pode haver
 * mais de uma estrada ligando o mesmo par de cidades.
 *
 * Output
 * Seu programa deve imprimir uma única linha contendo um número inteiro, a distância máxima percorrida por um
 * caminhoneiro para ir até a reunião, obedecidas as restrições estabelecidas (ou seja, essa distância máxima deve
 * ser a menor possível).
 **/

#include <bits/stdc++.h>

using namespace std;

// Estrutura para representar uma estrada
struct Road {
    int destination;
    int length;
};

// Função para encontrar a menor distância máxima percorrida por um caminhoneiro
int findMinMaxDistance(int start, vector<vector<Road>>& graph, int numCities) {
    // Vetor para armazenar as distâncias mínimas de cada cidade até a cidade de reunião
    vector<int> distances(numCities, INT_MAX);
    distances[start] = 0;

    // Fila para percorrer as cidades em largura
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int currentCity = q.front();
        q.pop();

        // Percorre todas as estradas saindo da cidade atual
        for (const Road& road : graph[currentCity]) {
            int nextCity = road.destination;
            int roadLength = road.length;

            // Atualiza a distância mínima da próxima cidade se for menor do que a distância atual
            if (distances[currentCity] + roadLength < distances[nextCity]) {
                distances[nextCity] = distances[currentCity] + roadLength;
                q.push(nextCity);
            }
        }
    }

    // Encontra a maior distância mínima percorrida entre todas as cidades
    int maxDistance = 0;
    for (int distance : distances) {
        maxDistance = max(maxDistance, distance);
    }

    return maxDistance;
}

int main() {
    int numCities, numRoads;
    cin >> numCities >> numRoads;

    // Criação do grafo
    vector<vector<Road>> graph(numCities);

    // Leitura das estradas
    for (int i = 0; i < numRoads; i++) {
        int city1, city2, length;
        cin >> city1 >> city2 >> length;

        // Adiciona as estradas de ida e volta ao grafo
        graph[city1].push_back({ city2, length });
        graph[city2].push_back({ city1, length });
    }

    // Encontra a menor distância máxima percorrida por um caminhoneiro
    int minMaxDistance = INT_MAX;
    for (int startCity = 0; startCity < numCities; startCity++) {
        int maxDistance = findMinMaxDistance(startCity, graph, numCities);
        minMaxDistance = min(minMaxDistance, maxDistance);
    }

    // Imprime a resposta
    cout << minMaxDistance << endl;

    return 0;
}