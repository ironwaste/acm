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
// 补题——题目链接: https://acm.hdu.edu.cn/contest/problem?cid=1173&pid=1009
// 苹果树
// 网址：
// 2025.08.07——11:41:05
// 2025.08.07——11:53:22 中止 只写完了树链剖分没写 线段树

// 2025.08.07——21:33:19
// 2025.08.07——22:32:36 中止 写完了 但是在查询最大值的过程中有问题
// 可能是修改部分
/*
 *
 *
 *
*/
// 对于 dep siz 等多组样例 初始化的问题没想

const int N = 1e5 + 10;
const int n4 = 4 * N;
int n, m;

i64 dep[N], siz[N], fa[N], dfn[N], id[N];
i64 top[N],hson[N],lazy[N],seg[n4];
i64 tree[N],tag[N];
vector<vector<i64> >g;
i64 dfs1(i64 f, i64 u) {
    dep[u] = 0;
    siz[u] = 1LL;
    dep[u] = dep[f] + 1;
    for (auto v : g[u]) {
        if (v == f) continue;
        fa[v] = u;
        siz[u] += dfs1(u, v);
        if (siz[hson[u]] < siz[v]) {
            hson[u] = v;
        }
    }
    return siz[u];
}
int cnt = 1;
void dfs2(i64 u, i64 tp) {
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

void build(int p,int s,int t) {
    lazy[p] = 0;
    if (s == t) {
        seg[p] = tree[ dfn[s] ]; // 时间序 转换为原始序列号
        tag[s] = 0;
        return;
    }
    int mid = s + (t - s >> 1);
    int lp = p << 1LL, rp = (p << 1LL) + 1LL;
    build(lp, s, mid), build(rp, mid + 1, t);
    seg[p] = max(seg[lp] , seg[rp]);
}
void pushdown(int s,int mid,int t,int p) {
    if (lazy[p]) {
        int lp = p << 1LL, rp = (p << 1LL) + 1LL;
        // left son
        seg[lp] += lazy[p];
        lazy[lp] += lazy[p];

        seg[rp] += lazy[p];
        lazy[rp] += lazy[p];

        lazy[p] = 0;
    }
}
void add(int p, int s, int t, int l, int r, int x) {
    if (l <= s && t <= r) {
        seg[p] += x;
        lazy[p] += x;
        return;
    }

    int mid = s + (t - s >> 1);
    int lp = p << 1LL, rp = (p << 1LL) + 1LL;

    pushdown(s, mid, t, p);
    if (l <= mid) { add(lp, s, mid, l, r, x); }
    if (r > mid) { add(rp, mid + 1, t, l, r, x); }

    seg[p] = max(seg[lp] , seg[rp]);
}

i64 qry(int p,int s,int t,int l,int r) {
    if (l <= s && t <= r) {
        return seg[p];
    }
    int mid = s + (t - s >> 1);
    int lp = p << 1LL, rp = (p << 1LL) + 1LL;

    pushdown(s, mid, t, p);

    i64 res = 0;
    if (l <= mid) res = max(res, qry(lp, s, mid, l, r));
    if (r > mid) res = max(res, qry(rp, mid + 1,t, l, r));
    return res;
}

i64 lcaqry(i64 x, i64 y) {
    i64 res = 0;
    while (top[x] != top[y]) {
        de(x)de(y)deb(res)

        if (dep[top[x]] < dep[top[y]]) { swap(x, y); }
        i64 fx = top[x];
        // de(fx)de(x)de(y)deb(res)
        // de(dfn[fx])de(dfn[x])deb(res)
        res = max(res, qry(1, 1, n, dfn[fx], dfn[x]));
        x = fx;
        fx = fa[x];
        de(dfn[fx])de(dfn[x])deb(res)
        res = max(res, qry(1, 1, n, dfn[x], dfn[x]) + tag[fx]);
        x = fx;
    }
    if (dep[x]< dep[y]) { swap(x, y); }
    res = max(res, qry(1, 1, n, dfn[x], dfn[y]));
    return res;
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> tree[i];
    }

    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt = 1;
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    while (m--) {
        int opt,x,y,z;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            i64 ans = lcaqry(x, y);
            deb(ans);
            // cout <<  << endl;
        } else if (opt == 2) {
            cin >> x >> z;
            tag[x] += z;
            if (x != 1)     add(1, 1, n, dfn[fa[x]], dfn[fa[x]], z);
            if (hson[x])    add(1, 1, n, dfn[hson[x]], dfn[hson[x]], z);
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}