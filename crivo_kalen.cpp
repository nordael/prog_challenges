
/*
 * Kalen estava estudando na escola o Crivo de Eratóstenes. A ideia é que você cria uma tabela de números e itera sobre
 * os números da tabela. Ao encontrar um número não eliminado, você elimina da tabela todos os números múltiplos dele,
 * ou seja, se você encontrar o número 2, você elimina 4, 6, 8, 10, etc, em toda a extensão da tabela. No final,
 * restam apenas números primos na tabela, os que não foram eliminados.
 * Esse método de encontrar números primos inventado a mais de dois milênios é extremamente eficiente e inspirou Kalen a
 * fazer o seu próprio crivo. Ao invés de iterar sobre todos os números, Kalen escolheu uma lista de números primos e
 * aplicou o método de eliminação na sua tabela. Ele chamou esse método de Crivo de Kalen.
 *
 * Ele chamou os números que restam na sua tabela de números kalimos, e ele ficou curioso para saber quantos números
 * seriam kalimos em uma tabela maior e com números primos diferentes para fazer a eliminação.
 *
 * Input
 *
 * A primeira linha é composta por três inteiros A e B (2≤A≤B≤10¹⁸), os limites do intervalo e N (1≤N≤15),
 * o tamanho do conjunto de números primos. Em seguida segue em uma linha N números primos distintos Pi (2≤Pi≤10¹⁸−11).
 * É garantido que o produto deles não excede 10¹⁸.
 *
 * Output
 * Imprima quantos números kalimos ficam depois da aplicação do Crivo de Kalen.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

llong A, B, N;
vector<llong> primes;

llong count_multiples(llong prime, llong start, llong end) {
    start = (start + prime - 1) / prime;
    end = end / prime;
    return end - start + 1;
}

llong solve(llong idx, llong selected, llong lcm) {
    if (lcm > B) return 0;
    if (idx == primes.size()) {
        if (selected == 0) return 0;
        llong multiples = count_multiples(lcm, A, B);
        return ((selected & 1) ? multiples : -multiples);
    }
    return solve(idx + 1, selected + 1, lcm / __gcd(lcm, primes[idx]) * primes[idx]) +
           solve(idx + 1, selected, lcm);
}

int main() {
    cin >> A >> B >> N;
    primes.resize(N);
    for (llong i = 0; i < N; i++)
        cin >> primes[i];

    llong total_numbers = B - A + 1;
    llong non_kalimos = solve(0, 0, 1);
    llong kalimos = total_numbers - non_kalimos;
    cout << kalimos << '\n';

    return 0;
}
