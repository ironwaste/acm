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


void solve(){
    i64 n, k;
    cin >> n >> k;
    // i64 ans = 0LL;
    // vector<>
    vector< vector<i64> > a(n+2,vector<i64>(k+2,0)),dp(n+2,vector<i64>(k+2,0) );

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= k;j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1;i <= k;i++) {
        for (int j = 1;j <= n;j++) {
            dp[j][i] = max(max(dp[j - 1][i - 1] + a[j][i], dp[j - 1][i] + a[j][i]), dp[j][i-1]);
        }
    }



    // cout << "-------------------" << endl;
    // for (int j = 1;j <= k;j++) {
    //     for (int i = 1;i <= n;i++) {
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }

    i64 ans = 0;
    for (int i = 0;i <= k;i ++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
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