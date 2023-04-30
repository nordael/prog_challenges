#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int L, N;
        cin >> L >> N;
        int minTime = 0, maxTime = 0;
        for (int i = 0; i < N; i++) {
            int pos;
            cin >> pos;
            minTime = max(minTime, min(pos, L - pos));
            maxTime = max(maxTime, max(pos, L - pos));
        }
        cout << minTime << " " << maxTime << endl;
    }
    return 0;
}
