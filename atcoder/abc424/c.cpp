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

// 2025.09.20——20:07:09
// 2025.09.20——20:22:12 ac
/* https://atcoder.jp/contests/abc424/tasks/abc424_c
 *
 *
 *
*/

void solve() {
    i64 n;cin >> n;
    vector<i64>fa(n + 1);
    iota(all(fa), 0);
    vector<pll>a(n);
    vector<i64>vec[n + 1];
    unordered_set<i64>st;
    vector<i64>vis(n + 1, 0);
    i64 cnt = 0;
    queue<i64>q;
    for (int i = 0;i < n;i++) {
        i64 x, y;
        cin >> x >> y;
        a[i].fi = x, a[i].se = y;
        if (x == y && x == 0) {
            st.insert(i + 1);
            vis[i + 1] = 1;
            cnt++;
            q.push(i + 1);
        }else {
            vec[x].push_back(i + 1);
            vec[y].push_back(i + 1);
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : vec[u]) {
            if (vis[v])continue;
            vis[v] = 1;
            cnt++;
            q.push(v);

        }

    }

    
    cout << cnt << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}