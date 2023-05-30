 /**
  * A Irrácia é uma nação distante e reclusa onde vivem números irracionais — assim chamados pelos quatro motivos que
  * você imaginaria: nenhum pode ser representado por uma razão, nenhum deles raciocina, todos nasceram em Irrácia e a
  * população inteira (como um todo, e não de números nascidos na Inteirônia) torce para o Irracionais Futebol Clube
  * (um time de Futebol de Filósofos N-dimensional).
  * Ra Izdidois, um pequenino número irracional, adora sonhar com bobagens que os mercantes contam quando passam por ali:
  * tudo desde frações até números primos. Em particular, ele inventou uma representação para números inteiros baseada em
  * números primos. Ela funciona assim: cada número N é representado por um conjunto A de pares pi,ei de tal maneira
  * que N=∏{from i=0 to |A|} p_i^(e_i). Agora, Ra tem um número X e quer saber a representação de X−1 em seu sistema.
  * Você pode ajudá-lo?
  *
  * Input
  *         A primeira linha da entrada consiste em um único inteiro T (1≤T≤1000): o número de casos de teste. Seguem T
  *         casos de teste da seguinte forma:
  *         Para um inteiro N (2<N≤10⁷) com K fatores primos, a entrada consiste na fatoração de K em primos: K linhas
  *         com pares de inteiros P (2≤P≤10⁷) e E, P primo e PE≤N, indicando que o fator P divide N E vezes.Todos os
  *         valores P na entrada são distintos.
  *
  * Output
  *         Para cada caso de teste, imprima a fatoração de N−1 tal qual na entrada, ordenada pelos valores de P
  *         (em ordem decrescente).
  */

#include <bits/stdc++.h>

using namespace std;

 int main() {
     int t;
     cin >> t;
     while (t--) {
         int k;
         cin >> k;
         vector<pair<int, int>> factors;
         for (int i = 0; i < k; i++) {
             int p, e;
             cin >> p >> e;
             factors.push_back(make_pair(p, e));
         }
         sort(factors.rbegin(), factors.rend()); // Ordena em ordem decrescente de P
         factors[0].second--; // Decrementa o expoente do maior primo
         if (factors[0].second == 0) factors.erase(factors.begin()); // Remove o par se o expoente se tornar zero
         int n = factors.size();
         cout << n << endl;
         for (int i = 0; i < n; i++) {
             cout << factors[i].first << " " << factors[i].second << endl;
         }
     }
     return 0;
 }


