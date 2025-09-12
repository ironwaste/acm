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

// 2025.09.12——05:19:59
// https://www.luogu.com.cn/problem/U81904
// 2025.09.12——05:33:55
/*
 *
 * 求树的直径，但是存在负边权
 *
*/

void solve(){
    i64 n;
    cin >> n;
    vector<pll>g[n + 1];
    for (int i = 1;i < n;i ++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }
    vector<vector<i64> >dp(2, vector<i64>(n + 1, 0));
    i64 ans = 0;
    function<void(i64, i64)>dfs;
    dfs = [&](i64 u, i64 f)->void {
        for (auto& [v, w] : g[u]) {
            if (v == f)continue;
            dfs(v, u);
            i64 dis = dp[0][v] + w;
            if (dis >= dp[0][u]) {
                dp[1][u] = dp[0][u];
                dp[0][u] = dis;
            } else if (dis > dp[1][u]) {
                dp[1][u] = dis;
            }
            ans = max(ans, dp[0][u] + dp[1][u]);
        }
        };
    dfs(1, 1);

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}