#include <bits/stdc++.h>
using namespace std;

// 1-based indexing
template <typename T>
struct SparseTable {
    vector<vector<T>> table;

    void build(const vector<T>& V) {
        int n = V.size();
        table.assign(n + 1, vector<T>(18));  // adjust the value 18 as (log(n) + 1)
        for (int i = 1; i <= n; i++) {
            table[i][0] = V[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) const {
        int k = __lg(r - l + 1);
        return min(table[l][k], table[r - (1 << k) + 1][k]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    SparseTable<int> st;
    st.build(A);

    while (q--) {
        int l, r;
        cin >> l >> r;  // 1-based indexing
        cout << st.query(l, r) << '\n';
    }

    return 0;
}