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

// 2025.08.28——17:11:27
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>g[n + 1];
    vector<i64>du(n + 1, 0);
    for (int i = 1;i < n;i ++) {
        i64 u,v;
        cin >> u >> v;
        du[u]++, du[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    i64 ok = 0;
    for (auto x : du) {
        if (x > 2)ok = 1;
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    vector<i64>fa(n + 1, 0), dis(n + 1, 0);
    i64 faru = 0;

    auto bfs = [&](i64 st)->void {
        queue<pll>q;
        q.push({ st ,0 });
        i64 c = 0;

        while (!q.empty()) {
            auto [u, f] = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (v == f)continue;
                dis[v] = dis[u] + 1;
                q.push({ v, u });
                fa[v] = u;
                if (dis[v] > dis[c]) { c = v; }
            }
        }
        faru = c;
        };

    bfs(1);
    // de(faru);
    fa[faru] = 0;
    bfs(faru);
    // deb(faru);
    vector<i64>path;
    // for (int i = 0;i <= n;i ++) {
    //     de(i)deb(fa[i]);
    // }
    for (i64 v = faru;v != 0;v = fa[v]) { path.push_back(v); }
    i64 sz = path.size(),ansc = 0,ansb,ansa;
    for (int i = 0;i < sz;i ++) {
        i64 v = path[i];
        if (du[v] > 2) {
            ansb = v;
            for (auto u : g[v]) {
                if (i + 1 < sz && i-1 >= 0) {
                    if (u != path[i + 1] && u != path[i - 1]) { ansa = path[i + 1];ansc = u;break; }
                } else if(i - 1 >= 0 && i + 1>= sz) {
                    if (u != path[i - 1]) { ansa = path[i - 1];ansc = u;break; }
                } else if (i - 1 < 0 && i + 1 < sz) {
                    if (u != path[i + 1] ) { ansa = path[i + 1];ansc = u;break; }
                }
            }
            if (ansc)break;
        }
    }
    cout << ansa << " " << ansb << " " << ansc << endl;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}