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


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<i64> >g(n);
    for (int i = 0;i < m;i ++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<i64>du(n, 0);
    // i64 mx = 0;, mxid = 0;
    priority_queue<pii>q;
    for (int i = 0;i < n;i++) {
        du[i] = g[i].size();
        if(du[i] > 2)q.push({ du[i],i });
    }
    // deb(1)
    queue<i64>que;
    vector<i64>vis(n, 0);
    i64 ans = 0;
    while (!q.empty()) {
        deb(2)
        while (!q.empty()) {
            int u = q.top().se;
            if (du[u] > 2 && !vis[u]) {
                que.push(u);
                break;
            }
            q.pop();
        }
        while (!que.empty()) {
            i64 u = que.front();
            vis[u] = 1;
            que.pop();
            for (auto v : g[u]) {
                if (vis[v]) { continue; } else if (du[v] > 2) {
                    vis[v] = 1;
                    ans++;
                    if (du[v] > 3 && du[u] > 2) {
                        du[u]--, du[v]--;
                        que.push(du[v]);
                    } else if (du[v] == 3 && du[u] > 2) {
                        du[u]--, du[v]--;
                    }
                }
            }
        }
    }
    i64 cnt0 = 0, cnt1 = 0;

    if ((cnt1 && cnt1 > 3) || (cnt1 && cnt0)) {
        ans += cnt1 / 2 + (cnt0);
    } else if (cnt0 >= 3) {
        ans += cnt0;
    } else if (cnt0 && cnt1 == 0) {
        ans += cnt0 + 2;
    }
    
    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}