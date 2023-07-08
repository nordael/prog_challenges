/**
 * Abel está com muito sono. Ele sempre se força a ficar o maior tempo possível acordado para que consiga estudar
 * para todas as matérias, mas sabe que precisa dormir eventualmente ou perderá sua produtividade. Para decidir se
 * é hora de dormir ou não, Abel joga um jogo consigo mesmo. Se ele responder algo errado no jogo, está com sono
 * demais e é hora de dormir.
 * O jogo é assim: Abel começa com um vetor de N elementos. A cada rodada, ele pode alterar o valor de um elemento
 * ou responder à seguinte pergunta: dados I≤J, o produto dos elementos no intervalo [I,J] é positivo, negativo ou
 * zero?
 * Abel precisa verificar se suas respostas estão corretas, e pediu que você escrevesse um programa que fizesse
 * isso por ele.
 *
 * Input
 * A primeira linha da entrada contém os inteiros N e K (1≤N,K≤10⁵) separados por um espaço. A próxima linha contém
 * N inteiros X (−100≤X≤100) separados por espaços. As K linhas seguintes contém um caractere 'A' ou 'B' indicando
 * o tipo de consulta. Se for 'A', seguem os inteiros I (1≤I≤N) e Y (−100≤Y≤100), indicando que o I-ésimo elemento
 * da sequência deve ser substituído pelo valor Y; se for 'B', seguem os inteiros I e J (1≤I≤J≤N), indicando uma
 * consulta no intervalo fechado [I,J].
 *
 * Output
 * Para cada consulta do tipo 'B', imprima o caractere '+' caso o produto seja positivo, '-' caso seja negativo e
 * '0' caso valha zero. Note que só deve ser impressa uma quebra de linha após todas as respostas.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct _data {
    ll pos, neg, zero;
};

int arr[100005];
_data tree[400005];

void build(int node, int start, int end){
    if(start == end){
        if(arr[start] > 0)
            tree[node].pos = 1;
        else if(arr[start] < 0)
            tree[node].neg = 1;
        else
            tree[node].zero = 1;
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node].pos = tree[2*node].pos + tree[2*node+1].pos;
        tree[node].neg = tree[2*node].neg + tree[2*node+1].neg;
        tree[node].zero = tree[2*node].zero + tree[2*node+1].zero;
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        if(val > 0)
            tree[node] = {1, 0, 0};
        else if(val < 0)
            tree[node] = {0, 1, 0};
        else
            tree[node] = {0, 0, 1};
    } else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        tree[node].pos = tree[2*node].pos + tree[2*node+1].pos;
        tree[node].neg = tree[2*node].neg + tree[2*node+1].neg;
        tree[node].zero = tree[2*node].zero + tree[2*node+1].zero;
    }
}

_data query(int node, int start, int end, int l, int r){
    if(r < start or end < l)
        return {0, 0, 0};
    if(l <= start and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    _data p1 = query(2*node, start, mid, l, r);
    _data p2 = query(2*node+1, mid+1, end, l, r);
    return {p1.pos + p2.pos, p1.neg + p2.neg, p1.zero + p2.zero};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    build(1, 1, N);

    while(K--){
        char type;
        int x, y;
        cin >> type >> x >> y;

        if(type == 'A'){
            update(1, 1, N, x, y);
        } else {
            _data ans = query(1, 1, N, x, y);
            if(ans.zero > 0)
                cout << '0';
            else if(ans.neg % 2 == 0)
                cout << '+';
            else
                cout << '-';
        }
    }
    cout << "\n";

    return 0;
}
