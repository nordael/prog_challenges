#include <iostream>
#include <stack>

/** O algoritmo utiliza uma pilha para manter uma lista de índices dos retângulos em ordem crescente de altura.
* Quando um novo retângulo é processado, o algoritmo verifica se ele tem altura menor do que o último retângulo na pilha.
* Se isso ocorrer, o algoritmo retira o último retângulo da pilha e calcula a área do retângulo que teria como altura a
* altura do retângulo retirado e como largura a distância entre o índice atual e o índice do novo último retângulo na
* pilha. O algoritmo atualiza o valor da maior área se a área do retângulo calculado for maior do que a maior área atual.
* Se o retângulo atual tem altura maior do que o último retângulo na pilha ou se a pilha está vazia, o algoritmo
* simplesmente adiciona o índice atual à pilha. Depois de processar todos os retângulos, o algoritmo retira todos os
* retângulos restantes da pilha e calcula a área dos retângulos usando a mesma lógica explicada anteriormente.
* Finalmente, o algoritmo imprime a maior área encontrada.

* Note que o algoritmo tem complexidade O(n), onde n é o número de retângulos no histograma, pois cada retângulo é
* inserido e retirado da pilha no máximo uma vez.
*/

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long h[n];
    for (long long i = 0; i < n; i++) {
        cin >> h[i];
    }

    stack<long long> s;
    long long max_area = 0;

    for (long long i = 0; i < n; i++) {
        while (!s.empty() && h[s.top()] > h[i]) {
            long long height = h[s.top()];
            s.pop();

            long long width;
            if (s.empty()) {
                width = i;
            } else {
                width = i - s.top() - 1;
            }

            long long area = height * width;
            if (area > max_area) {
                max_area = area;
            }
        }
        s.push(i);
    }

    while (!s.empty()) {
        long long height = h[s.top()];
        s.pop();

        long long width;
        if (s.empty()) {
            width = n;
        } else {
            width = n - s.top() - 1;
        }

        long long area = height * width;
        if (area > max_area) {
            max_area = area;
        }
    }

    cout << max_area << endl;

    return 0;
}
