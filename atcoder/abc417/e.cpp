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

// 2025.08.02——21:14:19
/*
 * 迪杰斯特拉 求最小路径
 *
*/

void solve() {
    i64 n, m, s,t;
    cin >> n >> m >> s >> t;
    vector<vector<i64> >g(n + 1);
    for (int i = 0;i < m;i ++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // for (auto& b : g) { sort(all(b)); }
    vector<i64>vis(n + 1, 0);
    priority_queue< vector<i64>,vector<vector<i64> >, greater<>>q;
    vector<i64>tmp;
    tmp.pb(s);
    q.push(tmp);
    while (!q.empty()) {
        auto vec = q.top();
        q.pop();
        i64 u = vec.back();
        if (u == t) {
            for (auto x : vec) {
                cout << x << " ";
            }
            cout << endl;
            return;
        }
        vis[u] = 1;
        i64 sz = vec.size();
        for (auto v : g[u]) {
            if (vis[v]) continue;
            vec.pb(v);
            q.push(vec);
            vec.erase(vec.begin() + sz, vec.end());
            // 数组中删除最后一个元素 ，需要的是 vec.begin() + sz 的方式进行
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