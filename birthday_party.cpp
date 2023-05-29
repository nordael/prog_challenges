/**
 * @brief
 * Mallu tem muitos amigos de computação. Seu aniversário está chegando e ela quer fazer uma super festa temática,
 * à qual todos estarão convidados. É claro que Mallu sabe que isso não é possível: por serem de computação, seus
 * amigos facilmente criam rivalidades baseados no editor de texto que as pessoas usam - tem o grupo do Vim, o do
 * Emacs, o do Nano, e por aí vai.
 * Para evitar brigas, Mallu vai fazer várias festas, de maneira que ninguém encontre um rival no evento que for
 * — veja que uma rivalidade é formada por duas pessoas que não usam o mesmo editor. Ela, particularmente, não é de
 * computação, então pediu a você que escrevesse um programa que decida qual o menor número de festas necessárias
 * para que essa condição seja cumprida.
 *
 * Input
 *
 * A entrada é dada por uma linha contendo os números N (1≤N≤10³) e M (0≤M≤N(N−1)²) separados por espaço, onde N é o
 * número de amigos que Mallu vai convidar e M é o número de amizades encontradas entre eles.
 *
 * As próximas M linhas contém, cada uma, dois números A e B (0≤A,B<N), indicando que os indivíduos de número A e B
 * são amigos — isto é, usam o mesmo editor de texto. É garantindo que nenhum par de amigos aparece duas vezes
 * na entrada.
 *
 * Output
 *
 * Imprima um único valor indicando quantas festas Mallu precisa fazer.
 *
 * TODO: funciona parcialmente para alguns casos de teste
 **/


#include <bits/stdc++.h>

using namespace std;

// Função para encontrar o menor número de festas necessárias
int encontrarNumeroDeFestas(int N, const vector<pair<int, int>>& amizades) {
    vector<vector<int>> adj(N); // Lista de adjacência para representar as amizades
    vector<bool> visitado(N, false); // Vetor para marcar os amigos já visitados
    int numFestas = 0; // Número de festas necessárias

    // Construir o grafo
    for (const auto& amizade : amizades) {
        int a = amizade.first;
        int b = amizade.second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Percorrer todos os amigos
    for (int i = 0; i < N; i++) {
        if (!visitado[i]) {
            numFestas++; // Iniciar uma nova festa
            queue<int> fila;
            fila.push(i);
            visitado[i] = true;

            // Realizar uma busca em largura no grafo para encontrar todos os amigos da mesma festa
            while (!fila.empty()) {
                int amigo = fila.front();
                fila.pop();

                // Verificar os amigos não visitados do amigo atual
                for (int vizinho : adj[amigo]) {
                    if (!visitado[vizinho]) {
                        fila.push(vizinho);
                        visitado[vizinho] = true;
                    }
                }
            }
        }
    }

    // Considerar os amigos que não têm amizades como festas individuais
    unordered_set<int> amigosSemAmizades;
    for (int i = 0; i < N; i++) {
        if (!visitado[i]) {
            numFestas++;
            amigosSemAmizades.insert(i);
        }
    }

    // Verificar se as festas individuais precisam ser mescladas com outras festas
    for (int amigo : amigosSemAmizades) {
        for (int i = 0; i < N; i++) {
            if (amigo != i && !amigosSemAmizades.count(i)) {
                numFestas++;
                break;
            }
        }
    }

    return numFestas;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> amizades(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        amizades[i] = make_pair(a, b);
    }

    int numFestas = encontrarNumeroDeFestas(N, amizades);
    cout << numFestas << endl;

    return 0;
}

