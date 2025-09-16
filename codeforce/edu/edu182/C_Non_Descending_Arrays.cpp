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

// 2025.09.15——23:00:36
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    vector<array<i64, 2> > a(n + 1, { 0,0 });
    vector<array<i64, 2> > dp(n + 1, { 0,0 });
    dp[0][0] = 1;
    for (int i = 1;i <= n;i ++) {cin >> a[i][0];}
    for (int i = 1;i <= n;i ++) {cin >> a[i][1];}
    // i64 xr = 0;
    for (int i = 1;i <= n;i ++) {
        i64 v1 = a[i][0], v2 = a[i][1];
        i64 prev1 = a[i - 1][0], prev2 = a[i - 1][1];
        i64 mx = max(prev1, prev2);
        if (v1 >= mx && v2 >= mx) {
            (dp[i][0] = dp[i - 1][0] * 2LL) %= mod3;
            (dp[i][1] = dp[i - 1][1] * 2LL) %= mod3;
        } else{
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1]; 
        }
    }
    cout << (dp[n][0] + dp[n][1]) % mod3 <<endl;

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