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

// 2025.07.21——22:24:16
/*  https://www.luogu.com.cn/problem/P5908
 *
 *
 *
*/

void solve(){
    int n, d;
    cin >> n >> d;
    vector<vector<i64> >g(n);
    for (int i = 0;i < n - 1;i ++) {
        i64 u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    i64 ans = 0;
    queue<pll>q;// 第一个为点，第二个为距离
    vector<i64>vis(n, 0);
    vis[0] = 1;
    q.push({ 0, 0 });
    while (!q.empty()) {
        auto [u, dd] = q.front();
        q.pop();
        if (d < dd) break;
        ans++;
        for (auto v : g[u]) {
            if (vis[v])continue;
            // if(d =)
            q.push({v,dd+1LL});
            vis[v] = 1;
        }
    }
    cout << ans - 1 << endl; //减去自己即可
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}