/**
 * Dados dois extremos inteiros A e B, imprima o número de pontos inteiros entre eles. Um ponto inteiro é
 * aquele cujos pontos tem coordenadas X e Y inteiras.
 *
 * Por exemplo, para A=(−2,−2) e B=(−4,−4) a saída é 3 pois temos os pontos (−2,−2), (−3,−3) e (−4,−4).
 *
 * Input
 *         A entrada começa com um inteiro T (1≤T≤100), o número de casos de teste. Cada caso contém quatro inteiros
 *         AX, AY, BX e BY (−10⁹≤AX,AY,BX,BY≤10⁹) sendo que A=(AX,AY) e B=(BX,BY).
 *
 * Output
 *         Para cada caso de teste, imprima o número de pontos inteiros entre A e B.
 **/

#include <bits/stdc++.h>

#define llong long long

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        llong AX, AY, BX, BY;
        cin >> AX >> AY >> BX >> BY;

        llong dx = abs(BX - AX), dy = abs(BY - AY);
        llong gcd = __gcd(dx, dy);
        // número de pontos inteiros é igual a gcd(dx, dy) + 1
        cout << gcd + 1 << endl;
    }
    return 0;
}
