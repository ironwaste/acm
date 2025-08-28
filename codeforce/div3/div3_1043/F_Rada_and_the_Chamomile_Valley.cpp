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

using pll = pair<i64, i64>;
// 补题——题目链接: https://codeforces.com/contest/2132/problem/F
// 网址：
// 2025.08.24——02:17:02 tle 3 是因为 vector的问题
// 2025.08.24——07:13:09 wa3 搞错输出了
// 2025.08.24——07:23:07 accpted TLE 14 ??!!
/*
 * 这题很熟悉啊 好像是杭电的一场里面有的
 * 就是求割点 杭电的是求树上覆盖种类 好像不一样
 * 然后求所有点到割点的最短路 即可
 * 太久 没写割点了 TT
 * 也就是从 1 to n 之间一定会经过的点
 *
 * 但是不会写的点在于 不知道如何判断该割点是在 1到n的
 * 简单路径上的
 *
 * 不对题目看错了  是求割边也就是桥  然后求桥是否在简单路径上
 *
 * 因为所有的简单路径都会经过割边  所以只要找到一条简单路径即可 
 */
const i64 N = 2e5 + 10;


void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<pll> >g(n + 1);
    vector<pll>edge(m + 1);
    for (int i = 1;i <= m;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back({ v,i });
        g[v].push_back({ u,i });
        edge[i] = { u,v };
    }
    i64 idx = 0;
    vector<i64>low(n + 1, 0), dfn(n + 1, 0), isb(m + 1, 0);
    vector<i64>spath(m + 1, 0), ansp(n + 1, 0), vvis(n + 1, 0);
    auto dfs = [&](auto self, i64 f, i64 u)->void {
        low[u] = dfn[u] = ++idx;
        for (auto [v, idm] : g[u]) {
            if (!dfn[v]) {
                self(self, u, v);
                low[u] = min(low[v], low[u]);
                if (low[v] > dfn[u]) { isb[idm] = 1; }
            } else if (f != v) {
                low[u] = min(low[u], low[v]);
            }
        }
        };
    dfs(dfs, 1, 1);
    i64 cnt = 0;
    auto dfs2 = [&](auto self, i64 f, i64 u)->i64 {
        vvis[u] = 1;
        if (u == n) {
            return 1;
        }
        for (auto [v,mid] : g[u]) {
            if (!vvis[v] && v != f) {
                vvis[v] = 1;
                ansp[cnt++] = mid;
                spath[mid]++;
                if (self(self, u, v))return 1LL;
                cnt--;
                spath[mid]--;
                // vvis[v] = 0;
            }
        }
        return 0LL;
        };
    dfs2(dfs2, 1, 1);
    queue<i64>q;
    vector<i64>vis(n + 1, 0), ans(n + 1, INT_MAX);
    for (i64 i = 1;i <= m;i++) {
        // de(i)deb(isb[i]);
        if (isb[i] == 1 && spath[i] == 1) {
            i64 u = edge[i].fi, v = edge[i].se;
            if (!vis[u]) {
                q.push(u );
                vis[u] = 1;
            }if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
            ans[v] = min(i,ans[v]);
            ans[u] = min(i,ans[u]);
        }
    }
    while (!q.empty()) {
        i64 u = q.front();
        q.pop();
        for (auto [v, idm] : g[u]) {
            if (!vis[v]) {
                ans[v] = min(ans[u], ans[v]);
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    i64 Q;
    cin >> Q;
    for (int i = 0;i < Q;i++) {
        i64 c;
        cin >> c;
        cout << ((ans[c] == INT_MAX) ? -1 : ans[c]) << " ";
    }cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}