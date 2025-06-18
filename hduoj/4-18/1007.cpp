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


void solve() {
    i64 n;
    cin >> n;
    vector<vector<pair<i64, pair<i64, i64 > > > >g(n);
    set<i64>st;
    map < pll, i64 > mp;
    for (int i = 0;i < n - 1;i++) {
        i64 u, v, p, q;
        cin >> u >> v >> p >> q;
        u--, v--;
        mp[{u, v}] = p;
        mp[{v, u}] = q;
        g[u].push_back({ v,{ p,q } });
        g[v].push_back({ u,{ q,p } });
    }
    i64 s, t;
    cin >> s >> t;
    s--, t--;
    vector<i64>path;
    auto dfs = [&](auto self, i64 fa, i64 u) ->bool {
        if (u == t) {
            path.pb(u);
            st.insert(u);
            return true;
        }
        for (auto k : g[u]) {
            i64 v = k.fi, p = k.se.fi, q = k.se.se;
            if (fa == v) { continue; }
            if (self(self, u, v)) {
                path.pb(u);
                st.insert(u);
                return true;
            }
        }
        return false;
        };
    dfs(dfs, s, s);
    auto mxdfs = [&](auto self, i64 fa, i64 u)->i64 {
        i64 mx = 0;
        for (auto k : g[u]) {
            i64 v = k.fi, p = k.se.fi, q = k.se.se;
            if (fa == v || st.count(v)) { continue; }
            mx += max(0LL, self(self,u,v) + p + q);
        }
        return mx;

        };
    // vector<i64>ans(n,0);
    i64 ans = 0;
    for (auto x : path) {
        ans += mxdfs(mxdfs, x, x);
        // de(x)deb(ans)
        // de(x)deb(ans);
    }
    // mxdfs(s, s);// 用于求ss 的最大值，并且留下地图
    int sz = path.size();
    for (int i = sz-1;i;i --) {
        i64 u = path[i], v = path[i - 1];
        ans += mp[{u, v}];
    }
    cout << ans << endl;
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