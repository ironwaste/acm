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

// 2025.07.27——15:31:38
// 2025.07.27——18:16:53 accpted
/*
 * 题目意思： 是有一棵树，期间点权为0 或者 1
 * 现在需要判断路径 u ， v 之间的最短路径是否有存在
 * 0 或者 1
 * 多次查询
 * 存储信息，可以直接找俩个点的 LCA 这样就可以直接 找到最小路径
 *
 * 然后通过维护root 到 v + root 到 v - root 到 lca的 值，以判断是否经过过 0 或者 1
 * 先进行树链剖分 进而维护出 重链 轻链  hson[n] num[n] fa[n] dep[n] top[N]
 *
 * 再求出 每个点之间的权值和，根据路径长度 和 最终算出的权值和比较是否存在着 0 和 1
 * 使用 树上差分即可
 *  
 *
*/
const int N = 5e5 + 10;
i64 num[N], dep[N], hson[N], fa[N], top[N];
i64 root;
vector<i64>hg;
vector<vector<i64> >g;
i64 HG(char c) {
    return c == 'H';
}

i64 dfsi(i64 u, i64 step) {
    hson[u] = 0;
    num[hson[0]] = 0;
    dep[u] = step;
    num[u] = 1LL;
    for (auto v : g[u]) {
        if (v == fa[u]) { continue; }
        fa[v] = u;
        num[u] += dfsi(v, step + 1LL);
        if (num[v] > num[hson[u]]) {
            hson[u] = v;
        }
    }
    return num[u];
}

void treedec(i64 u, i64 tp) {
    top[u] = tp;
    if (hson[u]) {
        treedec(hson[u], tp);
        for (auto v : g[u]) {
            if (v == fa[u] || v == hson[u])continue;
            treedec(v, v);
        }
    }
};

i64 lca(i64 u, i64 v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = fa[top[u]];
        } else {
            v = fa[top[v]];
        }
    }
    return dep[u] > dep[v] ? v : u;
}
i64 prefix[N];
void dfspre(i64 u) {
    for (auto v : g[u]) {
        if (fa[u] == v)continue;
        prefix[v] = prefix[u] + hg[v];
        dfspre(v);
    }
}

i64 query(i64 x,i64 y,i64 lc) {
    return prefix[x] + prefix[y] - 2 * prefix[lc] + hg[lc];
}
i64 querydep(i64 x,i64 y,i64 lc) {
    return dep[x] + dep[y] - 2 * dep[lc] + 1LL;
}

void solve() {
    int n, m;
    cin >> n >> m;
    hg.resize(n + 1);
    g.resize(n + 1);
    string s;
    cin >> s;
    for (int i = 1;i <= n;i++) { hg[i] = HG(s[i - 1]); }

    for (int i = 1;i < n;i ++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    root = 1;
    fa[root] = root;
    dfsi(root, 1);
    treedec(root, root);
    prefix[root] = hg[root];
    dfspre(root);
    
    // for (int i = 0;i <= n;i ++) {
    //     de(i)deb(prefix[i]);
    // }
    
    // for (int i = 0;i <= n;i ++) {
    //     de(i)de(fa[i])deb(top[i]);
    // }

    string ans = "";
    while (m--) {
        i64 w1, w2, x, y;
        char c;
        cin >> x >> y >> c;
        i64 w = HG(c),lc = lca(x,y);
        w1 = querydep(x, y, lc);
        w2 = query(x, y, lc);
        // cout << lc << endl;
        // de(w1)de(w2)de(lc)deb(w)
        if ( (w2 > 0 && w == 1) || (w2 < w1 && w == 0) ) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << endl;

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