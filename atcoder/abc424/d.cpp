// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#include<bits/stdc++.h>
#include<climits>


#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
// #define int long long
#define fi first
#define se second

#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using pii = pair<int, int>;
using pll = pair<int, int>;

// 2025.09.20——20:22:37
/* https://atcoder.jp/contests/abc424/tasks/abc424_d
 *
 *
 *
*/

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string>s(h);
    vector<int>init(h);
    for (int i = 0;i < h;i++) {
        cin >> s[i];
        int m = 0;
        for (int j = 0;j < w;j++) {
            m |= (int)(s[i][j] == '#' )<< j;
        }
        init[i] = m;
        // deb(m);
    }
    const int N = 1LL << w;
    vector<int>dp(N, INT_MAX);
    auto ndp = dp;
    auto fresh = ndp;
    // 0 shi 白 1 是 黑

    for (int i = 0;i < N;i++) {
        // 原本是白的 不能是黑的
        if ((i & ~init[0]) != 0)continue;
        dp[i] = __builtin_popcount(init[0]) - __builtin_popcount(i);
    }

    for (int i = 1;i < h;i ++) {
        ndp = fresh;
        for (int pm = 0;pm < N;pm ++) {
            if (dp[pm] == INT_MAX)continue;
            for (int cm = 0;cm < N;cm ++) {
                if ((cm & ~init[i]) != 0)continue;
                int v = ((pm & (pm >> 1)) & (cm & (cm >> 1)));
                // 出现2 * 2 黑块 v 不为0 的时候
                if (v != 0)continue;
                ndp[cm] = min(ndp[cm], dp[pm] +
                    __builtin_popcount(init[i]) - __builtin_popcount(cm));
            }
        }
        dp = ndp;
    }
    int ans = INT_MAX;
    for (int i = 0;i < N;i ++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}