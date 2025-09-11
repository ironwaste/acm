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

// 补题——题目链接: https://www.luogu.com.cn/problem/U89620
// 网址：
// 2025.09.10——12:03:37
/*
 *
 *
 *
*/

void solve() {
    i64 n, s;
    cin >> n >> s;
    vector<pll>g[n + 1];

    for (int i = 1;i < n;i++) {
        i64 v, u, w;
        cin >> u >> v >> w;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }

    vector<i64>fa(n + 1, -1), dis(n + 1, 0);
    i64 c = 0;
    function<void(i64, i64)>dfs;
    dfs = [&](i64 u, i64 f) ->void {
        // deb(u)
        for (auto& [v, w] : g[u]) {
            if (v == f)continue;
            fa[v] = u;
            dis[v] = dis[u] + w;
            dfs(v, u);
            if (dis[c] < dis[v]) { c = v; }
        }
        };
    dfs(1, 1);
    fa[c] = -1;
    dis[c] = 0;
    dfs(c, c);
    vector<i64>p, h(n + 1, 0), vis(n + 1, 0), prew(n + 1, 0);
    for (int i = c;i != -1;i = fa[i]) {
        p.push_back(i); vis[i] = 1;
    }
    i64 sz = p.size();
    for (int i = 0;i < sz - 1;i++) {
        i64 v1 = p[i], v2 = p[i + 1];

        function<void(i64, i64)>dh;
        dh = [&](i64 u, i64 f)->void {
            for (auto &[v, w] : g[u]) {
                if (u == v1 && v == v2) {
                    prew[i + 1] = prew[i] + w;
                }
                if (vis[v] || v == f)continue;
                dh(v, u);
                h[u] = max(h[v] + w, h[u]);
            }
            };
        dh(v1, v1);
        // de(sz)de(p[i])deb(h[p[i]]);
        // de(i + 1)de(prew[i])deb(prew[i + 1]);
    }
    prew[sz] = prew[sz - 1];
    i64 ans = LLONG_MAX;
    multiset<i64>q;
    // q.insert(h[p[0]]);
    for (int r = 0, l = 0;l < sz;) {
        while (r < l) { r++; }
        while (r < sz && prew[r] - prew[l] <= s) {
            q.insert(h[p[r++]]);
        }
        i64 ecc = max({ *q.rbegin(),prew[l], prew[sz] - prew[r - 1] });
        // ecc = max(*q.rbegin(), ecc);
        // set的 rebegin 返回的才是最大值
        // set 的 end 只是最后一个元素，不一定是最大值
        // de(*q.end())deb(ecc);
        ans = min(ans, ecc);
        q.extract(h[p[l++]]);
        
    }
    cout << ans << endl;
    
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