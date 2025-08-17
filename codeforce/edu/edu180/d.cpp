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


// 改正后的条件 ： 
// 正好半小时 -> 思路 wa 2 了
void solve(){
    int n;
    cin >> n;
    vector<vector<i64> >g(n);
    vector<i64>du(n, 0);
    for (int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    // if (n <= 2) { cout << "NO\n"; return; }
    int root = -1;
    for (int i = 0;i < n;i++) {
        du[i] = g[i].size();
        // if (du[i] == 1) { root = i; break; }
    }
            
    for (int i = 0;i < n;i++) {
        if (du[i] == 2) {
            root = i;break;
        }
    }
    if (root == -1) { cout << "NO\n"; return; }

    int cifa = g[root][0];
    int fa = g[root][1];
    // de(root)deb(cifa)

    vector<i64>vis(n, 0);
    vis[root] = 1;
    vis[fa] = 1;
    vis[cifa] = 1;
    cout << "YES\n";
    cout << cifa + 1 << " " << root + 1 << endl;
    cout << root + 1 << " " << fa + 1 << endl;
    queue<pii>q;
    // 0 is 被指向 1 是 指向别人的
    // cout << "YES\n";
    q.push({ fa,0 });
    q.push({ cifa,1 });
    while (!q.empty()) {
        pii tmp = q.front();
        q.pop();
        int u = tmp.fi, w = tmp.se;
        for (auto x : g[u]) {
            if (!vis[x]) {
                q.push({ x,1 - w });
                vis[x] = 1;
                if (w == 1) {
                    cout << u + 1 << " " << x + 1 << endl;
                } else {
                    cout << x+1 << " " << u+1 << endl;
                }
            }
        }
    }

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