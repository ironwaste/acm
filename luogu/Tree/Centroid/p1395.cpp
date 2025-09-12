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

// 2025.07.21——22:30:56
/*  https://www.luogu.com.cn/problem/P1395
 *
 * 求树上所有点到其中一个点的总和最小时，该点为几，且总和为多少
 * 所以如果有两个重心的时候，可能会有距离和两个不同的情况出现。
 * 时间花费一个小时九分钟
*/
const int N = 5e4 + 10;
i64 num[N], weight[N], centroid[2] = {0,0}, dis[N],disnum[N];
// 距离怎么求呢？ dis怎么求
// dfs 下去，我可以求小的子树的距离和，这样我就可以根据其节点数和距离数
// 求出最终的值，其子节点的距离数 + 其子节点的节点数就等于该点的距离数；
vector<vector<i64> >g;
void dfs(i64 sum,i64 fa, i64 u) {
    i64 res = 1LL;// 自己
    i64 disres = 0LL;
    for (auto v : g[u]) {
        if (v == fa) { continue; }
        dfs(sum,u, v);
        res += num[v];
        // disres += dis[v] + num[v];
    }
    i64 k;
    weight[u] = max(sum - res + 1LL, res);
    k = weight[u];
    num[u] = res;
    // dis[u] = disres;
    i64 *id0 = &centroid[0], *id1 = &centroid[1];
    i64 k0 = weight[*id0], k1 = weight[*id1];
    if (k <= k0) {
        *id1 = *id0, *id0 = u;
    } else if (k <= k1) {
        *id1 = u;
    }
}
void dfs2(i64 fa, i64 u) {
    i64 res = 1LL,disres = 0LL;
    for (auto v : g[u]) {
        if (v == fa)continue;
        dfs2(u, v);
        res += disnum[v];
        disres += dis[v] + disnum[v];
    }
    dis[u] = disres;
    disnum[u] = res;
    // return res;
}


void solve() {
    weight[0] = LLONG_MAX;
    int n;
    cin >> n;
    i64 sum = n;// 总共有三个点
    g.resize(n + 1);
    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(sum,1,1);
    i64 id0 = centroid[0], id1 = centroid[1];
    i64 mi0 = weight[id0], mi1 = weight[id1];
    dfs2(id0, id0);
    vector<pll>a;
    a.push_back({ dis[id0],id0 });
    dfs2(id1, id1);
    a.push_back({ dis[id1],id1 });
    sort(all(a));
    i64 id = a[0].se;
    cout << id << " " << a[0].fi << endl;

}
// 2025.07.23——16:10:24 wa了1个
// 2025.07.23——16:14:39 accpted
int main() {
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