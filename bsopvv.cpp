#include <bits/stdc++.h>
using namespace std;

/*
 * Um número N é dito Bonito Se Observado do Ponto de Vista Volumétrico (BSOPVV) quando existem três números
 * longeiros A,B e C de raízes longeiras tais que 1≤A≤B≤C≤N² e √A+√B+√C=N. Além disso, os jovens dizem que A,B e C
 * são uma Tripla Top de N quando estas condições são satisfeitas.
 */

int main() {
    long n;
    cin >> n;
    long top_triple = 0;
    for (long a = 1; a <= n; a++) {
        for (long b = a; b <= n; b++) {
            long c = abs(a + b - n);
            if(b >= a && c >= b && c <= n && (a + b + c) == n){
                top_triple++;
            }
        }
    }
    cout << top_triple << endl;
    return 0;
}
