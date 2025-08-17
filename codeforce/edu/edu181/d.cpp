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

// 2025.07.22——23:05:39
/*
 *
 *
 *
*/
i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1LL)res = res * a % mod3;
        a = a * a % mod3;
        b >>= 1LL;
    }
    return res % mod3;
}


i64 inv(i64 x) {
    return pw(x, mod3 - 2LL) % mod3;
}

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<array<i64, 4> > lrpq(n);
    vector<i64>dp(m + 10, 0LL);
    dp[0] = 1LL;
    for (int i = 0LL; i < n;i++) {
        i64 p, q;
        cin >> lrpq[i][0] >> lrpq[i][1] >> p >> q;
        lrpq[i][2] = p, lrpq[i][3] = q;
        dp[0] = dp[0] * (q - p) % mod3 *inv(q) % mod3;
    }
    sort(all(lrpq));
    for (int i = 0;i < n;i ++) {
        auto [l, r, p, q] = lrpq[i];
        // de(l)de(r)de(p)deb(q);
        dp[r] = (dp[r] + (dp[l - 1] * p % mod3 * inv(q-p) ) % mod3) % mod3;
    }
    cout << dp[m] % mod3 << endl;
}
// 2025.07.22——23:47:29 accpted

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1LL;
    // cout << 5LL * inv(18LL) % mod3 << endl;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}