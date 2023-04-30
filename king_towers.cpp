#include <bits/stdc++.h>

using namespace std;

template <typename _RAIter, typename _Compare>
void merge(_RAIter first, _RAIter middle, _RAIter last, _Compare cmp) {
    std::vector<typename std::iterator_traits<_RAIter>::value_type> buffer(std::distance(first, last));
    auto buffer_it = buffer.begin();

    auto left_it = first;
    auto right_it = middle;

    while (left_it != middle && right_it != last) {
        if (cmp(*left_it, *right_it)) {
            *buffer_it++ = std::move(*left_it++);
        } else {
            *buffer_it++ = std::move(*right_it++);
        }
    }

    buffer_it = std::move(left_it, middle, buffer_it);
    buffer_it = std::move(right_it, last, buffer_it);

    std::move(buffer.begin(), buffer_it, first);
}

template <typename _RAIter, typename _Compare>
void merge_sort(_RAIter first, _RAIter last, _Compare cmp) {
    const auto size = std::distance(first, last);
    if (size < 2) {
        return;
    }

    auto middle = std::next(first, size / 2);

    merge_sort(first, middle, cmp);
    merge_sort(middle, last, cmp);
    merge(first, middle, last, cmp);
}

typedef struct {
    long id;
    long height;
    char direction;
} Tower;

/*--------- Resolve  o problema das torres ----------------*/
int main() {
    int n;
    cin >> n;

    list<pair<int, char>> towers;
    for (int i = 0; i < n; i++) {
        long h; char c;
        cin >> h >> c;
        towers.push_back({h, c});
    }

    stack<pair<int, char>> st;
    for (auto it = towers.begin(); it != towers.end(); it++) {
        if (it->second == 'L') {
            if(st.empty() || st.top().first > it->first) {
                st.push({it->first, it->second});
            }else {
                cout << "N\n";
                return 0;
            }
        } else {
            if(st.empty()) {
                cout << "N\n";
                return 0;
            }else if( st.top().first < it->first) {
                cout << "N\n";
                return 0;
            } else if (st.top().first > it->first) {
                cout << "N\n";
                return 0;
            } else {
                st.pop();
            }
        }
    }

   if(st.empty()) cout << "S\n";
   else cout << "N\n";

   return 0;
}
