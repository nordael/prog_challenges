/*
 * É dado N cubos em uma certa ordem e a sua tarefa é construir torres com eles. Quando um cubo está em cima de
 * outro, o cubo de cima deve ser menor do que o cubo de baixo. Você deve processar os cubos na ordem dada. Você sempre
 * pode ou colocar um cubo em uma torre já existente, ou criar uma nova torre. Qual o número mínimo possível de torres?
 * Input
 * A primeira linha da entrada contém um inteiro N (1≤N≤2⋅10⁵), o número de cubos. A próxima linha contém N inteiros
 * K1,K2,…,KN (1≤Ki≤10⁹), o tamanho dos cubos.
 * Output
 * Imprima um inteiro: o número mínimo de torres.
 **/

#include <bits/stdc++.h>
#define ullong unsigned long long

using namespace std;

int main() {
    ullong n;
    cin >> n;

    multiset<ullong> towers;

    for (ullong i = 0; i < n; i++) {
        ullong cube;
        cin >> cube;

        auto it = towers.upper_bound(cube);
        // caso especial para quando o conjunto de torres está vazio ou o cubo atual é menor do que a menor torre existente
        if (towers.empty() || it == towers.end()) {
            towers.insert(cube); // cria uma nova torre
        } else {
            // encontra a primeira torre que pode acomodar o cubo
            towers.erase(it); // remove a torre antiga
            towers.insert(cube); // adiciona o cubo à torre
        }
*    }

    cout << towers.size() << endl;

    return 0;
}
