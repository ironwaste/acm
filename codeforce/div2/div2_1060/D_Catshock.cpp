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

// 补题——题目链接: https://codeforces.com/contest/2154/problem/D
// 网址：
// 2025.10.19——23:26:02
// 2025.10.20——00:51:57 
/*
 *
 * 一个点的奇偶性 是不会改变的，比如说起点，只能在
 * 偶数次的距离 位置出现，  因为 出去 回来的边一定走两回
 * 不会产生 奇数次的情况。
 *
 * 需要知道， 每个点的奇偶性 ，和 到达这个点最小的距离
 * 然后根据奇偶性， 将节点
 * 从叶子节点进行删除即可
 * 从叶子 节点开始 最多只需要 2* n 吧应该
 *
 * 先删除和 1 相关的 点 但是和路径无关的点
 *
 * 再删除 和n 相链接的点，
 * 没有规律性不好 写代码
 *
 * 换种方式，直接 从 1 开始删除即可路径的反方向删除即可
 *
 * 不 直接从 叶子节点开始， 根据叶子节点的奇偶性进行删除。
 * 删除到只剩下路径
 *
 */

void solve() {

    i64 n;
    cin >> n;
    vector<vector<i64> >g(n + 1);
    vector<pll>du(n + 1, { 0,0 });
    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<i64>odd, eve;

    vector<i64>dis(n + 1, 0), fa(n + 1, 0);
    vector<i64>path;
    set<i64>pt;
    auto dfs = [&](auto dfs, i64 u, i64 f)->void {
        for (auto v : g[u]) {
            if (v == f)continue;
            dis[v] = dis[u] + 1;
            fa[v] = u;
            dfs(dfs, v, u);
        }
        };

    dfs(dfs, 1, 1);
    for (i64 c = n;c != 1;c = fa[c]) {
        path.push_back(c);
        pt.insert(c);
    }

    path.push_back(1);
    pt.insert(1);
    reverse(all(path));

    for (int i = 1;i <= n;i++) {
        du[i] = { g[i].size(),i };
        if (du[i].fi == 1) {
            if (pt.count(i))continue;
            if (dis[i] % 2 == 1) {
                odd.push_back(i);
            } else {
                eve.push_back(i);
            }
        }
    }

    i64 osz = odd.size(), esz = eve.size();
    vector<pll>ans;
    // de(osz)deb(esz);
    if (osz) {
        i64 node = odd.back();
        odd.pop_back();
        ans.push_back({ 2, node });

        osz--;
        i64 f = fa[node];
        du[f].fi--;
        if (!pt.count(f) && du[f].fi == 1) {
            esz++;
            eve.push_back(f);
        }
    } else if (esz) {
        i64 node = eve.back();
        eve.pop_back();
        ans.push_back({ 2, node });

        esz--;
        i64 f = fa[node];
        du[f].fi--;
        if (!pt.count(f) && du[f].fi == 1) {
            osz++;
            odd.push_back(f);
        }
    }


    i64 parity = 0;
    while (osz || esz) {
        ans.push_back({ 1,0 });
        parity = 1 - parity;
        if (parity == 1 && esz > 0) {
            i64 node = eve.back();
            eve.pop_back();
            ans.push_back({ 2, node });

            esz--;
            i64 f = fa[node];
            du[f].fi--;
            if (!pt.count(f) && du[f].fi == 1) {
                osz++;
                odd.push_back(f);
            }
        } else if (parity == 0 && osz > 0) {
            i64 node = odd.back();
            odd.pop_back();
            ans.push_back({ 2, node });

            osz--;
            i64 f = fa[node];
            du[f].fi--;
            if (!pt.count(f) && du[f].fi == 1) {
                esz++;
                eve.push_back(f);
            }
        }
    }
    if (parity == 1) {
        ans.push_back({ 1,0 });
        parity = 1 - parity;
    }
    ans.push_back({ 1,0 });
    i64 psz = path.size();
    for (int i = 0;i < psz - 2;i++) {
        ans.push_back({ 2,path[i] });
        ans.push_back({ 1,0 });
    }
    i64 ssz = ans.size();
    cout << ssz << endl;
    for (int i = 0;i < ssz;i++) {
        i64 op = ans[i].fi;
        if (op == 1) {
            cout << 1 << endl;
        } else {
            cout << 2 << " " << ans[i].se << endl;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}