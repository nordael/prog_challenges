#include <bits/stdc++.h>

using namespace std;
//
//const int MAXN = 1e6 + 5;
//
//bitset<MAXN> is_composite;
//vector<long long> primes;
//
//// função para gerar os números primos menores que sqrt(B)
//void generate_primes(long long B) {
//    is_composite[0] = is_composite[1] = true;
//    for (long long i = 2; i <= B; i++) {
//        if (!is_composite[i]) {
//            primes.push_back(i);
//            if (i * i <= B) {
//                for (long long j = i * i; j <= B; j += i) {
//                    is_composite[j] = true;
//                }
//            }
//        }
//    }
//}
//
//// função para eliminar os múltiplos dos primos da lista
//void sieve(long long A, long long B, const vector<long long>& factors, vector<bool>& is_kalimo) {
//    is_kalimo.resize(B - A + 1, true);
//    for (long long p : factors) {
//        long long start = ((A + p - 1) / p) * p; // primeiro múltiplo de p em [A, B]
//        for (long long j = start; j <= B; j += p) {
//            is_kalimo[j - A] = false;
//        }
//    }
//}
//
//int main() {
//    long long A, B;
//    int N;
//    cin >> A >> B >> N;
//
//    generate_primes(sqrt(B));
//
//    vector<long long> factors(N);
//    for (int i = 0; i < N; i++) {
//        cin >> factors[i];
//    }
//
//    vector<bool> is_kalimo;
//    sieve(A, B, factors, is_kalimo);
//
//    int count_kalimo = count(is_kalimo.begin(), is_kalimo.end(), true);
//
//    cout << count_kalimo << endl;
//
//    return 0;
//}

// Abordagem 2
//
//unordered_set<long long> factors;
//
//// função para fatorar um número em primos
//void factorize(long long x) {
//    for (long long i = 2; i * i <= x; i++) {
//        while (x % i == 0) {
//            factors.insert(i);
//            x /= i;
//        }
//    }
//    if (x > 1) {
//        factors.insert(x);
//    }
//}
//
//// função para eliminar os múltiplos dos fatores primos
//void sieve(long long A, long long B, const unordered_set<long long>& factors, vector<bool>& is_kalimo) {
//    is_kalimo.resize(B - A + 1, true);
//    for (long long x = A; x <= B; x++) {
//        bool is_kalimo_x = true;
//        for (long long p : factors) {
//            if (x % p == 0) {
//                is_kalimo_x = false;
//                break;
//            }
//        }
//        is_kalimo[x - A] = is_kalimo_x;
//    }
//}
//
//int main() {
//    long long A, B;
//    int N;
//    cin >> A >> B >> N;
//
//    for (int i = 0; i < N; i++) {
//        long long p;
//        cin >> p;
//        factorize(p);
//    }
//
//    vector<bool> is_kalimo;
//    sieve(A, B, factors, is_kalimo);
//
//    int count_kalimo = count(is_kalimo.begin(), is_kalimo.end(), true);
//
//    cout << count_kalimo << endl;
//
//    return 0;
//}

//#define MAX 1000000000ULL
//
//using namespace std;
//
//int main() {
//    unsigned long long A, B;
//    int N;
//    cin >> A >> B >> N;
//
//    vector<unsigned long long> primes(N);
//    for (int i = 0; i < N; i++) {
//        cin >> primes[i];
//    }
//
//    vector<bitset<MAX>>bs(MAX);
//    for (int i = 0; i < bs.size(); i++) {
//        bs[i].set();
//    }
//    bs[0].reset(0); bs[0].reset(1); // 0 e 1 não são primos
//
//    for (int i = 0; i < N; i++) {
//        unsigned long long p = primes[i];
//        unsigned long long start = ((A + p - 1) / p) * p; // primeiro múltiplo de p no intervalo [A, B]
//        if (start == p) start += p; // evita marcar p como composto
//        long k = 0;
//        for (unsigned long long j = start; j <= B; j += p) {
//            k = (j-A) > MAX ? k+1 : k;
//            bs[k].reset((j - A)%MAX); // marca o múltiplo como composto
//        }
//    }
//
//    unsigned long long count = 0;
//    for (long j,k, i = A; i <= B; i++) {
//        k = (i-A) > MAX ? k+1 : k;
//        j = (i-A)%MAX;
//        if (bs[k].test(j)) {
//            count++;
//        }
//    }
//
//    cout << count << endl;
//
//    return 0;
//}


////ABordagem 3
int main() {
    unsigned long long A, B;
    int N;
    cin >> A >> B >> N;

    unsigned long long mask = 0;
    vector<unsigned long long> primes(N);

    for (int i = 0; i < N; i++) {
        cin >> primes[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        // primeiro múltiplo de p no intervalo [A, B]
        unsigned long long start =
                ((A + primes[i] - 1) / primes[i]) * primes[i];

        if (start == primes[i]) {
            // evita marcar primes[i]como composto
            start += primes[i];
        }
        unsigned long long k = 0, l = 0;
        while (start <= B) {
            mask |= 1ULL << (start - A)%64; // marca o múltiplo como composto
            start += primes[i];

            k |= 1ULL << ++l;
            if(k <= 63 && start > B){
                for (unsigned long long j = A; j <= B; j++) {
                    // testa se o bit correspondente ao número é 0, ou seja, se o número é primo
                    if ((mask & (1ULL << (j - A)%64)) == 0) {
                        count++;
                    }
                }
                mask = 0;
            }
        }
    }

//    int count = 0;
//    for (unsigned long long i = A; i <= B; i++) {
//        // testa se o bit correspondente ao número é 0, ou seja, se o número é primo
//        if ((mask & (1ULL << (i - A))) == 0) {
//            count++;
//        }
//    }

    cout << count << endl;

    return 0;
}