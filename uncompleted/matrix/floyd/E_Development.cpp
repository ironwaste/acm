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
i64 inf = 1e17;
// 补题——题目链接: https://atcoder.jp/contests/abc416/tasks/abc416_e
// 网址：
// 2025.11.11——15:03:58
/*
 *
 *
 *
*/



void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64> > dis(n + 2, vector<i64>(n + 2, inf));
    for (int i = 0;i < m;i++) {
        i64 u, v, d;
        cin >> u >> v >> d;
        dis[u][v] = min(dis[u][v], d);
        dis[v][u] = min(dis[v][u], d);
    }
    i64 k, ft;
    cin >> k >> ft;
    for (int i = 0;i < k;i++) {
        i64 u;
        cin >> u;
        dis[u][n + 1] = ft;
        dis[n + 1][u] = 0;
    }
    for (int i = 0;i < n + 1;i++) {
        dis[i][i] = 0;
    }



    for (int k = 1;k < n + 2;k++) {
        for (int i = 1;i < n + 2;i++) {
            for (int j = 1;j < n + 2;j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }


    i64 q;
    cin >> q;
    while (q--) {
        i64 op, u, v, t;
        cin >> op;
        if (op == 1) {
            cin >> u >> v >> t;
            dis[u][v] = min(dis[u][v], t);
            dis[v][u] = min(dis[v][u], t);
            for (int k : {u, v}) {
                for (int y = 1;y <= n + 1;y++) {
                    for (int x = 1;x <= n + 1;x++) {
                        dis[y][x] = min(dis[y][k] + dis[k][x], dis[y][x]);
                    }
                }
            }
        } else if (op == 2) {
            cin >> u;
            dis[u][n + 1] = min(ft, dis[u][n + 1]);
            dis[n + 1][u] = min(dis[n + 1][u], 0LL);
            for (int k : {u, n + 1}) {
                for (int y = 1;y <= n + 1;y++) {
                    for (int x = 1;x <= n + 1;x++) {
                        dis[y][x] = min(dis[y][k] + dis[k][x], dis[y][x]);
                    }
                }
            }
        } else if(op == 3){
            i64 sum = 0;
            for (int i = 1;i < n + 1;i++) {
                for (int j = 1;j < n + 1;j++) {
                    if (dis[i][j] != inf && dis[i][j] != 0) {
                        sum += dis[i][j];
                    }
                }
            }
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