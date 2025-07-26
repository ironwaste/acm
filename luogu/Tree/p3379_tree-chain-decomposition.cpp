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

// 2025.07.25——21:52:33
/* https://www.luogu.com.cn/problem/P3379
 * 由于上一个版本TLE 所以重新复写一下，之前只是普通版仅仅标记了树的分叉
 * 并且对于树的分叉的不同子树进行不同的标注，一个是标注了其本身为top点，
 * 并且记录了其父亲节点，以实现标注为自己的节点能正常向祖先找节点，
 * 另外一个是直接标记为 其分支节点
 *
 * 但是由于可能存在全部都是一个子树特别长的情况，重复出现，导致的超时。
 *
 * 改称为双dfs的树链剖分 tree chain decomposition
 *
 * 第一个dfs 用于求每个点的父节点（father） ，深度（deep），子树大小（size），重子节点hson
 * 第二个dfs 记录重链或者轻链的链顶（top 应初始化为其本身） ， 重边有限遍历时的dfs序列（dfn时间戳）
 * 以及dfs序列 所对应的节点编号（rank）
*/

const int N = 5e5 + 10;
vector<vector<i64> >g;
i64 fa[N], num[N], dep[N], dfn[N], top[N], hson[N], rank[N];
// 第一个dfs1 维护父节点（fa） 、深度（dep） 、子树大小（size）、重子节点（hson）
i64 dfs1(i64 u, i64 deep) {
    hson[u] = 0;
    num[hson[u]] = 0;
    // fa[u] = u;
    dep[u] = deep;
    num[u] = 1;// size为加上自己的子树节点数
    for (auto v : g[u]) {
        // deb(v)
        if (v == fa[u])continue;
        fa[v] = u;    
        num[u] += dfs1(v, deep + 1LL);
        if (num[v] > num[hson[u]]) {
            hson[u] = v;
        }
    }
    // deb(u)
    return num[u];
}

// 第二个dfs 用于求 树的top节点，重边优先遍历时的dfs序列 （dfn）、 
// dfs序 对应的节点编号dfn -> 用于线段树操作的，如果使用求lca 可以不需要
void treedec(i64 u,i64 tp) {
    top[u] = tp;
    if (hson[u]) {
        treedec(hson[u], tp);
        for (auto v : g[u]) {
            if(v == fa[u] || v == hson[u])continue;
            treedec(v, v);
        }
    }
}

i64 lca(i64 u, i64 v) {
    // 判断是 否在同一深度，
    // 首先应该判断是否在同一条链上，那么答案就应该是深度小的哪一个
    // top[a] == top[b] 
    // 可以先进行交换将a 变为深度小的那一个
    // 如果是重链则先跳重链，然后再将另一个节点跳到相应深度上
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = fa[top[u]];
        } else {
            v = fa[top[v]];
        }
    }
    return dep[u] > dep[v] ? v : u;
}


void solve() {
    i64 n, m, s;
    cin >> n >> m >> s;
    g.resize(n + 2);
    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(s, 1);
    treedec(s, s);

    while (m --) {
        i64 x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;

    }



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