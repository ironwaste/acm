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

using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 2025.08.28——20:40:57
/*
 *
 * 先判断是否是 直径上的 叶子节点
 * 非直径上叶子节点  都是 0 不可能到达的
 *
 * 次数大于3 则全部直径上 叶子节点 可以到达
 *
 * 如果 直径长度为奇数  且 中心点上 存在三条长度相等的
 * 最长半链  则 全部直径上叶子节点可以达到
 *
 * 或者 起始点 在中心 或者和中心相连的子树上
 * 也就是说其到达其他所有 直径上叶子节点的距离一样远
 *
 *
 * 如果是直径上的叶子节点  且 1节点不在直径上
 * 则所有 直径上叶子节点可到达
 * 如果
 *
 *
 * 按照 直径的中心 进行子树 划分
 * 如果中心点有两个呢 ？？ 两个中心点之间加一个点
 * 使其 变为 奇数直径 没有区别
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>g[n + 1];
    vector<i64>id(n + 1, 0);
    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<i64>fa(n + 1, 0), dis(n + 1, 0);
    i64 far = 0;
    auto bfs = [&](i64 st)->void {
        queue<pll>q;
        q.push({ st,0 });
        dis[st] = 0;
        fa[st] = 0;
        while (!q.empty()) {
            auto [u, w] = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (v == fa[u])continue;
                fa[v] = u;
                dis[v] = dis[u] + 1;
                if (dis[v] > dis[far]) {
                    far = v;
                }
            }
        }
        };
    bfs(1);


    i64 cnt = 0;
    vector<i64>lu,lu1,lu2,ans(n+1,0);
    for (int i = 1;i <= n;i++) {
        if (dis[i] == dis[far]) {
            lu.push_back(i);
            ans[i] = 1;
        }
    }

    if (k == 1) {
        for (int i = 1;i <= n;i++) {
            cout << ans[i] << " \n"[i == n];
        }
        return;
    } else {
        for (auto x : lu) { ans[x] = 0; }
    }
    bfs(far);
    vector<i64>path;
    for (i64 v = far; v != 0;v = fa[v]) {path.push_back(v);}
    i64 sz = path.size();
    for (int i = 1; i <= n;i ++) {
        if(dis[i] == dis[far])lu1.push_back(i);
    }
    far = path.back();
    bfs(far);
    for (int i = 1; i <= n;i ++) {
        if(dis[i] == dis[far])lu2.push_back(i);
    }

    i64 root = 0;
    vector<i64>reg[n + 1];
    if (sz % 2 != 1) {
        i64 mid = sz / 2;
        i64 u, v;
        u = path[mid], v = path[mid + 1];
        for (int i = 1;i <= n;i ++) {
            for (auto x : g[i]){
                if (i == u && x == v)continue;
                if (i == v && x == u)continue;
                reg[i].push_back(x);
            }
            if (i == v || i == u) {
                g[0].push_back(i);
            }
        }
    } else {
        i64 mid = sz / 2;
        root = path[mid + 1];
        reg = g;
    }
    i64 cnt = 1;
    

    auto dfs = [&](auto self, i64 u, i64 f, i64 idx)->void {
        id[u] = idx;
        for (auto v : reg[u]) {
            if (v == f) { continue; }
            self(self, v, u, idx);
        }
        };

    for (auto v : reg[root]) {
        id[v] = cnt;
        dfs(dfs, v, root, cnt);
        cnt++;
    }

    set<i64>idx;
    for (auto u : lu1) {
        idx.insert(id[u]);
    }
    if (idx.size() > 2) {
        
    }





}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}