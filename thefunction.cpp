#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> memo;

long long f(long long n) {
    if (n == 0) {
        return 1;
    }
    if (memo.count(n)) {
        return memo[n];
    }
    long long res = f(n/2) + f(n/3);
    memo[n] = res;
    return res;
}

int main() {
    long long n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
