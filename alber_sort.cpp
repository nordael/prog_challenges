#include <iostream>
#include <vector>

/*
 * Para resolver esse problema, podemos usar a técnica de backtracking para gerar todas as possíveis permutações dos
 * livros na estante, respeitando as restrições impostas por Alber.Primeiro, vamos construir um grafo direcionado em
 * que cada livro é um nó e cada restrição é uma aresta do nó A para o nó B.
 * Isso significa que o livro A deve vir antes do livro B na ordem final. Em seguida, podemos usar uma busca em profundidade
 * (DFS) para gerar todas as permutações possíveis, visitando os nós em ordem topológica.
 * Para implementar a busca em profundidade, podemos usar um vetor para armazenar a permutação atual e outro vetor para
 * marcar quais nós já foram visitados. Em cada nó, verificamos se todos os seus predecessores já foram visitados antes
 * de adicioná-lo à permutação atual e continuar a busca. Quando atingirmos o final da permutação (ou seja, quando todos
 * os nós foram visitados), imprimimos a permutação e retornamos.
 */

using namespace std;

const int MAXN = 12;

vector<int> graph[MAXN+1];
int indegree[MAXN+1];
int n, c;
bool visited[MAXN+1];
int permutation[MAXN+1];
int count_permutations;

void dfs(int pos) {
    if (pos == n) { // final da permutação
        count_permutations++;
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && indegree[i] == 0) { // nó não visitado e sem predecessores não visitados
            visited[i] = true;
            permutation[pos] = i;
            for (int j = 0; j < graph[i].size(); j++) { // atualiza os predecessores
                indegree[graph[i][j]]--;
            }
            dfs(pos+1);
            for (int j = 0; j < graph[i].size(); j++) { // desfaz as atualizações
                indegree[graph[i][j]]++;
            }
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> c;

    // constrói o grafo
    for (int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    // busca em profundidade
    count_permutations = 0;
    dfs(0);

    return 0;
}
