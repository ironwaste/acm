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
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64> >a(m, vector<i64>(n, 0LL));
    vector<vector<pll> >mx(n, vector<pll>(2,{0LL,0LL}));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> a[j][i];
            if (mx[i][0].fi <= a[j][i]) {
                mx[i][1] = mx[i][0];
                mx[i][0] = { a[j][i],j };
            } else if (mx[i][1].fi < a[j][i]) {
                mx[i][1] = { a[j][i],j };
            }
        }
    }
    // deb(m)
    // a[][] fi 是 食物序号 ，第二个是 人的序号
    // mx[][] 第二个下标应该是 人的下标

    vector<vector<i64> >dp(n+10, vector<i64>(n+10, 0LL));
    // deb(m)
    for (int i = 0;i < m;i++) { // 选中第 i 个 作为 x
        for (int j = 0;j < n;j++) {
            i64 cntx = a[i][j], cnt = 0;
            pll mx1 = mx[j][0], mx2 = mx[j][1];
            if (mx1.se == i) {
                cnt = mx2.fi;
            } else {
                cnt = mx1.fi;
            }
            for (int k = 0;k < j;k++){
                dp[j][k + 1] = max(dp[j][k] + cntx, dp[j][k + 1]);
                dp[j][k + 1] = max(dp[j][k + 1] + cnt, dp[j][k + 1]);
            }   
        }
    }

    i64 ans = 0;
    for (int j = 0;j < n;j ++) {
        ans = max(dp[j][n], ans);
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