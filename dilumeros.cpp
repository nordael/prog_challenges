/**
 * Dilen é fascinada pelas somas dos dígitos dos números. Ela descobriu por exemplo que a soma dos dígitos
 * (mod9) de um número é exatamente igual ao número (mod 9). E que esse método de obter a soma (mod9) é extremamente
 * útil para validar a soma de números grandes, podendo ser usado por exemplo pelo método da raíz digital: Pegue um número
 * e some os seus dígitos e faça o mesmo com o resultado até obter um único número. Mas Dilen não quer saber de somas de
 * dígitos (mod 9) hoje.
 *
 * O que ela descobriu é que existem muitos números que se forem somados todos os dígitos, resultam em um mesmo número N.
 * Por exemplo para obter o número 12, você pode somar todos os dígitos do número 192, ou do número 11118, etc, e Dilen
 * acredita que o maior número que se pode obter que soma 12 por exemplo é uma sequência de 12 uns: 111111111111.
 * Dilen chamou esses números de N-dilúmeros, no caso de 12 por exemplo, são os 12-dilúmeros.
 *
 * O mistério que Dilen agora quer resolver é encontrar o menor N-dilúmero, afinal, o maior, ela já sabe. Como esse
 * número pode ser muito grande, Dilen quer saber esse número (mod 10⁹ + 7). Ajude Dilen a encontrá-lo!
 *
 * Input
 *
 *        A primeira linha contém T (1≤T≤10⁵), a quantidade de casos de teste. Em seguida seguem T linhas, cada uma
 *        com um inteiro N (0≤N≤10¹⁵).
 *
 * Output
 *
 *        Imprima o menor N-dilúmero (mod 10⁹+7) para cada caso de teste.
 **/

#include <bits/stdc++.h>

#define ullong unsigned long long

using namespace std;

const ullong DIVISOR = 1e9+7;

/**
 *
 * ((d+1) mod DIVISOR) * (10^(n-1) mod DIVISOR) - 1
 * ((d+1) mod DIVISOR) * (10^((n-1)/2) mod DIVISOR) * (10^((n-1)/2) mod DIVISOR) - 1
 */

ullong modular_power(ullong x, ullong y, ullong p){
    ullong res = 1;
    x = x % p;
    if (x == 0) return 0;

    while (y > 0){
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ullong find_ndil(ullong n) {
    if (n < 10) return n;

    //calcula o numero de noves
    ullong nines = (n % 9 > 0) ? (n / 9)+1 : (n / 9);

    // o digito mais significativo
    auto msdigit = n % 9;

    //calcula o resto da divisao por 10⁹+7
    auto exp = (n % 9 > 0) ? nines-1 : nines;
    ullong result = modular_power(10ULL, exp, DIVISOR);

    return (((msdigit+1) * result) % DIVISOR)-1;
}

int main() {
    ullong t;
    cin >> t;
    vector<ullong> cases(t);
    for (auto &item : cases) {
        cin >> item;
    }

    for (auto item : cases) {
        cout << find_ndil(item) << endl;
    }

    return 0;
}
