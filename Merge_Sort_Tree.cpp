/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct MergeSortTree {
    int n;
    vector<ordered_set<pair<int, int>>> tree;
    MergeSortTree() {}
    MergeSortTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].insert({A[l], l});
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        for (int i = l; i <= r; i++) {
            tree[node].insert({A[i], i});
        }
    }
    void update(int node, int l, int r, int indx, int prev, int cur) {
        if (l == r) {
            tree[node].erase({prev, indx});
            tree[node].insert({cur, indx});
            return;
        }
        int mid = (l + r) / 2;
        if (l <= indx && indx <= mid) {
            update(2 * node, l, mid, indx, prev, cur);
        } else {
            update(2 * node + 1, mid + 1, r, indx, prev, cur);
        }
        tree[node].erase({prev, indx});
        tree[node].insert({cur, indx});
    }
    void update(int indx, int prev, int cur) {
        update(1, 1, n, indx, prev, cur);
    }
    int query(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return tree[node].order_of_key({val + 1, -1});
        }
        int mid = (l + r) / 2;
        int left = query(2 * node, l, mid, ql, qr, val);
        int right = query(2 * node + 1, mid + 1, r, ql, qr, val);
        return left + right;
    }
    int query(int ql, int qr, int val) {
        return query(1, 1, n, ql, qr, val);
    }
};

void solve() {
    int n, m, u;
    cin >> n >> m >> u;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    MergeSortTree mst(n);
    mst.build(1, 1, n, A);
    
    while (m--) {
        int l, r, v, p;
        cin >> l >> r >> v >> p;
        int k = mst.query(l, r, v - 1);
        int x = 1LL * u * k / (r - l + 1);
        mst.update(p, A[p], x);
        A[p] = x;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << A[i] << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}