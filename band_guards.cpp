/*
 * Inicie um contador de guardas em 0
 * Percorra a sequência S da esquerda para a direita:
 * Se encontrar uma parede, avance para a próxima posição
 * Se encontrar uma abertura, coloque um guarda na posição atual e avance três posições (para garantir que haverá pelo menos 90cm protegidos)
 * Adicione 1 ao contador de guardas
 * Imprima o identificador do caso e o valor do contador de guardas
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string s;
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '#') continue;
            cnt++;
            j += 2;
        }
        cout << "Caso " << i << ": " << cnt << endl;
    }
    return 0;
}

