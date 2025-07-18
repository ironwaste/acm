// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
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
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;


/****
 * 有几个信息:
 * 1、 需要知道 有哪些点与点相连接
 * 2、 每个点的颜色
 */





void solve() {
    i64 n, q;
    cin >> n >> q;
    vector<vector<pll> >g(n);
    vector<i64>ac(n, 0);
    for (int i = 0;i < n;i ++) {
        cin >> ac[i];
    }
    i64 ans = 0;
    vector<map<i64, i64> >mpc(n);
    for (int i = 0;i < n - 1;i++) {
        i64 u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({ v,c });
        g[v].push_back({ u,c });
        mpc[u][v] = c;
        mpc[v][u] = c;
        if (ac[u] != ac[v])ans += c;
    }
    vector<map<i64, i64> >g_C(n);
    vector<i64>f(n, -1);
    auto dfs = [&](auto self, i64 u, i64 fa) -> void {
        for (auto t : g[u]) {
            i64 v = t.fi, c = t.se;
            if (v == fa) { continue; }
            i64 C = ac[v];
            f[v] = u;
            g_C[u][C] += c;
            self(self, v, u);
        }
        };
    dfs(dfs, 0, 0);

    auto erase = [&](i64 fa,i64 pre_color,i64 color, i64 w)->void {
        g_C[fa][pre_color] -= w;
        if (g_C[fa][color] == 0) {
            g_C[fa].erase(color);
        }
        g_C[fa][color] += w;
        };
    auto change = [&]( i64 v, i64 x)->i64 {
        i64 pre_c = ac[v], u = f[v];
        i64 res = 0;
        if (u != -1) {
            i64 c = mpc[u][v];
            erase(u, pre_c, x, c);
            if (pre_c == ac[u] && x != ac[u]) {
                res += c;
            } else if (pre_c != ac[u] && x == ac[u]) {
                res -= c;
            }
        }
        ac[v] = x;
        res += g_C[v][pre_c] - g_C[v][x];
        return res;
        };
    for (int i = 0;i < q;i++) {
        i64 v, x;
        cin >> v >> x;
        v--;
        ans += change(v, x);
        cout << ans << endl;
    }
    return;
}
// 2025.07.18——02:15:41 accpted
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // 2025.07.17——23:32:14
/*
 *
 *
 *
*/
    while(T--){
        solve();
    }
    return 0;
}