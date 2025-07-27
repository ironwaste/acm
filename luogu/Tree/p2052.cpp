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

// 2025.07.27——15:04:20
// 2025.07.27——15:24:26 accpted
/* https://www.luogu.com.cn/problem/P2052
 *
 * 题目意思：即求给定的树中，线段两端之间 的国家数量只差，乘以道路权值
 * 所以需要存储每个国家其子树大小，相当于乘积的另外一个值为总个数减去子树个数
 * 存储的变量有 子树大小，总个数，即可
 *
 *
 *
 * 当我们对于 树进行dfs 求节点的子树大小的时候，再后续乘起来的时候，不可以直接
 * 按照边相连进行乘，它的逻辑关系是和 dfs深度也就是父子节点的关系，
 *  但是我们可以通过其子树大小来判断 谁是为父，谁子节点 的逻辑关系，前提是按照连边来
 * 相当于对于其进行层序遍历的关系
*/
const int N = 1e6 + 10;
i64 num[N], sum;
vector<vector<pll> >g;
i64 dfs(int fa,int u) {
    i64 res = 1LL;
    for (auto [v,w] : g[u]) {
        if (v == fa) continue;
        res += dfs(u, v);
    }
    return num[u]=res;
}
i64 dfs2(i64 fa, i64 u) {
    // de(u)deb(fa)
    i64 res = 0LL;
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        res += dfs2(u, v);
        // de(v)deb(res)
        res += abs(sum - 2 * num[v]) * w;
        // de(v)deb(res)
    }
    return res;

}

void solve() {
    int n;
    cin >> n;
    sum = n;
    g.resize(n);
    for (int i = 1;i < n;i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(0, 0);
    // for (int i = 0;i < n;i ++) {
    //     de(i)deb(num[i]);
    // }
    // i64 ans = dfs2(0, 0);

    i64 ans = 0;
    for (int i = 0;i < n;i++) {
        // deb(i)
        for (auto [v, w] : g[i]) {
            // de(v)de(w)de(ans)
            ans += abs(sum - min(num[v],num[i]) * 2LL) * w;
            // deb(ans);
        }
    }



    cout << ans/2 << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}