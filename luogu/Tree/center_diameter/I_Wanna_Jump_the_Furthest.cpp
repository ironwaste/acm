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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://ac.nowcoder.com/acm/contest/115999/D
// 网址：
// 2025.09.10——13:39:21
// 2025.09.10——13:56:10 通过率 96%
/*
 * set 的merge操作 s1.merge(s2);
 * s1 为取并
 * 而s2 将会变成取交集
 *
 * 不会的关键点在于（或者说是没能转化的点） ：
 * 第一次到达的直径的点 如果和第二次到达的直径的点有重合
 * 那么第二次就能够达到 两个集合都能够到达的并
*/

void solve(){
    i64 n, k;
    cin >> n >> k;
    vector<i64>g[n + 1];
    for (int i = 1;i < n;i ++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    i64 c = 0;
    function<void(i64, i64)>dfs;
    vector<i64>p, dis(n + 1, 0), fa(n + 1, -1);
    dfs = [&](i64 u, i64 f)->void {
        for (auto v : g[u]) {
            if (v == f) continue;
            fa[v] = u;
            dis[v] = dis[u] + 1;
            if (dis[v] > dis[c])c = v;
            dfs(v, u);
        }
        };
    dfs(1, 1);
    set<i64>s1, s2, s3;
    for (int i = 1;i <= n;i ++) {
        if (dis[i] == dis[c]) { s1.insert(i); }
    }
    fa[c] = -1;
    dis[c] = 0;
    dfs(c, c);
    for (int i = 1;i <= n;i ++) {
        if (dis[i] == dis[c]) { s2.insert(i); }
    }
    s3 = s1;
    auto ss = s2;
    s3.merge(ss);
    i64 sz1 = s1.size(), sz2 = s2.size(),sz3 = s3.size();
    i64 ok;
    // de(sz1)de(sz2)deb(sz3);
    if (sz3 == sz1 + sz2) {
        if (k % 2 == 1) {
            ok = 1;
        } else {
            ok = 2;
        }
    } else {
        ok = 0;
    }
    vector<i64>ans(n + 1, 0);
    if (ok == 1) {
        for (auto x : s1) {ans[x] = 1;}
    } else if (ok == 2) {
        for (auto x : s2) {ans[x] = 1;}
    } else {
        for (auto x : s3) { ans[x] = 1; }
    }
    for (int i = 1;i <= n;i ++) {
        cout << ans[i] << " \n"[i == n];
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