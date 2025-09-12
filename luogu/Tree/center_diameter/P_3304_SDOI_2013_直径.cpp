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

// 补题——题目链接: https://www.luogu.com.cn/problem/P3304
// 网址：
// 2025.09.12——07:52:08
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<pll>g[n + 1];
    for (int i = 1;i < n;i++) {
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
            fa[v] = u;
            dis[v] = dis[u] + w;
            if (dis[v] > dis[c])c = v;
            dfs(v, u);
        }
        };
    dfs(1, 1);
    fa[c] = -1;
    dis[c] = 0;
    dfs(c, c);
    i64 dia = 0;
    for (i64 st = c;st != -1;st = fa[st]) { p.push_back(st); }
    vector<i64>h(n + 1, 0), prew(n + 1, 0);

    i64 sz = p.size();
    for (i64 i = 0;i < sz - 1;i++) {
        i64 v1 = p[i], v2 = p[i + 1];
        function<void(i64, i64)>dh;
        dh = [&](i64 u, i64 f)->void {
            for (auto& [v, w] : g[u]) {
                if (u == v1 && v2 == v) {
                    dia += w;
                    prew[i + 1] = prew[i] + w;
                    continue;
                }if (v == f || (i > 0 && v == p[i-1]))continue;
                dh(v, u);
                h[u] = max(h[u], h[v] + w);
            }
            };
        dh(v1, v2);
    }
    i64 idx1 = 0, idx2 = sz - 1;
    for (i64 i = 0;i < sz - 1;i++) {
        i64 v1 = p[i], v2 = p[i + 1];
        if (prew[i + 1] == h[v2]) { idx1 = i + 1; }
    }
    for (i64 i = sz - 1;i;i--) {
        i64 v1 = p[i], v2 = p[i - 1];
        if (prew[sz - 1] - prew[i - 1] == h[v2]) {
            idx2 = i - 1;
        }
    }
    
    cout << dia << endl << max(0LL, idx2 - idx1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}