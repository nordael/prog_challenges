#include <bits/stdc++.h>

using namespace std;

int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<int> red(A), green(B), colorless(C);
    for (int i = 0; i < A; i++) {
        cin >> red[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> green[i];
    }
    for (int i = 0; i < C; i++) {
        cin >> colorless[i];
    }

    sort(red.rbegin(), red.rend()); // ordena em ordem decrescente
    sort(green.rbegin(), green.rend()); // ordena em ordem decrescente

    vector<int> chosen;
    for (int i = 0; i < X; i++) {
        chosen.push_back(red[i]);
    }
    for (int i = 0; i < Y; i++) {
        chosen.push_back(green[i]);
    }
    for (int i = 0; i < C; i++) {
        chosen.push_back(colorless[i]);
    }

    sort(chosen.rbegin(), chosen.rend()); // ordena em ordem decrescente

    long long sum = 0;
    for (int i = 0; i < X + Y; i++) {
        sum += chosen[i];
    }

    cout << sum << endl;

    return 0;
}
