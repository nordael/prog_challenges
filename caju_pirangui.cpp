#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> regioes(n);
    for (int i = 0; i < n; i++) {
        cin >> regioes[i];
    }

    int cajus_coletados = 0;

    for (int i = 0; i < n; i++) {
        if (regioes[i] <= 10) {
            continue;
        }

        cajus_coletados += regioes[i] - 10;
    }

    cout << cajus_coletados << endl;

    return 0;
}

