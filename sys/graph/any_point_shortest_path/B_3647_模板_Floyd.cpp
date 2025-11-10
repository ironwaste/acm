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
i64 inf = INT_MAX;
// 补题——题目链接: https://www.luogu.com.cn/problem/B3647
// 网址：
// 2025.11.10——20:25:02
/*
 * floyd
 *
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>>dis(n, vector<i64>(n, inf));
    for (int i = 0;i < m;i++) {
        i64 u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        dis[u][v] = min(d,dis[u][v]);
        dis[v][u] = min(d,dis[v][u]);
    }

    for (int k = 0;k < n;k++) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (i == j)cout << 0 << " ";
            else {
                cout << dis[i][j] << " ";
            }
        }cout << endl;
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