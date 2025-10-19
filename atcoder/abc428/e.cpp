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

// 补题——题目链接: https://atcoder.jp/contests/abc428/tasks/abc428_e
// 网址：
// 2025.10.19——12:03:57
/*
 *
 * 树求直径
*/



void solve() {
    i64 n;
    cin >> n;
    vector<vector<i64> >g(n + 1);
    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        // u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // auto dfs = [&](auto dfs,i64 u,i64 f)
    vector<i64>fa(n + 1, 0), dis(n + 1, 0);
    vector<pll>diss(n + 1, { 0,0 });
    vector<i64>path;
    i64 c = 0;
    auto dfs = [&](auto dfs, i64 u, i64 f)->void {
        for (auto v : g[u]) {
            if (v == f) { continue; }
            fa[v] = u;
            dis[v] = dis[u] + 1;
            if (dis[c] < dis[v]) {
                c = v;
            } else if (dis[c] == dis[v]) {
                c = max(c, v);
            }
            dfs(dfs,v, u);
        }
        };
    dfs(dfs,1, 1);
    i64 fic = c;
    fa[c] = -1;
    dis[c] = 0;
    dfs(dfs,c, c);
    i64 sec = c;

    auto dfs1 = [&](auto dfs1, i64 u, i64 f,i64 dd,i64 dv)->void {
        for (auto v : g[u]) {
            if (v == f)continue;
            fa[v] = u;
            auto [d, pv] = diss[v];
            if (dd > d) {
                diss[v] = { dd,dv };
            } else if (dd == d && dv > pv) {
                diss[v] = { dd,dv };
            }
            dfs1(dfs1, v, u, dd + 1, dv);
        }
        };
    dfs1(dfs1, sec, sec, 0, sec);
    dfs1(dfs1, fic, fic, 0, fic);
    for (int i = 1;i <= n;i ++ ) {
        cout << diss[i].se << endl;
    }


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