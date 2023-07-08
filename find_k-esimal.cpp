/**
 * Você está trabalhando para a empresa Macrohard no departamento de estruturas de dados. Depois de falhar em sua
 * tarefa anterior sobre inserção de chave, você foi solicitado a escrever uma nova estrutura de dados que seria
 * capaz de retornar rapidamente estatísticas de k-ésima ordem em segmento de vetor.
 * Ou seja, dado um vetor a[1…N]de diferentes números inteiros, seu programa deve responder a uma série de consultas
 * Q(I,J,K) da forma: "Qual seria o K-ésimo número em um segmento [I…J], se este segmento fosse ordenado?"
 *
 * Por exemplo, considere o vetor a=[1,5,2,6,3,7,4]. Seja a consulta Q(2,5,3). O segmento a[2...5] é [5,2,6,3]. Se
 * ordenarmos esse segmento, obtemos [2,3,5,6]e o terceiro número é 5 e, portanto, a resposta à consulta é 5.
 *
 * Input
 * A primeira linha da entrada contém N(1≤N≤10⁵) — o tamanho do vetor e Q (1≤Q≤5⋅10³)— o número de consultas.
 * A segunda linha contém N números inteiros distintos Ai (−10⁹≤Ai≤10⁹)— o vetor que será consultado.
 * As seguintes Q linhas contêm descrições de consultas, e cada descrição consiste em três números: I e J (1≤I≤J≤N),
 * e K (1≤K≤J−I+1) e representa a consulta Q(I,J,K).
 *
 * Output
 * Para cada consulta, imprima a sua resposta — o K-ésimo número no segmento ordenado A[I…J].
 * @brief using persistent segment tree
*/

#include<bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define MAXQ 5005
#define MAXRANGE 1000000000

struct node {
    int left, right;
    node *l, *r;
    node(): left(0), right(0), l(NULL), r(NULL) {}
}*version[MAXN], *NIL;

int a[MAXN], Sorted[MAXN];

void build(node *n, int low, int high) {
    if(low == high)
        return;
    int mid = (low + high) >> 1;
    n -> l = new node();
    n -> r = new node();
    build(n -> l, low, mid);
    build(n -> r, mid + 1, high);
}

void upgrade(node *prev, node *cur, int low, int high, int idx) {
    if(idx > high || idx < low || low > high)
        return;
    if(low == high) {
        cur -> left = prev -> left + 1;
        return;
    }
    int mid = (low + high) >> 1;
    if(idx <= mid) {
        cur -> r = prev -> r;
        cur -> l = new node();
        upgrade(prev -> l, cur -> l, low, mid, idx);
    } else {
        cur -> l = prev -> l;
        cur -> r = new node();
        upgrade(prev -> r, cur -> r, mid + 1, high, idx);
    }
    cur -> left = cur -> l -> left + cur -> r -> left;
}

int query(node *prev, node *cur, int low, int high, int k) {
    if(low == high)
        return low;
    int mid = (low + high) >> 1;
    int count = cur -> l -> left - prev -> l -> left;
    if(count >= k)
        return query(prev -> l, cur -> l, low, mid, k);
    else
        return query(prev -> r, cur -> r, mid + 1, high, k - count);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, m = 0;
    cin >> n >> q;
    map<int, int> M;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        Sorted[i] = a[i];
    }
    sort(Sorted + 1, Sorted + n + 1);
    for(int i = 1; i <= n; i++)
        M[Sorted[i]] = ++m;
    NIL = new node();
    NIL -> l = NIL -> r = NIL;
    version[0] = NIL;
    build(version[0], 1, m);
    for(int i = 1; i <= n; i++) {
        version[i] = new node();
        upgrade(version[i - 1], version[i], 1, m, M[a[i]]);
    }
    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << Sorted[query(version[i - 1], version[j], 1, m, k)] << "\n";
    }
    return 0;
}
