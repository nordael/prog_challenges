/**
 * @brief Como o grupo é de anônimos, todos são identificados por um número que indica quando entraram no grupo,
 * sendo que o criador do grupo é o número 1. Como forma de penalizar quem chega atrasado depois de tanto tempo desde
 * a entrada no grupo, toda vez que um integrante chega atrasado, ele deve pedir desculpas a todos que entraram no
 * grupo depois dele. Como esperado, ninguém chega na hora para as reuniões, e se todos forem pedir desculpas, vão
 * ficar horas sem conversar nada.
 *
 * Então, foi sugerido criar um sistema para gerenciar esses atrasos. O grupo dos Atrasados Anônimos então pede sua
 * ajuda para saber quantos pedidos de desculpa teriam sido feitos em uma noite de reunião.
 *
 * Input
 * A primeira linha contém um número N (1≤N≤10⁵), o número de participantes daquela reunião, e um número H (0≤H≤N), a
 * quantidade de participantes que chegaram na hora. Em seguida seguem N números de participante P (0≤P≤10⁹), na ordem
 * em que eles chegaram na reunião. Nem todos vão para as reuniões. Não há números repetidos.
 *
 * Output
 * Imprima a quantidade de pedidos de desculpa que seriam dados pelos participantes que chegaram atrasado.
 * @todo Otimizar o algoritmo para custo inferior a O(n²)
 **/

#include <bits/stdc++.h>
#define ullong unsigned long long

using namespace std;

int main() {

    ullong n, h;
    cin >> n >> h;

    vector<ullong> belated(n);
    for (ullong i = 0; i < n; i++) {
        cin >> belated[i];
    }

    ullong apologies = 0;
    for (ullong i = h; i < n; i++) {
        set<ullong> s(belated.begin(), belated.begin()+i);
        auto it = s.upper_bound(belated[i]);
        while(it != s.end()) {
            apologies++;
            s.erase(it);
            it = s.upper_bound(belated[i]);
        }
    }

    cout << apologies << endl;

    return 0;
}