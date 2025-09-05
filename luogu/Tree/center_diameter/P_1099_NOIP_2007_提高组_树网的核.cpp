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

// 补题——题目链接: https://www.luogu.com.cn/problem/P1099
// 网址：
// 2025.09.04——07:57:34
// 2025.09.04——09:29:43 wa了 并且多种错误
/*
 *
 * 树的直径
 *
*/

void solve() {
    i64 n, s;
    cin >> n >> s;
    vector<pll>E[n + 1];
    map<pll, i64>mp;
    for (int i = 1;i < n;i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }
    i64 root = 1;
    vector<i64>fa(n + 1, 0), h(n + 1, 0), far(n + 1, 0);
    vector<i64>path;
    function<i64(i64, i64)>dfs;
    dfs = [&](i64 u, i64 f)->i64 {
        // fa[u] = f;
        
        for (auto [v, w] : E[u]) {
            if (v == f)continue;
            fa[v] = u;
            far[v] = far[u] + w;
            if (far[v] > far[root]) { root = v; }

            dfs(v, u);
            // if (far[v] > far[root]) { root = v; }
        }
        return far[root];
        };
    dfs(1, 1);
    far[root] = 0;
    fa[root] = -1;
    dfs(root, -1);
    vector<i64>vis(n + 1, 0);
    i64 sz = 0,sum =0 ;
    for (i64 st = root;st != -1;st = fa[st]) {
        path.push_back(st);
        vis[st] = 1;
        sz++;
    }
    function<void(i64, i64)>hdfs;
    hdfs = [&](i64 u, i64 f)->void {
        for (auto [v, w] : E[u]) {
            if (vis[v] || v == f)continue;
            hdfs(v, u);
            h[u] = max(h[u], h[v] + w);
        }
        };
    for (auto u : path) { hdfs(u, u); }
    i64 ans = LLONG_MAX;
    vector<i64>prew(sz, 0);
    for (int i = 1;i < sz;i++) {
        i64 u = path[i], vv = path[i - 1];
        for (auto [v , w] : E[u]) {
            if (v == vv) { sum += w; prew[i] = w + prew[i-1]; break; }
        }
    }

    for (i64 l = 0, r = 0;l < sz && r < sz;l ++) {
        while (r + 1 < sz && prew[r + 1] - prew[l] <= s ) {
            r++;
        }
        // de(l)
        //     de(r)de(path[l])de(path[r]);
        // de(prew[sz - 1] - prew[r]);
        // de(prew[l]);
        i64 ecc = max(prew[sz - 1] - prew[r], prew[l]);
        for (int i = l;i <= r;i++) {
            ecc = max(ecc, h[path[i]]);
        }
        ans = min(ans, ecc);
        // deb(ans);
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