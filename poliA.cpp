#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string verbo;
    cin >> n >> verbo;

    // Verifica a terminação do verbo
    string terminacao = "";
    int tamanho = verbo.size();

    switch(verbo[tamanho-1]) {
        case 'i':
            terminacao = "i";
            break;
        case 'u':
            terminacao = "u";
            break;
        case 's':
            switch(verbo[tamanho-2]) {
                case 'i':
                    terminacao = "is";
                    break;
                case 'a':
                    terminacao = "as";
                    break;
                case 'o':
                    terminacao = "os";
                    break;
                case 'u':
                    terminacao = "us";
                    break;
            }
            break;
    }

    // Imprime a terminação
    cout << terminacao << endl;
    return 0;
}
