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

// 2025.08.24——23:36:45
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n + 1);
    i64 sum = 0;
    for (int i = 1;i <= n;i++) { cin >> a[i]; sum += a[i]; }

    vector<pll>dp(n + 10, { INT_MAX,INT_MAX });
    // fi 没被砍
    // se 被砍
    dp[1].fi = a[1];
    dp[1].se = INT_MAX;
    for (i64 i = 2;i <= n;i++) {
        dp[i].se = min(dp[i - 1].se + a[i] - 1, dp[i - 1].fi + max(0LL, a[i] - i + 1));
        dp[i].fi = min(dp[i - 1].se, dp[i - 1].fi) + a[i];

    }
    i64 vv = min(dp[n].fi, dp[n].se);
    cout << vv << endl;

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