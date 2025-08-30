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

// 2025.08.28——23:05:36
// 2025.08.29——00:00:22 accpted
/*
 *
 *
 *
*/

void solve() {

    i64 n;
    cin >> n;
    vector<i64>a(n + 1), num(n + 1, 0), idx(n + 1, 0);
    vector<i64>g[n + 1];
    // map<i64, vecter<i64>>cnt;
    for (int i = 1;i <= n;i ++ ) {
        i64 x;
        cin >> x;
        a[i] = x;
        g[x].push_back(i);
        idx[i] = num[x] ++;
        // num[x]++;
    }

    vector<i64>dp(n + 1, 0);

    for (int i = 1;i <= n;i ++) {
        i64 v = a[i], id = idx[i];
        i64 preidx = id - v + 1;
        if (preidx >= 0) {
            i64 preid = g[v][preidx] - 1;
            dp[i] = max(dp[i], dp[preid] + v);
        }
        dp[i] = max(dp[i],dp[i - 1]);
    }
    cout << dp[n] << endl;




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