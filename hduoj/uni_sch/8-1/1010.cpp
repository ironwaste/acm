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

using lb = long double;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 2025.08.01——16:35:50
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    vector<i64>x(n + 1);
    for (int i = 1;i <= n;i ++) { cin >> x[i]; }
    vector<long double>dp(n + 10);
    dp[n] = n;

    for (i64 i = n - 1;i;i--) {
        long double v = (lb)x[i];
        long double p = 1.0 * ((lb)1000.0 - v) / 1000;
        long double q = ((lb)1.0 * v) / 1000;
        dp[i] = min(dp[i + 1], (dp[i + 1] + 20) * q + (lb) (i) *p);
    }
    printf("%.10Lf\n",dp[1]);
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