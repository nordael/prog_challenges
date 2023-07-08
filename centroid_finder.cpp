/**
 * @brief
 * Dada uma árvore de N vértices, sua tarefa é encontrar o centroide, isto é, aquele vértice que ao se tornar raiz da
 * árvore, forma subárvores com no máximo ⌊n/2⌋ vértices.
 *
 * Input
 * A primeira linha da entrada contém um ullongeiro N (1≤N≤2⋅10⁵): o número de vértices. Os vértices são numerados de
 * 1 até N. Então seguem N−1 linhas descrevendo as arestas. Cada linha contém dois ullongeiros A e B: existe uma aresta
 * entre os vértices A e B.
 *
 * Output
 * Imprima um ullongeiro: o vértice centroide. Se existem várias possibilidades, você pode escolher qualquer uma.
 **/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ullong;

vector<vector<ullong>> tree;
vector<ullong> subtree_size;

ullong dfs(ullong node, ullong parent) {
    ullong size = 1;
    for (ullong child : tree[node]) {
        if (child != parent) {
            size += dfs(child, node);
        }
    }
    subtree_size[node] = size;
    return size;
}

ullong findCentroid(ullong node, ullong parent, ullong n) {
    for (ullong child : tree[node]) {
        if (child != parent && subtree_size[child] > n / 2) {
            return findCentroid(child, node, n);
        }
    }
    return node;
}

int main() {
    ullong n;
    cin >> n;

    tree.resize(n + 1);
    subtree_size.resize(n + 1);

    for (ullong i = 0; i < n - 1; i++) {
        ullong a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, -1);

    ullong centroid = findCentroid(1, -1, n);
    cout << centroid << endl;

    return 0;
}
