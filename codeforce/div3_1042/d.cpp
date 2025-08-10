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

// 2025.08.10——22:54:39
/*
 * 判断 du 为1的节点 ，去找拥有最多du为1的节点的个数
 * 然后 剩下的du为1的节点的个数就是解
 *
*/

void solve() {
    int n;
    cin >> n;
    vector<i64>du(n, 0);
    vector<vector<i64> >g(n);
    i64 cnt = 0, mx = 0;
    for (int i = 1;i < n;i ++) {
        i64 u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        du[u]++;
        du[v]++;
    }
    for (int i = 0;i < n;i ++) {
        if (du[i] == 1) {
            cnt++;
        }
    }
    for (int i = 0;i < n;i ++) {
        i64 mcnt = 0;
        for (auto v : g[i]) {
            if (du[v] == 1)mcnt++;
        }
        if (du[i] == 1)mcnt++;
        mx = max(mx, mcnt);
    }
    // de(cnt)deb(mx)
    cout << cnt - mx << endl;
    // deb(cnt - mx);
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