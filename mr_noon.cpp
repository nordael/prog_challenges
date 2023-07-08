 /**
 * @brief
 * Seu Madruga finalmente arrumou um emprego, é sua grande chance de pagar os 14 meses de aluguel que estão atrasados.
 * Seu cargo é o de cortador de papel e o salário é excelente.
 *
 * Madruga irá receber N tiras retangulares de papel com 1cm de largura e C cm de comprimento.
 * As tiras devem ser colocadas uma ao lado da outra de forma que suas bases estejam alinhadas. A tarefa de seu
 * Madruga será, com apenas um corte em linha reta, paralelo à base, fazer com que a soma das áreas das tiras cortadas
 * seja igual a Acm².
 *
 * Veja a ilustração abaixo com N=5 e as tiras com 5, 3, 6, 2 e 3cm de comprimento, respectivamente,
 * para um A=3cm².
 *
 * Com um corte feito a uma altura de 4 cm em relação a base, a área resultante, pintada de vermelho, é exatamente
 * igual a Acm2. Sua tarefa é descobrir essa altura H e ajudar Seu Madruga a se manter no emprego.
 *
 * Input
 *
 *         Haverá diversos casos de testes. A primeira linha de cada caso inicia com dois inteiros N(1≤N≤10⁵) e
 *         A (1≤A≤10⁹) representando, respectivamente, a quantidade de tiras e a área resultante esperada. A próxima
 *         linha conterá N inteiros, representando o comprimento Ci (1≤Ci≤10⁴) de cada tira.
 *
 * A entrada termina com N=A=0 , a qual não deve ser processada.
 *
 * Output
 *
 *         Para cada caso, exiba uma única linha, a altura H do corte que Seu Madruga deve fazer para que a soma da
 *         área das tiras cortadas seja igual a A cm². Use 4 casas decimais após o ponto. Será tolerada uma
 *         diferença de 10−5. Exiba :D, caso nenhum corte seja necessário, ou -.- caso seja impossível.
 */

#include <bits/stdc++.h>
using namespace std;

#define ullong unsigned long long

const double EPS = 1e-5; // tolerância para diferenças numéricas

double calculate_cut_height(const vector<ullong>& strips, ullong A) {
    ullong N = strips.size();
    double total_area = 0;
    for (ullong i = 0; i < N; i++) {
        total_area += strips[i];
    }
    if (total_area < A) {
        return -1; // não é possível encontrar altura de corte
    }
    double low = 0, high = *max_element(strips.begin(), strips.end()); // limites iniciais da busca binária
    while (fabs(high - low) > EPS) { // enquanto a diferença entre os limites não for insignificante
        double mid = (low + high) / 2; // altura do corte atual
        double cut_area = 0;
        for (ullong i = 0; i < N; i++) {
            if (strips[i] > mid) {
                cut_area += (strips[i] - mid);
            }
        }
        if (cut_area > A) {
            low = mid; // altura do corte precisa ser aumentada
        } else {
            high = mid; // altura do corte precisa ser diminuída
        }
    }
    return low; // a altura do corte encontrada é a menor possível
}

int main() {
    ullong N, A;
    while (cin >> N >> A && N != 0 && A != 0) {
        vector<ullong> strips(N);
        for (ullong i = 0; i < N; i++) {
            cin >> strips[i];
        }
        double cut_height = calculate_cut_height(strips, A);
        if (cut_height < 0) {
            cout << "-.-" << endl; // não é possível encontrar altura de corte
        } else if (cut_height == 0){
            cout << ":D" << endl; // nenhum corte é necessário
        } else {
            cout.precision(4);
            cout << fixed << cut_height << endl;
        }
    }
    return 0;
}
