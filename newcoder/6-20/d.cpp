#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using i64 = long long;

struct Trie {
    struct node {
        std::array<int, 2> son;

        node() : son{} {}
    };

    std::vector<node> t;

    Trie() {
        init();
    }

    void init() {
        t.assign(1, node());
    }

    int newnode() {
        t.emplace_back();
        return t.size() - 1;
    }

    void insert(const int &val) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int ne = val >> i & 1;
            if (t[p].son[ne] == 0) {
                t[p].son[ne] = newnode();
            }
            p = t[p].son[ne];
        }
    }

    int query(const int &val) {
        int p = 0, ans = 0;
        for (int i = 30; i >= 0; i--) {
            int ne = val >> i & 1;
            if (t[p].son[ne ^ 1]) {
                ans |= 1 << i;
                p = t[p].son[ne ^ 1];
            } else {
                p = t[p].son[ne];
            }
        }
        return ans;
    }
};

void DAOQI() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Trie trie;
    std::vector<int> ans(n + 1);
    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        ans[u] = std::max(ans[u], trie.query(a[u]));
        for (int v: adj[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
        }
        trie.insert(a[u]);
    };
    dfs(dfs, 1, 1);

    for (int i = 1; i <= n; i++) {
        reverse(all(adj[i]));
    }
    trie.init();
    dfs(dfs, 1, 1);
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    //std::cin >> T;
    while (T--) DAOQI();
    return 0;
}

