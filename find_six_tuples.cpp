/*
 * Te é dado um conjunto S de inteiros, e a sua tarefa é achar o número total de sêxtuplas (a,b,c,d,e,f)
 * com a,b,c,d,e,f∈S e d≠0 que satisfazem:
 *
 * c=d*(f+e)-a*b
 *
 * Input
 * A primeira linha contém o inteiro N (1≤N≤100), o tamanho de S. Seguem os elementos S1,S2,…,SN (−3⋅10⁴≤Si≤3⋅10⁴)
 * de S nas próximas N linhas. Todos os números são distintos.
 *
 * Output
 * Imprima a quantidade de sêxtuplas plausíveis.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong N;
    cin >> N;

    vector<llong> S(N);
    for(llong i=0; i<N; ++i)
        cin >> S[i];

    unordered_map<llong, llong> left, right;

    for(llong a=0; a<N; ++a)
        for(llong b=0; b<N; ++b)
            for(llong c=0; c<N; ++c)
                left[S[c]+S[a]*S[b]]++; //map all possible left side (c+a*b)

    for(llong d=0; d<N; ++d)
        if(S[d]) // to avoid division by zero
            for(llong e=0; e<N; ++e)
                for(llong f=0; f<N; ++f)
                    right[(S[e]+S[f])*S[d]]++; //map all possible right side ((f+e)*d)

    llong ans = 0;
    for(auto l : left)
        ans += l.second * right[l.first]; //count the sextuples

    cout << ans << "\n";

    return 0;
}

