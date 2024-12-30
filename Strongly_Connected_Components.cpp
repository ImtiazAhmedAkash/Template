/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Strongly Connected Components

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n, vector<int>());
    vector invG(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        invG[v].push_back(u);
    }
    
    vector<bool> used(n, false);
    vector<int> order;
    auto topo_sort = [&](auto&& self, int u) -> void {
        used[u] = true;
        for (auto &v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
        order.push_back(u);
    };
    
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            topo_sort(topo_sort, i);
        }
    }
    reverse(order.begin(), order.end());
    
    vector<vector<int>> ans;
    vector<int> cur;
    fill(used.begin(), used.end(), false);
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        cur.push_back(u);
        for (auto &v : invG[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (!used[order[i]]) {
            cur.clear();
            dfs(dfs, order[i]);
            ans.push_back(cur);
        }
    }
    
    cout << ans.size() << nl;
    for (auto &v : ans) {
        cout << v.size() << " ";
        for (auto &x : v) {
            cout << x << " ";
        }
        cout << nl;
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