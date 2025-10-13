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

// 补题——题目链接: https://atcoder.jp/contests/abc427/tasks/abc427_c
// 网址：
// 2025.10.11——20:08:54
/*
 *
 * 没有长度为 三 的环
 *
 * 直接模拟 数据量小
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64> >g(n);
    vector<pll>edge;
    for (int i = 0;i < m;i++) {
        i64 u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({ v,u });
    }
    i64 ans = m;
    i64 inf = (1LL << n) - 1;
    for (i64 i = 0;i < inf;i ++) {
        i64 tmp = 0;
        for (i64 j = 0;j < m;j++) {
            i64 v = edge[j].fi, u = edge[j].se;
            i64 v1 = (i >> v) & 1LL, u1 = (i >> u) & 1LL;
            if (v1 == u1) {
                tmp++;
            }
        }
        ans = min(ans, tmp);
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