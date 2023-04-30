/**
 * @brief A Banda Quis está em Curitiba! Porém os ingressos são escassos... são apenas N ingresso disponíveis,
 * cada um com um certo preço. Para comprar vão aparecer M fãs da banda, um atrás do outro.
 * Cada fã anuncia o preço máximo que está disposto a pagar por um ingresso, e depois disso, obtém um ingresso de valor
 * mais próximo do seu máximo, sem exceder o seu valor máximo.
 * Input
 * A primeira linha da entrada contém os inteiros N (1≤N≤2⋅10⁵), o número de ingressos e M (1≤M≤2⋅10⁵), o número de fãs
 * da Banda Quis.A próxima linha contém N inteiros H1,H2,…,HN (1≤Hi≤10⁹), o preço de cada ingresso.
 * A próxima linha contém M inteiros T1,T2,…,TM (1≤Ti≤10⁹), o máximo que cada fã está disposto a pagar em ordem de chegada.
 * Output
 * Imprima em ordem de chegada, o preço que será pago por cada fã. Depois disso, o ingresso não poderá ser comprado de
 * novo. Se um fã não conseguir um ingresso, imprima −1.
 *
 * @details Podemos utilizar a estrutura de dados @datastruct multiset<ullong> para armazenar os preços dos ingressos disponíveis
 * em ordem crescente. O multiset é uma estrutura de dados que permite inserção, remoção e busca de elementos em tempo
 * logarítmico (O(log N)), o que é mais eficiente do que a busca linear da solução anterior.
 * Além disso, podemos utilizar a função lower_bound do multiset para encontrar o primeiro ingresso com preço maior do
 * que o valor máximo que o fã está disposto a pagar. A função lower_bound retorna um iterador para o primeiro elemento
 * no multiset que é maior ou igual ao valor especificado.
 * @author Julio Martins
 */

#include <bits/stdc++.h>

#define ullong unsigned long long

using namespace std;

int main() {
    ullong n, m;
    cin >> n >> m;
    multiset<ullong> h;
    for (ullong i = 0; i < n; i++) {
        ullong price;
        cin >> price;
        h.insert(price);
    }
    for (ullong i = 0; i < m; i++) {
        ullong max_price;
        cin >> max_price;
        // encontra o primeiro ingresso com preço maior do que o valor máximo que o fã está disposto a pagar
        auto it = h.lower_bound(max_price+1);
        // se não há ingressos com preço menor ou igual ao valor máximo que o fã está disposto a pagar
        if (it == h.begin()) {
            cout << "-1" << endl;
        } else {
            it--;
            cout << *it << endl;
            h.erase(it);
        }
    }
    return 0;
}