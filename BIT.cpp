/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

template<typename T>
struct BIT {
    int n;
    std::vector<T> tree;
    BIT() {}
    BIT(int _n) {
        n = _n;
        tree.resize(n + 1);
    }
    void update(int i, T val) {
        if(i <= 0) return;
        while(i <= n) {
            tree[i] += val;
            i += (i & -i);
        }
    }
    void update(int i, int j, T val) {
        if(i > j) return;
        update(i, val);
        update(j + 1, -val);
    }
    T query(int i) const {
        T ans = 0;
        while(i > 0) {
            ans += tree[i];
            i -= (i & -i);
        }
        return ans;
    }
    T query(int l, int r) const {
        if(l > r || l == 0) return T(0);
        return query(r) - query(l - 1);
    }
};


void solve() {
    int n;
    cin >> n;
    BIT<int> bit(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}