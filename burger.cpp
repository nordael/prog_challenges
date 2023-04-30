#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int p, h, f, d, c;
        cin >> p >> h >> f >> d >> c;

        int max_chicken = min(p / 2, f);
        int max_cheddar = min(p / 2, h);

        int profit_chicken = max_chicken * c;
        int profit_cheddar = max_cheddar * d;

        if (c >= d) {
            max_cheddar = min((p-max_chicken*2) / 2, h);
            profit_cheddar = max_cheddar * d;
        } else {
            max_chicken = min((p-max_cheddar*2) / 2, f);
            profit_chicken = max_chicken * c;
        }

        int total_profit = profit_chicken + profit_cheddar;

        cout << total_profit << endl;
    }

    return 0;
}

