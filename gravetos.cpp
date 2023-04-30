#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int n;
int p[MAXN];

long long cost(int len) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(p[i]-len);
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p+n);
    int lo = 1, hi = p[n-1];
    long long ans = LLONG_MAX;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        long long cur = cost(mid);
        ans = min(ans, cur);
        if (cost(mid-1) < cur) {
            hi = mid-1;
        } else if (cost(mid+1) < cur) {
            lo = mid+1;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

//int main() {
//
//    long n;
//    cin >> n;
//
//    vector<long> heights(n);
//    long median = 0;
//
//    for (int i = 0; i < n; i++) {
//        cin >> heights[i];
//        median += heights[i];
//    }
//    median /= n;
//
//    long cost = 0;
//    for (int i = 0; i < n; i++) {
//        cost += abs(heights[i] - median);
//    }
//
//    cout << cost << endl;
//    return 0;
//}
