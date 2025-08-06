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

// 2025.08.05——10:41:54
// 2025.08.07——00:22:04 
/* https://www.luogu.com.cn/problem/P3384
 * 树链剖分模板题 ：
 * 四种操作：
 * 1、 x  y  z  表示树从节点 x 到 y 节点的最短路径上所有节点 加上Z
 * 2、 x  y     表示求树从 x 到 y 结点最短路径上所有节点的值之和。
 * 3、 x z      表示将以 x 为根节点的子树内所有节点值都加上 z。
 * 4、 x        表示求以 x 为根节点的子树内所有节点值之和。
 *
*/
const int N = 1e5 + 10;
i64 tree[N];
i64 dep[N], siz[N], dfn[N],id[N],hson[N], top[N], fa[N];
i64  seg[4 * N + 10LL], lazy[4 * N + 10LL];
i64 mod;
vector<vector<i64>>g;
i64 dfs1(i64 f, i64 u) {
    hson[u] = 0;
    dep[u] = dep[f] + 1;
    siz[u] = 1LL;
    for (auto v : g[u]) {
        if (v == f) continue;
        fa[v] = u;
        siz[u] += dfs1(u, v);
        if (siz[v] > siz[hson[u]]) {
            hson[u] = v;
        }
    }
    return siz[u];
}
i64 cnt = 1;
void dfs2(i64 u,i64 tp) {
    top[u] = tp;
    id[cnt] = u;
    dfn[u] = cnt++;
    if (hson[u]) {
        dfs2(hson[u], tp);
        for (auto v : g[u]) {
            if (v == fa[u] || v == hson[u]) continue;
            dfs2(v, v);
        }
    }
}

i64 lca(i64 x,i64 y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            y = fa[top[y]];
        } else {
            x = fa[top[x]];
        }
    }
    return dep[x] > dep[y] ? y : x;
}

void build(i64 s, i64 t, i64 p) {
    if (s == t) {
        seg[p] = tree[id[s]];
        return;
    }

    int mid = s + (t - s >> 1);
    build(s, mid, 2 * p), build(mid + 1, t, 2 * p + 1LL);
    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}
void pushdown(i64 s, i64 mid, i64 t, i64 p) {
    if (lazy[p]) {
        // i64 mid = s + (t - s >> 1);
        i64 lp = p << 1LL, rp = (p << 1LL) + 1LL;
        i64 len1 = mid - s + 1, len2 = t - mid;
        seg[lp] = (seg[lp] + len1 * lazy[p] % mod) % mod;
        (lazy[lp] += lazy[p]) %= mod;

        seg[rp] = (seg[rp] + len2 * lazy[p] % mod) % mod;
        (lazy[rp] += lazy[p]) %= mod;

        lazy[p] = 0;
    }
}
void add(i64 l, i64 r, i64 s, i64 t, i64 p, i64 x) {
    if (l <= s && t <= r) {
        i64 len = t - s + 1;
        (seg[p] += len * x % mod) %= mod;
        (lazy[p] += x) %= mod;
        return ;
    }
    int mid = s + (t - s >> 1);
    i64 lp = p << 1LL, rp = (p << 1LL)+ 1LL;
    pushdown(s, mid, t, p);
    if (l <= mid) add(l, r, s, mid, lp, x);
    if (r > mid) add(l, r, mid + 1, t, rp, x);
    seg[p] = (seg[lp] + seg[rp]) % mod;
}
i64 qry(i64 l, i64 r, i64 s, i64 t, i64 p) {
    if (l <= s && t <= r) {
        // de(p)deb(seg[p])
        return seg[p] % mod;
    }
    int mid = s + (t - s >> 1);
    i64 lp = p << 1LL, rp = (p << 1LL)+ 1LL;
    
    pushdown(s, mid, t, p);
    i64 res = 0;
    if (l <= mid) (res += qry(l, r, s, mid, lp)) %= mod;
    if (r > mid) (res += qry(l, r, mid + 1, t, rp)) %= mod;
    return res;
}

i64 lcaqry(i64 x, i64 y, i64 t) {
    i64 s = 1, p = 1;
    i64 res = 0;
    while (top[x] != top[y]) {
        if ( dep[top[x]] > dep[top[y]] ) {
            i64 dfx = dfn[top[x]], dfy = dfn[x];
            (res += qry(dfx, dfy, s, t, p) )%= mod;
            x = fa[top[x]];
        } else {
            i64 dfx = dfn[top[y]], dfy = dfn[y];
            (res += qry(dfx, dfy, s, t, p) )%= mod;
            y = fa[top[y]];
        }
    }
    if (dep[x] > dep[y])swap(x, y);
    (res += qry(dfn[x], dfn[y], s, t, p)) %= mod;
    return res % mod;
}

void lcaadd(i64 x, i64 y, i64 t,i64 z) {
    i64 s = 1, p = 1;
    while (top[x] != top[y]) {
        if ( dep[top[x]] > dep[top[y]] ) {
            i64 dfx = dfn[top[x]], dfy = dfn[x];
            add(dfx, dfy, s, t, p, z);
            x = fa[top[x]];
        } else {
            i64 dfx = dfn[top[y]], dfy = dfn[y];
            add(dfx, dfy, s, t, p, z);
            y = fa[top[y]];
        }
    }
    if (dep[x] > dep[y])swap(x, y);
    add(dfn[x], dfn[y], s, t, p, z);
}

void solve() {
    i64 n, m, r;
    cin >> n >> m >> r >> mod;
    for (int i = 1;i <= n;i ++) {cin >> tree[i];}

    g.resize(n + 1);
    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(r, r);
    dfs2(r, r);
    i64 s = 1, t = n, p = 1;
    build(s, t, p);
    while (m--) {
        i64 op,x,y,z,res = 0;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            lcaadd(x, y, t, z);
        } else if (op == 3) {
            cin >> x >> z;
            i64 sz = siz[x];
            x = dfn[x], y = x + sz - 1;
            add(x, y, s, t, p, z);
        } else if (op == 2) {
            cin >> x >> y;
            cout << lcaqry(x, y, t) <<endl;
            
        } else if (op == 4) {
            cin >> x;
            i64 sz = siz[x];
            x = dfn[x], y = x + sz - 1;
            cout << qry(x, y, s, t, p) << endl;
        }

        
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