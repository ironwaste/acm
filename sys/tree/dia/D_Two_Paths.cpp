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

// 补题——题目链接: https://codeforces.com/problemset/problem/14/D
// 网址：
// 2025.09.12——05:51:50
// 2025.09.12——06:39:10 accpted
/*
 * n 的限度只有200 可以O(nm)通过但是我觉得有O(n)解法
 *  好像不可以。。。。
 *
*/

// void solve() {

//     i64 n;
//     cin >> n;
//     vector<i64>g[n + 1];
//     for (i64 i = 1;i < n;i++) {
//         i64 u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
    // vector<vector<pll> >dp(2, vector<pll>(n + 1, { 0,0 }));
    // vector<i64>redp(n + 1, 0), fa(n + 1, 0);
    // fa[1] = 1;
    // function<void(i64, i64)>dfs;
    // dfs = [&](i64 u, i64 f)->void {
    //     for (auto v : g[u]) {
    //         if (v == f)continue;
    //         fa[v] = u;
    //         dfs(v, u);
    //         i64 dis = dp[0][v].fi + 1;
    //         if (dis >= dp[0][u].fi) {
    //             dp[1][u] = dp[0][u];
    //             dp[0][u].fi = dis;
    //             dp[0][u].se = v;
    //         } else if (dis > dp[1][u].fi) {
    //             dp[1][u].fi = dis;
    //             dp[1][u].se = v;
    //         }
    //     }
    //     };
//     dfs(1, 1);
//     function<void(i64, i64)>dfs2;
//     dfs2 = [&](i64 u, i64 f)->void {
//         for (auto v : g[u]) {
//             if (v == f)continue;
//             i64 idx1 = dp[0][u].se;
//             i64 dis = dp[idx1 == v][u].fi;
//             redp[v] = max(redp[v], dis);
//             redp[v] = max(redp[v], redp[u]);

//             if(u!=1)redp[v] = max(redp[v], redp[u] + 1);

//             dfs2(v, u);
//         }
//         };
//     dfs2(1, 1);


//     i64 ans = 0;
//     for (int i = 1;i <= n;i++) {
//         de(i)deb(redp[i]);
//         i64 w1 = dp[0][i].fi, w2 = dp[1][i].fi;
//         if (i == fa[i]) {
//             for (auto v : g[i]) {
//                 if (v != dp[0][i].se) { ans = max(w1 * dp[0][v].se, ans); }
//                 if (v != dp[1][i].se) { ans = max(w2 * dp[0][v].se, ans); }
//             }
//             continue;
//         } else {
//             ans = max(dp[0][i].fi * (redp[i] ), ans);
//         }
//     }
//     cout << ans << endl;

// }
void solve() {
    i64 n;
    cin >> n;
    vector<i64>g[n + 1];
    for (i64 i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    i64 ans = 0;
    for (int u = 1;u <= n;u++) {

        for (auto v : g[u]) {
            if (v < u)continue;
            vector<vector<pll> >dp(2, vector<pll>(n + 1, { 0,0 }));
            function<i64(i64, i64)>dfs;
            dfs = [&](i64 u, i64 f)->i64 {
                i64 res = 0;
                for (auto v : g[u]) {
                    if (v == f)continue;
                    res = max(res, dfs(v, u));
                    i64 dis = dp[0][v].fi + 1;
                    if (dis >= dp[0][u].fi) {
                        dp[1][u] = dp[0][u];
                        dp[0][u].fi = dis;
                        dp[0][u].se = v;
                    } else if (dis > dp[1][u].fi) {
                        dp[1][u].fi = dis;
                        dp[1][u].se = v;
                    }
                    // de(v)de(dis)de(dp[0][u].fi)deb(dp[1][u].fi);
                    res = max(res, dp[0][u].fi + dp[1][u].fi);
                }
                // de(u)deb(res);
                return res;
                };
            i64 v1 = dfs(u, v);
            i64 v2 = dfs(v, u);
            ans = max(ans, v1 * v2);
            // de(u)de(v)deb(ans);
        }

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