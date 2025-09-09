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


// 补题——题目链接: https://codeforces.com/contest/2134/problem/D
// 网址：
// 2025.09.05——23:47:52
// 2025.09.06——00:03:18 accpted
/*
 *
 * 树的直径 找出树的直径路径即可
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>g[n + 1], du(n + 1, 0);
    for (int i = 1;i < n;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        du[u]++, du[v]++;
    }
    i64 root = 1;
    vector<i64>fa(n + 1, 0), path, dis(n + 1, 0);
    function<void(i64, i64)>dfs;
    dfs = [&](i64 u, i64 f) ->void {
        for (auto v : g[u]) {
            if (v == f)continue;
            fa[v] = u;
            dis[v] = dis[u] + 1;
            if (dis[v] > dis[root])root = v;
            dfs(v, u);
        }
        };
    // de(root);    
    dfs(1, 1);

    fa[root] = -1;
    dis[root] = 0;
    dfs(root, root);
    i64 b = -1,a,c;
    set<i64>dia;
    // de(root);

    for (i64 i = 0, st = root; st != -1;st = fa[st], i++) {
        path.push_back(st);
        dia.insert(st);
        if (du[st] > 2) { b = i; }
    }
    if (b == -1) {
        cout << b << endl;
        return;
    }b = path[b];
    for (auto v : g[b]) {
        if (dia.count(v)) {
            a = v;
        } else {
            c = v;
        }
    }
    cout << a << " " << b << " " << c << endl;
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