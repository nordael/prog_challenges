#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> v, p(n+1);
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        p[x] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (p[i] < p[i-1]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}