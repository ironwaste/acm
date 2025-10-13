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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://codeforces.com/contest/1209/problem/D
// 网址：
// 2025.09.19——21:58:02
// 2025.09.19——22:51:28 accpted
/*
 *
 *  这题我也不会 斯 有点东西
 *  感觉这题很典型
 *  
 *  图的匹配 判断联通分量的大小
 *
*/

void solve(){
    i64 n, k;
    cin >> n >> k;
    // vector<pll>a(n);
    vector<i64>g[n + 1];
    for (int i = 0;i < k;i++) {
        i64 v,u;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    i64 ans = 0;
    vector<i64>vis(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        if (!vis[i]) {
            queue<i64>q;
            q.push(i);
            vis[i] = 1;
            i64 cnt = 0;
            while (!q.empty()) {
                i64 u = q.front();
                q.pop();
                for (auto v : g[u]) {
                    if (vis[v])continue;
                    q.push(v);
                    vis[v] = 1;
                    cnt++;
                }
            }
            ans += cnt;
        }
    }
    cout << k - ans << endl;
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