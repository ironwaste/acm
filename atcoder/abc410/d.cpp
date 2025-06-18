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

using pii = pair<int, int>;
using pll = pair<i64, i64>;


void solve() {
    i64 n, h, m;
    cin >> n >> h >> m;
    vector<pii>ab(n);
    for (int i = 0;i < n;i++) {
        cin >> ab[i].fi >> ab[i].se;
    }

    vector<i64>dp(3010, 4000);
    dp[0] = 0;
    for (int i = 0;i < n;i++) {
        vector<i64>ndp(3010, 4000);
        i64 ok = 0, a = ab[i].fi, b = ab[i].se;
        for (int j = h;j >= 0;j--) {
            if ((j + a) <= h && dp[j] <= m) {
                ok = 1;
                ndp[j + a] = min(dp[j], ndp[j + a]);
            }
            if ((dp[j] + b) <= m) {
                ok = 1;
                ndp[j] = min(ndp[j], dp[j] + b);
            }
        }
        // deb(ok)
        dp = ndp;
        if (ok == 0) {
            cout << i << endl;
            return ;
        }
    }
    cout << n << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}