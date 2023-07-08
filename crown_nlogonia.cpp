/**
 * A Nlogônia ainda é dominada pela monarquia, mas felizmente com regras de sucessão simples. Em resumo há dois
 * aspectos para levar em consideração: "filhos vêm antes de irmãos" e "os mais velhos vêm antes dos mais novos".
 *
 * Os servos do reino mantêm uma linda e gigante tapeçaria onde a linhagem de Constante, o primeiro rei da Nlogônia, é
 * desenhada em forma de uma árvore. Sempre que um novo membro da família nasce um novo ramo do pai para o filho é
 * desenhado na tapeçaria. Este evento é tão importante que a lenda diz que quando um descendente de Constante tem um
 * filho ele não vai morrer até que o nome do seu filho seja desenhado na tapeçaria. Quando alguém morre, uma cruz é
 * desenhada perto do nome do falecido na tapeçaria. Quando o monarca morre, a tapeçaria é usada pelos servos para
 * determinar quem deve ser o novo monarca. Para que isso seja feito, os servos analisam a árvore iniciando pelo
 * Constante e atravessam os ramos de acordo com as regras descritas antes, "filhos vêm antes de irmãos" e
 * "os mais velhos vêm antes dos mais novos". Eles visitam cada nó da árvore iniciando pelo Constante, seguido pelo
 * filho mais velho de Constante, seguido pelo filho mais velho daquele filho, e assim por diante, até que encontram
 * alguma pessoa ainda viva, ou até que um membro da família não tenha filhos, e neste caso eles voltam para o pai
 * daquela pessoa e movem para o seu segundo filho, repetindo este processo até que um novo monarca seja encontrado.
 *
 * Depois de milhares de anos no poder, a linhagem de Constante é gigante. Manter a tapeçaria e, quando a hora chega,
 * determinar quem é o novo monarca são processos demorados e os servos Nlogonianos decidiram que está na hora de
 * modernizar. Eles querem escrever um programa que seja usado para manter a linhagem de Constante e que também possa
 * definir quem é o novo monarca quando o monarca anterior tragicamente morre. Dada a importância desta tarefa, os
 * servos da monarquia querem testar o programa garantindo que ele produza a saída correta para todos os eventos que
 * aconteceram até agora. Só existe um problema: nenhum deles é bom em programação. Por isso eles querem a sua ajuda.
 *
 * Mais tecnicamente, cada pessoa na linhagem de Constante vai ser representado por um identificador inteiro positivo
 * único. Sempre que um novo filho nasce, ele é atribuído o próximo menor inteiro único. O identificador de Constante
 * é o número 1, e inicialmente ele é a única pessoa viva. Você terá que processar vários eventos em ordem cronológica.
 * Sempre que uma pessoa morrer, você deve ajudar os servos a descobrirem quem é o atual monarca. É garantido que
 * sempre haverá alguém vivo para governar.
 *
 * Input
 * A primeira linha contém um inteiro Q(1≤Q≤10⁵), representando quantos eventos devem ser processados. As próximas Q
 * linhas conterão dois inteiros ti e xi cada, representando o tipo e o argumento do i-ésimo evento. Se ti é igual
 * a 1, então isso significa que a pessoa com identificador xi teve um filho. Se ti é igual a 2, então isso significa
 * que a pessoa com identificador xi morreu.
 *
 * Output
 * Para cada evento em que uma pessoa morre, você deve imprimir uma linha com um inteiro, representando o
 * identificador do monarca atual.
*/
#include <iostream>

#include <vector>

using namespace std;

vector<int> parent;
vector<int> ranks;

// Função para encontrar o representante (raiz) do conjunto
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Função para unir dois conjuntos
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (ranks[rootX] < ranks[rootY]) {
        parent[rootX] = rootY;
    } else if (ranks[rootX] > ranks[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        ranks[rootX]++;
    }
}

int main() {
    int Q;
    cin >> Q;

    parent.resize(Q + 2);
    ranks.resize(Q + 2);

    for (int i = 1; i <= Q + 1; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }

    int monarch = 1;

    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            unionSet(x, monarch);
        } else {
            monarch = find(x);
            cout << monarch << endl;
        }
    }

    return 0;
}
