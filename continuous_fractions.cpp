
//Seja b0,b1,b2,…,bn os inteiros com bk>0 com k>0. A fração contínua de ordem n com coeficientes b1,b2,…,bn e o
//termo inicial b0 é definido pela seguinte expressão:
//
//    b0 + 1/(b1 + 1/(b2 + 1/… + 1/bn))
//
//que pode ser abreviado como [b0;b1,b2,…,bn].
//
//Um exemplo de uma fração contínua de ordem 3 é [2;3,1,4]. Isso é equivalente a
//
//    2+1/(3+1/(1+1/4)) = 43/19
//
//Escreva um programa que determine a expansão de um número racional como uma fração contínua. Para que seja único,
//faça com que bn>1.
//
//Input
//        A primeira linha de entrada é composta do inteiro T (1≤T≤100), a quantidade de casos de teste. Em seguida
//        seguem T casos de teste, cada um em uma linha, contendo os inteiros N (0≤N≤10⁵) e D (1≤D≤10⁵), o numerador e
//        denominador respectivamente, formando o número N/D.
//
//Output
//        Para cada caso de teste, você deve imprimir a fração contínua correspondente.

#include <bits/stdc++.h>

#define ullong unsigned long long

using namespace std;

// Algoritmo de Euclides estendido para calcular os coeficientes da fração contínua
vector<ullong> euclid(ullong a, ullong b) {
    vector<ullong> coef;
    while (b > 0) {
        ullong q = a / b;
        ullong r = a % b;
        coef.push_back(q);
        a = b;
        b = r;
    }
    return coef;
}

int main() {
    ullong t;
    cin >> t;
    while (t--) {
        ullong n, d;
        cin >> n >> d;
        ullong b0 = n / d;
        ullong r0 = n % d;
        vector<ullong> coef = euclid(d, r0);
        // Verificar se o último coeficiente é igual a 1, se não for, adicionamos 1 ao final
        if (coef.size() > 0 && coef.back() != 1) {
            coef.push_back(1);
        }
        // Imprimir a fração contínua
        cout << "[" << b0;
        if(coef.size() > 0)
            cout << ";";

        for (ullong i = 0; i < coef.size(); i++) {
            if( i < coef.size() - 1)
                cout << coef[i];

            if (i < coef.size() - 2) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
