/**  A Primolândia é chamada de terra dos números primos, pois lá existe um número infinito deles. São números de diversos
  *  tamanhos, sendo que apenas uma fração muito pequena deles é popular em outros reinos da Inteirônia. Como eles não são
  *  muito de viajar, pois muitos deles tem gêmeos para cuidar, a hotelaria Hilbert propôs um pacote de viagens para
  *  habitantes da Primolândia:
  *
  *  "Junte K amigos consecutivos cujo produto não excede N e ganhe uma viagem de avião para as Ilhas Fractais!"
  *
  *  Os primos menores da ilha são bem mais populares e já viajaram bastante para todos os cantos da Inteirônia, então a
  *  sua missão é achar os maiores primos que podem usar essa promoção!
  *
  *  Input
  *
  *          A primeira linha contém um inteiro T (1≤T≤10³), a quantidade de casos de teste.
  *          Em seguida seguem T linhas, cada uma com um inteiro N (30≤N≤10^15) e um inteiro K (3≤K≤12).É garantido que
  *          existem pelo menos K primos consecutivos cujo produto não excede N.
  *
  *  Output
  *        Imprima o maior produto dos primos que podem aproveitar a promoção.
  **/

#include <bits/stdc++.h>

#define ullong unsigned long long

using namespace std;

const ullong MAXN = 1e7+5;

ullong t, k;
ullong n;
bool is_prime[MAXN];
vector<ullong> primes;

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (ullong i = 2; i*i < MAXN; i++) {
        if (is_prime[i]) {
            for (ullong j = i*i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (ullong i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    sieve();
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ullong ans = 1;
        for (ullong i = 0; i < primes.size(); i++) {
            ullong prod = 1;
            for (ullong j = i; j < i+k; j++) {
                prod *= primes[j];
            }
            if (prod > n) break;
            ans = max(ans, prod);
        }
        cout << ans << endl;
    }
    return 0;
}