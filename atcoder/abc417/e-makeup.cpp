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


// 补题——题目链接:
// 网址：https://atcoder.jp/contests/abc417/tasks/abc417_e
// 2025.08.03——11:36:48
/*
 *
 *
 *
*/

void solve(){
    i64 n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<i64> > g(n + 1);
    for (int i = 0; i < m;i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (auto& vec : g) { sort(all(vec)); }

    vector<i64>vis(n + 1, 0), vvis(n + 1, 0);
    vis[s] = 1;
    vvis[s] = 1;
    vector<i64>ans;
    ans.pb(s);

    // 这样的时间复杂度 巨低 ，6ms 比迪杰斯特拉 快
    // 只需要遍历所有点即可
    auto dfs = [&](auto self, i64 u)->i64 {
        if (u == t) {
            for (auto v : ans) {
                cout << v << " ";
            }cout << endl;
            return 1;
        }
        i64 sz = ans.size();
        for (auto v : g[u]) {
            if (vis[v] && vvis[s])continue;
            ans.push_back(v);
            vis[v] = 1;
            if (self(self, v)) {
                return 1LL;
            }
            ans.erase(ans.begin() + sz, ans.end());
        }
        return 0LL;
        };

    dfs(dfs, s);


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