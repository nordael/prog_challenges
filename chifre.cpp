#include <iostream>
#include <list>

using namespace std;

int main() {

    list<unsigned long> tape;
    long n;
    cin >> n;
    auto head = tape.begin(); // cabeça de leitura inicia na posição vazia

    for (long i = 0; i < n; i++) {
        char op;
        cin >> op;

        switch(op){
            case 'm': {
                long d;
                cin >> d;
                advance(head, d); // move a cabeça de leitura
            }break;
            case 'i': {
                unsigned long q, t;
                cin >> q >> t;

                // insere Q espaços com o número T na posição atual
                head = tape.insert(head, q, t);
            }break;
            case 'd': {
                // remove a posição atual
                head = tape.erase(head);
            }break;
            case 'q': {
                // imprime o número na posição atual
                cout << (*head) << endl;
            }break;
        }
    }

    return 0;
}