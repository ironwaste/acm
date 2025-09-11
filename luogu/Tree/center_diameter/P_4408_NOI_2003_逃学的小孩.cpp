#include<bits/stdc++.h>
#include<climits>


#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define i64 long long
#define fi first
#define se second

#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/P4408
// 网址：
// 2025.09.10——14:46:09
// 2025.09.10——15:12:21 wa 一半
// 2025.09.10——15:14:48 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<pll>g[n + 1];
    for (int i = 0;i < m;i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }
    i64 c = 0;
    vector<i64>fa(n + 1, -1), dis(n + 1, 0), p;
    function<void(i64, i64)>dfs;
    dfs = [&](i64 u, i64 f)->void {
        for (auto& [v, w] : g[u]) {
            if (v == f)continue;
            dis[v] = dis[u] + w;
            fa[v] = u;
            if (dis[v] > dis[c]) { c = v; }
            dfs(v, u);
        }
        };
    dfs(1, 1);
    fa[c] = -1;
    dis[c] = 0;
    dfs(c, c);
    vector<i64>vis(n + 1, 0);
    for (int i = c;i != -1;i = fa[i]) {
        p.push_back(i);
        vis[i] = 1;
    }

    vector<i64>h(n + 1, 0), prew(n + 1, 0);
    i64 sz = p.size();
    for (int i = 0;i < sz - 1;i++) {
        i64 v1 = p[i], v2 = p[i + 1];
        function<void(i64, i64)>dh;
        dh = [&](i64 u, i64 f)->void {
            for (auto& [v, w] : g[u]) {
                if (u == v1 && v2 == v) {
                    prew[i + 1] = prew[i] + w;
                }
                if (vis[v] || v == f)continue;
                dh(v, u);
                h[u] = max(h[u], h[v] + w);
            }
            };
        dh(v1, v1);
    }
    i64 ans = 0;
    for (int i = 0;i < sz - 1;i++) {
        i64 v = min(prew[i], prew[sz - 1] - prew[i]);
        // i64 res = min(prew[i], prew[sz - 1] - prew[i]) + prew[sz - 1];
        i64 tmp = prew[sz - 1] + 2LL * h[p[i]];
        i64 k = v + h[p[i]] + prew[sz - 1];
        ans = max({ ans, tmp ,k });
    }
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}