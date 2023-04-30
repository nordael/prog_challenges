#include <bits/stdc++.h>

using namespace std;

struct Vaca {
    int leite, tempo;
};

//bool cmp(Vaca a, Vaca b) {
//    return a.tempo < b.tempo;
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<Vaca> vacas(n);
//    for (int i = 0; i < n; i++) {
//        cin >> vacas[i].leite >> vacas[i].tempo;
//    }
//
//    sort(vacas.begin(), vacas.end(), cmp);
//
//    int tempo_decorrido = 0, leite_total = 0;
//    for (int i = 0; i < n; i++) {
//        long best = i, j = i+1;
//        while(j < n &&  vacas[i].tempo == vacas[j].tempo && vacas[j].tempo > tempo_decorrido) {
//            if (vacas[i].leite <= vacas[j].leite){
//                best = j;
//            } else {
//                best = i;
//            }
//            j++;
//        }
//
//        i = j-1;
//        if (vacas[best].tempo > tempo_decorrido) {
//            tempo_decorrido++;
//            leite_total += vacas[best].leite;
//        }
//    }
//
//    cout << leite_total << endl;
//
//    return 0;
//}


bool cmp(Vaca a, Vaca b) {
    if (a.tempo == b.tempo) {
        return a.leite > b.leite;
    }
    return a.tempo < b.tempo;
}

int main() {
    int n;
    cin >> n;

    vector<Vaca> vacas(n);
    for (int i = 0; i < n; i++) {
        cin >> vacas[i].leite >> vacas[i].tempo;
    }

    sort(vacas.begin(), vacas.end(), cmp);

    int tempo_decorrido = 0, leite_total = 0;
    for (int i = 0; i < n; i++) {

        if (vacas[i].tempo > tempo_decorrido) {
            tempo_decorrido++;
            leite_total += vacas[i].leite;
        }
    }

    cout << leite_total << endl;

    return 0;
}