/**
* Uma sequência de parênteses correta é uma sequência de caracteres que satisfaz uma das seguintes condições:
 * É uma sequência vazia.
 * É uma concatenação de '(', A e ')', nesta ordem, para algum sequência de parênteses correta A.
 * É uma concatenação de A, B, nesta ordem, para algumas sequências de parênteses corretas A e B.
 *
 * Nós temos uma sequência S de tamanho N consistindo de '(' e ')'. Responda as Q consultas de troca de caracteres
 * e verificação das subsequências.
 *
 * Input
 * A primeira linha da entrada contém um inteiro N (1≤N≤2⋅10⁵), o tamanho da sequência de parênteses e um inteiro
 * Q (1≤Q≤2⋅10⁵). A segunda linha contém a sequência S que consiste apenas de caracteres '(' e ')'. Em seguida
 * seguem Q consultas, uma em cada linha, onde casa linha é composta pelos inteiros T (1≤T≤2), L e R (1≤L,R≤N).
 * Quando a consulta tem T=1, significa que é pedido que o caractere L e o caractere R da sequência S sejam trocados.
 * Se a consulta tem T=2, então é necessário determinar se a substring [L,R] de S é uma sequência de parênteses válida.
 *
 * Output
 * Para cada consulta T=2, imprima 'Yes' se a substring [L,R] for válida ou 'No', se não for válida.
*/

//#include <bits/stdc++.h>
//using namespace std;
//
//bool isValid(string &str, int L, int R) {
//    stack<char> st;
//    for (int i = L; i <= R; i++) {
//        if (str[i] == '(')
//            st.push(str[i]);
//        else {
//            if (st.empty())
//                return false;
//            st.pop();
//        }
//    }
//    return st.empty();
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int N, Q;
//    cin >> N >> Q;
//
//    string S;
//    cin >> S;
//    S = " " + S;
//
//    while (Q--) {
//        int T, L, R;
//        cin >> T >> L >> R;
//
//        if (T == 1) {
//            swap(S[L], S[R]);
//        }
//        else {
//            if (isValid(S, L, R))
//                cout << "Yes\n";
//            else
//                cout << "No\n";
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int open;
    int closed;
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    void build(const string& s, int v, int tl, int tr) {
        if (tl == tr) {
            if (s[tl - 1] == '(') {
                tree[v].open = 1;
                tree[v].closed = 0;
            } else {
                tree[v].open = 0;
                tree[v].closed = 1;
            }
        } else {
            int tm = (tl + tr) / 2;
            build(s, v * 2, tl, tm);
            build(s, v * 2 + 1, tm + 1, tr);
            int matched = min(tree[v * 2].open, tree[v * 2 + 1].closed);
            tree[v].open = tree[v * 2].open + tree[v * 2 + 1].open - matched;
            tree[v].closed = tree[v * 2].closed + tree[v * 2 + 1].closed - matched;
        }
    }

    void update(int v, int tl, int tr, int pos, char newChar) {
        if (tl == tr) {
            if (newChar == '(') {
                tree[v].open = 1;
                tree[v].closed = 0;
            } else {
                tree[v].open = 0;
                tree[v].closed = 1;
            }
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, newChar);
            } else {
                update(v * 2 + 1, tm + 1, tr, pos, newChar);
            }
            int matched = min(tree[v * 2].open, tree[v * 2 + 1].closed);
            tree[v].open = tree[v * 2].open + tree[v * 2 + 1].open - matched;
            tree[v].closed = tree[v * 2].closed + tree[v * 2 + 1].closed - matched;
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return {0, 0};
        }
        if (tl == l && tr == r) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        Node left = query(v * 2, tl, tm, l, min(r, tm));
        Node right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        int matched = min(left.open, right.closed);
        return {left.open + right.open - matched, left.closed + right.closed - matched};
    }

public:
    SegmentTree(const string& s) {
        n = s.size();
        tree.resize(4 * n);
        build(s, 1, 1, n);
    }

    void swapCharacters(int pos) {
        if (tree[1].open == 1) {
            update(1, 1, n, pos, ')');
        } else {
            update(1, 1, n, pos, '(');
        }
    }

    bool isValid(int l, int r) {
        Node result = query(1, 1, n, l, r);
        return (result.open == 0 && result.closed == 0);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    SegmentTree segmentTree(S);

    for (int i = 0; i < Q; i++) {
        int T, L, R;
        cin >> T >> L >> R;
        if (T == 1) {
            segmentTree.swapCharacters(L);
        } else if (T == 2) {
            if (segmentTree.isValid(L, R)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}

