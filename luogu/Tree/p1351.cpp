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
#define mod 10007

using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 2025.07.27——18:36:30
// 2025.07.27——19:24:40 accepted
/*
 * 题目意思： 给一棵树，其中每个点有点权Wi ，然后如果两个点的最短距离为2的话
 * 会产生一个 联合权值 Wv *Wu ,然后求该值的最大值
 *
 * 思路， 因为 会产生两种情况的最短距离为 2，一个是 该节点的父节点的父节点
 * 或者 是 该节点的父节点的其他子节点 而父节点的父节点 ，在无向图中也是该点的父节点的子节点
 *
 * sum值的维护 可以使用前缀和的方式， 而wi * wj 可以使用 维护一个点上的最大值和次大值进行实现；
 */

const int N = 2e5 + 10;
i64 dp[N],w[N],sum;
vector<vector<i64> >g;
i64 dfs(i64 u, i64 f) {
    i64 res = 0LL, w0 = 0LL, w1 = 0LL;
    i64 sz = g[u].size();
    i64 presum = 0LL;
    for (int j = 0;j < sz;j++) {
        i64 vv = g[u][j];
        // pre[j + 1] += (pre[j] + w[vv]);
        presum += w[vv];
    }
    for (int i = 0;i < sz;i++) {
        i64 v = g[u][i];
        if (w[v] > w0) { w1 = w0;w0 = w[v]; }
        else if (w[v] > w1) {w1 = w[v];}
        if (v != f)dp[u] = max(dfs(v, u), dp[u]);
        (sum += (presum - w[v]) * w[v] % mod) %= mod;
    }
    return dp[u] = max(dp[u], w0 * w1);
}


void solve() {
    i64 n;
    cin >> n;
    g.resize(n + 1);
    // g.resize(n + 1);
    for (int i = 1;i < n;i ++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) {
        sort(all(g[i]));
        cin >> w[i];;
    }


    cout << dfs(1, 1) << " " << sum << endl;
    


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