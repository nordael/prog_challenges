/**
* Você está tentando virar hipster e agora tenta sempre frequentar bares desconhecidos (underground). As pessoas da
 * cidade estão saindo agora da quarentena e visitam bares em sequência, postando nas redes sociais
 * (que você evita usar) e, por isso, você sabe quantas pessoas visitam cada bar a partir das fotos (individuais ou
 * em grupo).
 * A partir das informações de visitas, e sabendo que você pode visitar qualquer bar numa sequência contígua de
 * bares (mas vai visitar o mais desconhecido), determine quantas pessoas conhecem o bar de destino.
 * Posto de outra forma, a partir de um vetor inicial de N números, escreva um programa que realize as seguintes
 * operações:
 *      Para dois índices I e J, somar um número K a todos os números no intervalo [I..J]
 *      Para dois índices I e J, imprimir o menor valor no intervalo [I..J].
 *
 *Input
 * A primeira linha da entrada contém o número N(1≤N≤10⁵), o número de bares sobre o qual serão realizadas as
 * operações, e Q (1≤Q≤10⁵), o número de operações. A próxima linha contém N elementos X (−104≤X≤10⁴) separados
 * por espaço, representando o vetor inicial. Seguem Q linhas descrevendo uma operação. O primeiro número de cada l
 * inha T (T∈{1,2}) define qual operação deve ser realizada. Os próximos dois números I e J (1≤I≤J≤N) definem o
 * intervalo da operação. Caso T=1 segue um quarto número K (−10⁴≤K≤10⁴) indicando que K deve ser somado aos números
 * no intervalo.
 *
 * Output
 * Para cada consulta do tipo 2, imprima uma linha com o menor valor no intervalo da consulta.
 **/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
int n, q;
int arr[MAXN];
pair<int, int> t[4*MAXN];
int lazy[4*MAXN];

void build(int v, int tl, int tr) {
    lazy[v] = 0;
    if (tl == tr) {
        t[v] = make_pair(arr[tl], tl);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

void push(int v) {
    t[v*2].first += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1].first += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v].first += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(INF, -1);
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n-1);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, add;
            cin >> l >> r >> add;
            update(1, 0, n-1, l-1, r-1, add);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n-1, l-1, r-1).first << "\n";
        }
    }
    return 0;
}
