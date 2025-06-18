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
    int n, k;
    double P;
    cin >> P >> n >> k;
    vector<double> dism, disp;

    for (int i = 0;i < n;i++) {
        int t, p;
        cin >> t >> p;
        if (t == 0)dism.pb(p);
        else disp.pb(p);
    }

    vector<double>dp(k + 2, 2e9);
    dp[0] = P;
    
    // for (int i = 0;i <= k;i++) { de(i)deb(dp[i]); }

    for (auto x : dism) {
        for (int i = k; i;i--) {
            if (dp[i - 1] != 1e9 + 10) {
                dp[i] = max(0.00, min(dp[i], 1.0 * dp[i - 1] * x / 10.0));
                
            }
        }
    }

    // for (int i = 0;i <= k;i++) { de(i)deb(dp[i]); }

    for (auto x : disp) {
        for (int i = k;i;i--) {
            if (dp[i - 1] != 1e9 + 10)dp[i] = max(0.00,min(dp[i],1.0 * dp[i - 1] - x));
        }
    }
    // cout << endl;
    // for (int i = 0;i <= k;i++) { de(i)deb(dp[i]); }
    // cout.precision(2);
    // cout << dp[k] << endl;
    printf("%.02lf\n", dp[k]);
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