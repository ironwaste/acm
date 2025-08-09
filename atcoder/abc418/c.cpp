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

// 2025.08.09——20:44:16
// 2025.08.09——21:17:28 accepted
/*
 * 有偶数个零就是 完美字串 但是字符串长度为 2e5 n^ 2 不可以
 * 所以需要记录所有的为偶数的0的位置
 *
 * 按照位置存储 0的个数 ？
 * 存储到该位置 有多少个位置到这里时 不加当前位 是奇数个0
 * 如果 当前位置是0 的话，则 直接加上 当前位上奇数个0 的个数
 * 且从这里开始 奇数零的个数 和 偶数零的个数 交换了
 *
 * 如果 是 1 的话，则 根据上一位是奇数还是偶数 来加
 * 并且寻找和 当前这个 1  的时候的 奇偶性 相同的 0 的个数
*/

void solve() {
    i64 n;
    string t;
    cin >> n >> t;
    t = ' ' + t;
    // deb(t)
    // i64 poscnt2 = 0, poscnt1 = 0;
    // 偶数个零的位置 0 也是偶数
    // 和奇数个0的位置
    i64 ans = 0,parity = 0;
    vector<vector<i64> >dp(2, vector<i64>(n + 10, 0));
    dp[0][0] = 1;// 0 
    // dp[1][0] = 0;
    for (int i = 1;i <= n;i++) {
        if (t[i] == '1') {

            ans += dp[parity][i - 1];
            dp[parity][i] = dp[parity][i - 1] + 1;
            dp[1 - parity][i] = dp[1 - parity][i - 1];
        } else if (t[i] == '0') {
            ans += dp[1 - parity][i - 1];
            dp[1 - parity][i] = dp[1 - parity][i - 1] + 1;
            dp[parity][i] = dp[parity][i - 1];
            parity = 1 - parity;
        }
    }
    // for (int i = 0;i <= n;i++) {
    //     cout << dp[0][i] << ' ';
    // }cout << endl;

    // for (int i = 0;i <= n;i++) {
    //     cout << dp[1][i] << ' ';
    // }cout << endl;
    cout << ans << endl;
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