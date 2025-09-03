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

// 2025.07.11——21:17:01
/*
 * 先对于权值相同被遍历的直接true不再遍历
 * 然后对于进行dfs判断是否催你在有值
 * 在于简单路径中有小于等于的权值
*/


void solve() {
    int n;
    cin >> n;
    vector<i64>w(n);
    for (auto& x : w) { cin >> x; }
    vector<i64>g[n];
    for (int i = 0;i < n;i ++) {
        i64 u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<i64>vis(n, 0);
    set<i64>
    for (int i = 0;i < n;i++) {

        
    }

    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}