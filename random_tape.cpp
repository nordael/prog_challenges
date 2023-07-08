 /**
  *  @brief
  *  Humberto Iamarino pensou em outro novo modelo de Máquina de Turing. Nesta máquina, ele decidiu fazer com que ela
  *  fosse dotada de uma fita remendável e cada espaço desta fita guarda um número inteiro de 1 a 10⁹. O Computador de
  *  Humberto Iamarino com Fita Remendável de Acesso Aleatório (CHIFRAA) funciona da seguinte maneira:
  *
  *  Inicialmente, a cabeça da máquina aponta para uma fita vazia. Através da leitura das instruções da máquina ela decide
  *  então uma das ações a se tomar:
  *
  *  A máquina pode mover a cabeça de leitura na fita para a esquerda ou para a direita.
  *  Outra opção é retirar espaços da fita, por meio do corte dela e remendo do restante da fita.
  *
  *  Humberto já criou o sistema de instruções da máquina mas agora precisa da sua ajuda para fazer um sistema de
  *  controle da fita.
  *
  *  Input
  *
  *      A entrada é dada por uma linha contendo um inteiro N (1≤N≤10⁵), o tamanho da fita e Q (1≤N≤10⁵), o número de
  *      operações. Na segunda linha seguem N inteiros identificando o número Ti (0≤i<N,0≤Ti≤10⁹) escrito em cada
  *      posição da fita. Nas próximas Q linhas seguem as operações, e cada operação é identificada por um caractere:
  *
  *      'm' indica que a cabeça de leitura precisa mover D (−(10⁵−1)≤D≤(10⁵−1),D≠0) espaços para direita (positivos) ou
  *      para esquerda (negativos). É garantido que a cabeça se move para uma posição válida.
  *      'd' indica que a máquina quer cortar uma posição da posição atual. É garantido que a fita não está vazia e
  *      que a cabeça aponta para uma posição válida.
  *      'q' é uma requisição para verificar qual número está na cabeça de leitura.
  *
  *      É garantido que a fita não está vazia e que a cabeça aponta para uma posição válida.
  *
  *  Output
  *      Para cada operação 'q', imprima qual número está na cabeça de leitura na mesma ordem da entrada.
  *      @todo otimizar o algoritmo: apagar um item de vector é muito custoso se frequentemente necessárioe
  **/

#include <bits/stdc++.h>

#define ullong unsigned long long

 using namespace std;

 int main() {
     string line;
     ullong n, q;

     cin >> n >> q;

     // Lê os valores da fita
     multimap<ullong, ullong> fita;
     vector <ullong> tape;

     ullong ti = 0, i = 0;
     while (i++ < n) {
         cin >> ti;
         tape.push_back(i);
         fita.insert(make_pair(i, ti));
     }

     // Posiciona a cabeça de leitura na primeira posição da fita
     auto head = fita.begin();
     auto pos = tape.begin();

     // Processa as operações
     while (q--) {
         char op;
         cin >> op;

         switch (op) {
             case 'm':{
                 ullong D;
                 cin >> D;
                 pos += D;
                 head = fita.find(*pos);
             } break;
             case'd': {
                 head = fita.erase(head);
                 pos = tape.erase(pos);
             } break;
             case 'q': {
                 cout << head->second << endl;
             } break;
         }
     }

     return 0;
 }

