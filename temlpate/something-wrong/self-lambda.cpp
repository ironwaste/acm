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

// 补题——题目链接: https://www.luogu.com.cn/problem/P1099
// 网址：
// 2025.09.04——07:57:34
/*
 *
 *
 *
*/

void solve() {
    i64 n, s;
    cin >> n >> s;
    vector<pll>E[n + 1];
    map<pll, i64>mp;
    for (int i = 1;i < n;i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
        mp[{v, u}] = w;
        mp[{u, v}] = w;
    }

    i64 root = 1;
    vector<i64>fa(n + 1, -1), dis(n + 1, 0);
    auto dfs = [&](auto self, i64 u, i64 f)->i64 {
        for (auto &&[v, w] : E[u]) {
            if (v == f)continue;
            fa[v] = u;
            dis[v] = dis[u] + w;
            i64 c = self(self, v, u);
        }
        return dis[root];
        };
    fa[root] = -1;
    i64 len = dfs(dfs, root, 1);
    vector<i64>path;
    for (i64 st = root;st != -1;st = fa[st]) {
        path.push_back(st);
    }

    vector<i64>dp(n + 1, 0);
    auto dfs2 = [&](auto self, i64 u, i64 f)->void {
        // dp[u] = 1;
        for (auto &&[v, w] : E[u]) {
            if (v == f)continue;
            dp[u] = max(dp[v] + w,dp[u]);
            self(self, v, u);
        }
        return;
        };
    dfs2(dfs2, root, root);

    i64 idx1 = -1, idx2 = -1;
    i64 sz = path.size();

    vector<i64>is(n + 1, 0);
    for (i64 i = 0, mid = 0;i < sz - 1;i++) {
        i64 u = path[i], v = path[i + 1];
        i64 w = mp[{u, v}];
        mid += w;
        if (len % 2 == 1 && mid * 2 - 1 == len) {
            idx1 = i, idx2 = i;
            is[i] = 1;
        } else if ((mid - w) * 2 < len && (mid * 2) > len) {
            idx1 = i, idx2 = i + 1;
            if (s < w) {
                i64 ww = len - mid + 2;
                cout << min(ww,mid) << endl;
                return;
            } else {
                is[i] = 1, is[i + 1] = 1;
                s -= w;
            }
        }
    }
    for (;idx1 > 0 || idx2 < sz - 1;) {
        i64 w1 = LLONG_MAX, w2 = LLONG_MAX;
        i64 u1 = -1, v1 = -1, u2 = -1, v2 = -1;
        if (idx1 > 0) {
            u1 = path[idx1], v1 = path[idx1 - 1];
            w1 = mp[{u1, v1}];
        }
        if (idx2 < sz - 1) {
            u2 = path[idx2], v2 = path[idx2 + 1];
            w2 = mp[{u2, v2}];
        }
        if (s < w1 && s < w2) { break; }
        if (u1 != -1 && v2 != -1) {
            if (dp[u1] >= dp[u2] && w1 <= s) {
                s -= w1;
                is[--idx1] = 1;
            } else if (dp[u2] >= dp[u1] && w2 <= s) {
                s -= w2;
                is[++idx2] = 1;
            }
        } else if (u1 != -1) {
            if (w1 <= s) {
                s -= w1;
                is[--idx1] = 1;
            }
        } else if (u2 != -1) {
            if ( w2 <= s ) {
                s -= w2;
                is[++idx2] = 1;
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}