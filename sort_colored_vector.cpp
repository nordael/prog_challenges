#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX_COLORS = 200000;

int main() {
    long long n;
    cin >> n;

    vector<long long> count(MAX_COLORS+1, 0);
    vector<pair<long long, long long>> v(n);
    for (long long i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        count[v[i].second]++;
    }

    for (long long i = 1; i <= MAX_COLORS; i++) {
        count[i] += count[i-1];
    }

    vector<pair<long long, long long>> sorted_v(n);
    for (long long i = n-1; i >= 0; i--) {
        sorted_v[--count[v[i].second]] = v[i];
    }

    bool sorted = true;
    for (long long i = 1; i < n; i++) {
        if (sorted_v[i-1].first > sorted_v[i].first) {
            if (sorted_v[i-1].second == sorted_v[i].second) {
                sorted = false;
                break;
            }
        }
    }

    if (sorted) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
