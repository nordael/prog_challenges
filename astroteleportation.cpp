/**
 * @brief: Resolvido usando a técnica de Binary Lifting.
 * Você está jogando um jogo que tem N planetas. Cada planeta tem um teleportador para outro planeta
 * (ou o próprio planeta). Sua tarefa é processar Q consultas da forma: Se você começar no planeta X e
 * viajar por K teleportadores, qual planeta você vai alcançar?
 *
 * Input
 * A primeira linha da entrada tem dois inteiros N e Q (1≤N,Q≤2⋅10⁵): O número de planetas e de consultas.
 * Os planetas são numerados 1,2,…,N.
 * A segunda linha tem N inteiros t1,t2,…,tN (1≤ti≤N): Para cada planeta, o destino do teleportador. É possível
 * que ti=i. Finalmente, seguem Q linhas descrevendo as consultas. Cada linha tem dois inteiros X (1≤X≤N) e K
 * (0≤K≤10⁹): Você começa no planeta X e viaja por K teleportadores.
 *
 * Output
 * Imprima a resposta para cada consulta.
*/

#include<bits/stdc++.h>
using namespace std;

typedef  long long llong;

const llong MAXN = 2e5+5;
const llong LOG = 30;

llong N, Q;
llong teleport[MAXN];
llong ancestor[MAXN][LOG];

void preprocess(){
    for(llong i=1; i<=N; ++i)
        ancestor[i][0] = teleport[i];

    for(llong j=1; j<LOG; ++j)
        for(llong i=1; i<=N; ++i)
            ancestor[i][j] = ancestor[ ancestor[i][j-1] ][j-1];
}

llong process_query(llong X, llong K){
    for(llong i=LOG-1; i>=0; --i)
        if(K >= (1LL<<i)){
            X = ancestor[X][i];
            K -= (1LL<<i);
        }
    return X;
}

int main(){
    cin >> N >> Q;

    for(llong i=1; i<=N; ++i)
        cin >> teleport[i];

    preprocess();

    for(llong i=1; i<=Q; ++i){
        llong X;
        llong K;
        cin >> X >> K;
        cout << process_query(X, K) << "\n";
    }

    return 0;
}
