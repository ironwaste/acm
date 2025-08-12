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

// 2025.08.12——15:40:27
/*
 *
 *
 *
*/
const int mod = 12345;
void solve(){
    int n;
    cin >> n;
    vector<vector<i64> >dp(2, vector<i64>(n + 10, 0));
    dp[1][1] = 1;
    dp[0][1] = 8;
    for (int i = 2;i <= n;i++) {
        dp[0][i] = dp[1][i - 1] + 9 * dp[0][i - 1];
        dp[1][i] = 9 * dp[1][i - 1] + dp[0][i - 1];
        dp[0][i] %= mod;
        dp[1][i] %= mod;
    }
    cout << dp[0][n] << endl;
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