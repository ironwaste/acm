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
// 2025.08.08——01:13:56 
// 2025.08.08——02:45:58 wa 了 第一次觉得wa了那么亲切
// 2025.08.08——03:22:33 accpted  我要哭了 tmd小错误我恨死了。。。
/*
 *
 *
 *
*/
// 对于 dep siz 等多组样例 初始化的问题没想

const int N = 1e5 + 100;
const int n4 = 4LL * N + 10;
int n, m, cnt;

i64 dep[N], siz[N], fa[N], dfn[N], id[N];
i64 top[N], hson[N], seg[n4];
i64 tree[N], tag[N];
vector<vector<i64> >g;
void init() {
    for (int i = 0;i < N;i ++) {
        dep[i] = siz[i] = fa[i] = dfn[i] = id[i] = top[i] = hson[i] = tree[i] = tag[i] = 0;
    }
    for (int i = 0;i < n4;i ++) {
        seg[i] = 0;
    }
}
static inline void dfs1(i64 f, i64 u) {
    dep[u] = dep[f] + 1;
    siz[u] = 1;

    fa[u] = f;
    hson[u] = 0;
    for (auto v : g[u]) {
        if (v == f) continue;

        fa[v] = u;
        dfs1(u, v);

        siz[u] += siz[v];
        if (siz[hson[u]] < siz[v]) {
            hson[u] = v;
        }
    }
}
static inline void dfs2(i64 u, i64 tp) {
    top[u] = tp;
    id[cnt] = u;
    dfn[u] = cnt++;
    if (hson[u]) {
        dfs2(hson[u], tp);
    }
    for (auto v : g[u]) {
        if (v == fa[u] || v == hson[u]) continue;
        dfs2(v, v);
    }
}

void build(int p, int s, int t) {
    if (s == t) {
        seg[p] = tree[id[s]]; // 时间序 转换为原始序列号
        return;
    }
    int mid = (s + t) >> 1;

    build(p * 2, s, mid);
    build(p * 2 + 1LL, mid + 1, t);
    seg[p] = max(seg[p * 2], seg[p * 2 + 1LL]);
    return;
}


void add(int p, int s, int t, int l, int x) {
    if (s == t) {
        seg[p] += x;
        return;
    }

    int mid = (s + t) >> 1;


    if (l <= mid) { add(p * 2, s, mid, l, x); } else { add(p * 2 + 1, mid + 1, t, l, x); }
    seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
    return;
}
static inline i64 qry(int p, int s, int t, int l, int r) {
    if (l <= s && t <= r) {
        return seg[p];
    }
    int mid = (s + t) >> 1;

    i64 res = 0;
    if (l <= mid) res = max(res, qry(p * 2, s, mid, l, r));
    if (r > mid) res = max(res, qry(p * 2 + 1, mid + 1, t, l, r));
    return res;
}

i64 lcaqry(i64 x, i64 y) {
    i64 res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]]) { swap(x, y); }
        // i64 fx = top[x];

        res = max(res, qry(1, 1, n, dfn[top[y]], dfn[y]));
        res = max(res, tree[top[y]] + tag[fa[ top[y] ]]);
        y = fa[top[y]];
    }
    if (dep[x] > dep[y]) { swap(x, y); }
    res = max(res, qry(1, 1, n, dfn[x], dfn[y]));
    // return res;
    if (top[x] == x)
        res = max(res, tree[x] + tag[fa[x]]);
    return res;
}

static inline void solve() {
    cin >> n >> m;
    g.assign(n + 1, {});
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
    dfs1(0, 1);
    dfs2(1, 1);
    // deb(cnt);
    build(1, 1, n);
    for (int i = 0;i < m;i++) {
        int opt, x = 0, y = 0, z = 0;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            i64 res = lcaqry(x, y);
            cout << res << endl;
        } else if (opt == 2) {
            cin >> x >> z;
            tag[x] += z;
            if (fa[x]) {
                add(1, 1, n, dfn[fa[x]], z);
                tree[fa[x]] += z;
            }
            if (hson[x])    add(1, 1, n, dfn[hson[x]], z);

        }
    }
    for (auto &u : g) {
        u.clear();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        init();
        solve();
    }
    return 0;
}