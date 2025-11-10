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
// 补题——题目链接: https://atcoder.jp/contests/abc416/tasks/abc416_e
// 网址：
// 2025.11.10——22:14:13
/*
 *
 *
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64> >dis(n, vector<i64>(n, inf));

    for (int i = 0;i < m;i++) {
        i64 u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        dis[u][v] = dis[v][u] = min(dis[u][v], c);
    }
    i64 k, t;
    cin >> k >> t;
    vector<i64>ver;
    for (int i = 0;i < k;i++) {
        i64 v;
        cin >> v;
        v--;
        ver.push_back(v);
    }

    for (int i = 0;i < k;i++) {
        i64 u = ver[i];
        for (int j = 0;j < k;j++) {
            i64 v = ver[j];
            if (i == j)continue;
            dis[u][v] = min(dis[u][v], t);
        }
    }


    for (int k = 0;k < n;k++) {
        for (int i = 0;i < n;i++) {
            for (int j = i + 1;j < n;j++) {
                if (dis[i][k] != inf && dis[k][j] != inf) {
                    dis[j][i] = dis[i][j]
                        = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    i64 sum = 0;
    for (int i = 0;i < n;i++) {
        dis[i][i] = 0;
        for (int j = 0;j < n;j++) {
            if (dis[i][j] != inf)sum += dis[i][j];
        }
    }

    i64 q;
    cin >> q;
    while (q--) {
        i64 op;
        cin >> op;
        if (op == 1) {
            i64 x, y, wt;
            cin >> x >> y >> wt;
            x--, y--;
            if (dis[x][y] < wt)continue;
            if (dis[x][y] == inf) dis[x][y] = 0;
            if (dis[y][x] == inf) dis[y][x] = 0;
            sum -= dis[x][y];
            sum -= dis[y][x];
            dis[x][y] = dis[y][x] = wt;
            sum += wt + wt;
            for (int i = 0;i < n;i++) {
                for (int j = 0;j < n;j++) {
                    i64 w = dis[i][x] + wt + dis[y][j];
                    if (dis[i][j] > w) {
                        if (dis[i][j] == inf) dis[i][j] = 0;
                        if (dis[j][i] == inf) dis[j][i] = 0;
                        sum -= dis[i][j];
                        sum -= dis[i][j];
                        sum += w * 2LL;
                        dis[i][j] = dis[j][i] = w;
                    }

                }
            }
        } else if (op == 2) {
            i64 x;
            cin >> x;
            x--;
            for (int i = 0;i < k;i++) {
                i64 u = ver[i];
                // deb(u);
                if (dis[x][u] > t) {
                    if (dis[u][x] == inf) dis[u][x] = 0;
                    if (dis[x][u] == inf) dis[x][u] = 0;
                    sum -= dis[u][x] * 2LL;
                    // de(sum);
                    sum += t * 2LL;
                    // deb(sum);
                    dis[u][x] = dis[x][u] = t;
                }

                for (int v = 0;v < n;v++) {
                    i64 wt = dis[u][v] + t;
                    // deb(v);
                    if (dis[x][v] > wt) {
                        if (dis[x][v] == inf) dis[x][v] = 0;
                        if (dis[v][x] == inf) dis[v][x] = 0;
                        sum -= dis[x][v] * 2LL;
                        // de(sum);
                        sum += (wt) * 2LL;
                        // deb(sum);
                        dis[x][v] = dis[v][x] = wt;
                    }
                }
            }
            k++;
            ver.push_back(x);
        } else {
            cout << sum << endl;
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