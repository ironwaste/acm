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

// 补题——题目链接:
// 网址：
// 2025.09.09——16:39:58
/*
 *
 * 这题很有意思： 题目内容是给出一个无根树
 * 而后我们可以选择k个相连的点， 去求其他未被选择的点到达
 * 这些 被选中的点的 最大值
 * 并且最小化这个最大值 通过选择不同的k个点进行实现
 *
 * 可以通过直径来进行选择
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>g[n + 1];

    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<i64>fa(n + 1, 0), dis(n + 1, 0);
    vector<i64>path;
    function<void(i64, i64)>dfs;
    i64 c = 0;
    dfs = [&](i64 u, i64 f)->void {

        for (auto v : g[u]) {
            if (v == f)continue;
            fa[v] = u;
            dis[v] = dis[u] + 1;
            if (dis[c] < dis[v]) {
                c = v;
            }
            dfs(v, u);
        }

        };
    dfs(1, 1);
    fa[c] = -1;
    dis[c] = 0;
    dfs(c, c);
    for (int st = c;st != -1;st = fa[st]) {
        path.push_back(st);
    }

    i64 sz = path.size();
    i64 cen1, cen2 = -1;
    vector<i64>h(n + 1, 0);
    function<void(i64, i64)>dfsh;
    dfsh = [&](i64 u, i64 f)->void {
        h[u] = 1;
        for (auto v : g[u]) {
            if (v == f)continue;
            dfsh(v, u);
            h[u] = max(h[u], h[v] + 1);
        }
        };
    i64 ans = INT_MAX;
    // 只需要计算一个中心的原因在于
    // 因为根节点也是要被计算在内的核心城市 也需要
    // 所以 偶数情况下的两个节点 只要是相同个数 解就相同
    // 

    cen1 = path[sz / 2];
    h[cen1] = 0;
    dfsh(cen1, cen1);
    vector<i64>a;
    for (int i = 1;i <= n;i++) { a.push_back(h[i]); }
    sort(all(a), greater<i64>());
    ans = min(ans, a[k]);
    // } else {
    //     cen1 = path[sz / 2];
    //     h[cen1] = 0;
    //     dfsh(cen1, cen1);
    //     vector<i64>a;
    //     for (int i = 1;i <= n;i++) { a.push_back(h[i]); }
    //     sort(all(a), greater<i64>());
    //     ans = min(ans, a[k]);
    // a.clear();
    // cen2 = path[sz / 2 + 1];
    // h[cen2] = 0;
    // dfsh(cen2, cen2);
    // for (int i = 1;i <= n;i++) { a.push_back(h[i]); }
    // sort(all(a), greater<i64>());
    // ans = min(ans, a[k]);
    // }


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