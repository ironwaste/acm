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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/P3629
// 网址：
// 2025.09.12——08:30:51
/*
 *
 * 
 *
*/
const i64 N = 1e5 + 10;
struct node {
    i64 value, to, nxt;
}e[N];
void solve() {
    i64 n, K;
    cin >> n >> K;
    vector<pll>g[n + 1];
    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back({ v,1 });
        g[v].push_back({ u,1 });
    }
    i64 c = 0;
    vector<i64>p, fa(n + 1, -1), dis(n + 1, 0);
    function<void(i64, i64)>dfs;
    dfs = [&](i64 u, i64 f)->void {
        for (auto [v, w] : g[u]) {
            if (v == f)continue;
            fa[v] = u;
            dis[v] = dis[u] + w;
            if (dis[c] < dis[v])c = v;
            dfs(v, u);
        }
        };
    dfs(1, 1);
    fa[c] = -1;dis[c] = 0;
    dfs(c, c);
    for (i64 i = c;i != -1;i = fa[i]) {
        if (i != c) {
            i64 u = i, v = p.back();
            for (auto& [vv, w] : g[u]) {
                if (v == vv) { w = -1;break; }
            }for (auto&& [uu, w] : g[v]) {
                if (u == uu) { w = -1;break; }
            }
            // for (auto [v, w] : g[u]) {
            //     de(u)de(v)deb(w);
            // }
        }
        // deb(i)
        p.push_back(i);
    }
    i64 ans = 2LL * (n - 1) - (p.size() - 2);
    if (K == 1) {
        cout << ans << endl;return;
    }
    vector<vector<i64> >dp(2, vector<i64>(n + 1, 0));
    i64 mx = 0;
    function<void(i64, i64)>tdp;
    tdp = [&](i64 u, i64 f)->void {
        for (auto [v,w] : g[u]) {
            if (v == f)continue;
            tdp(v, u);
            i64 d = dp[0][v] + w;
            if (d >= dp[0][u]) {
                dp[1][u] = dp[0][u];
                dp[0][u] = d;
            } else if (d > dp[1][u]) {
                dp[1][u] = d;
            }
            mx = max(mx, dp[0][u] + dp[1][u]);
        }
        };
    tdp(1, 1);
    // de(mx);
    cout << ans - mx + 1 << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}