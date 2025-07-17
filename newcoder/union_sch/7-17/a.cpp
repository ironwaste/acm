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

// 2025.07.17——12:14:59
/*
 * 题目意思就是 ，我们可以知道-1为不知道天亮或者暗的天数
 * 都可以，然后1代表天亮，0代表不亮，
 * 我们现在需要计算这个数组最少可能是几天，也就是说连续的1可能代表的是一天，
 * 然后因为存在-1 所以可能有2 ^ k 个不同的数组
 * 所以可能会有 2^k个不同的结果 进行相加再模除一下998244353
 *
 * 很像一道概率dp一样的东西
 * 解题: 先假设所有的-1 为0
 * 当我们经过一个 -1 的时候,我们来计算当前改变成为1是否会减少个数
 * k 最多 5e5
 * 然后ans = ans 变全零会导致后面的计算都是减去的，但是如果变全一的话那么最终的值就是全增的
 * k11 + k10
 * -> (k11 + k10)
 *  k21 = k11 - check() + k10 - check();
 * check 的情况有
 * 1、 0 ？ 0 chek + 1 需要标定前面有多少个结尾为0 的
 * 2、 0 ？ 1 1 ？ 0 
 * 3、 1 ？ 1 check - 1 ?减去多少个1呢？也就是要标定前面有多少个结尾为1的
 * 所以最终要有两个表明的
 * 前面确定了的，后面的问号全部假定为了1LL
 *
 * 无需计算出，一开始有多少个，我们只需要判断前面的值然后加和就好
 *  0 1 ？ 0 1 ？ 0 ？ 0  ？ 1  ？ 1  ？ 0 ;
 *  0 1 1  1 2 
 *  0 1 1  1 2 
*/
void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n+2,0LL);
    for (int i = 1LL;i <= n;i++) { cin >> a[i]; }
    // i64 cnt0 = 0,ok = 0;
    // for (int i = 1;i <= n;i++) {
    //     i64 v = a[i];
        // if (v == -1) { v = 1; }
        // if (ok != v) {
        //     ok = v;
        //     if (v == 1LL) {
        //         cnt0++;
        //     }
        // }
    // }
    // deb(cnt0);
    vector<vector<pll> >dp(n+10LL, vector<pll>(2LL, {0LL,0LL}));
    // fi 是代表的是 值，也就是天数
    // se 代表的是当前结尾的数组的个数是多少
    dp[0][0].fi = 0;
    dp[0][0].se = 1LL; //初始为1个数组
    for (int i = 1;i <= n;i++) {
        i64 v = a[i];
        if (v == -1) {
            i64 cnt0 = dp[i - 1][0].se, cnt1 = dp[i - 1][1].se;
            i64 v0 = dp[i - 1][0].fi, v1 = dp[i - 1][1].fi;
            dp[i][0].fi = (v0 % mod3 + v1 % mod3) % mod3;
            dp[i][0].se = (cnt0 + cnt1) % mod3;

            dp[i][1].fi = ((v0 + 1LL * cnt0 )% mod3 + v1 % mod3) % mod3;
            dp[i][1].se = (cnt0 + cnt1) % mod3;

        } else {
            i64 cnt0 = dp[i - 1][0].se, cnt1 = dp[i - 1][1].se;
            i64 v0 = dp[i - 1][0].fi, v1 = dp[i - 1][1].fi;
            if (v == 0) {
                dp[i][0].se = cnt0 + cnt1;
                dp[i][0].fi = (v1 % mod3 + v0 % mod3) % mod3;
            } else {
                dp[i][1].se = cnt0 + cnt1;
                dp[i][1].fi = ((v0 + 1LL * cnt0) % mod3 + v1 % mod3) % mod3;
            }
        }
        // deb(i)
        // de(dp[i][0].fi)
        // deb(dp[i][0].se)
        // de(dp[i][1].fi)
        // deb(dp[i][1].se)
    }

    if (a[n] != -1)cout << dp[n][a[n]].fi << endl;
    else {
        cout << (dp[n][0].fi + dp[n][1].fi) % mod3 <<endl;
    }
}
// 2025.07.17——13:20:56
/*
样例
1
3
-1 -1 -1
结果应该是 :
0 0 0 -> 0
0 0 1 -> 1
0 1 0 -> 1
0 1 1 -> 1
1 0 0 -> 1
1 0 1 -> 2
1 1 0 -> 1
1 1 1 -> 1
解为8
0 0 -> 0
0 1 -> 1
1 0 -> 1
1 1 -> 1
dp[0] = 1  se 2
dp[1] = 2  se 2
-> dp[i + 1] [0] = dp[0] + dp[1]
-> dp[i + 1] [1] = dp[1] + dp[0] + dp[0].se 
*/
// 2025.07.17——13:30:43 accpted
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}