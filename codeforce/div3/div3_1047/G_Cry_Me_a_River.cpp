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

// https://codeforces.com/contest/2137/problem/G
/*
 *
 * 
 *
*/

void solve() {
    i64 n, m, q;
    cin >> n >> m >> q;
    vector<i64>g[n + 1];
    vector<i64>dijcry(n + 1, 0), dijri(n + 1, 0), du(n + 1, 0);
    for (int i = 0;i < m;i++) {
        i64 u, v;
        cin >> u >> v;
        g[v].push_back(u);
        du[u]++;
    }
    vector<i64>cry(n + 1, 1), river(n + 1, 1);
    while (q--) {
        i64 op, u;
        cin >> op >> u;
        if (op == 2) {
            if (cry[u]) { cout << "YES\n"; } else { cout << "NO\n"; }
            continue;
        }
        queue<pll>q;
        if(cry[u] == 1)q.push({ u,0 });
        if(river[u] == 1)q.push({ u,1 });
        // cry[u] = 0;
        river[u] = 0;

        while (!q.empty()) {
            auto& [u, w] = q.front();
            q.pop();
            if(w){
                for (auto v : g[u]) {
                    if (!cry[v])continue;
                    du[v]--;
                    if (du[v] == 0) {
                        q.push({ v,0 });
                        // cry[v] = 0;
                    }
                }
            } else {
                if (cry[u] == 0)continue;
                cry[u] = 0;
                for (auto v : g[u]) {
                    if (river[v] == 0)continue;
                    river[v] = 0;
                    q.push({ v,1 });
                }
            }
        }
    }


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

/*
图：
3 8
3 2
6 7
4 7
1 7
2 8
1 4
1 2
6 8
7 2
9 5
3 5
1 5
3 7
4 6
8 5
6 2
2 5
7 8
7 5
3 9
3 4
1 9
4 2
9 7
9 2
4 5
6 5
3 1
1 8
4 9
3 6
9 8
9 6
4 8
1 6

*/