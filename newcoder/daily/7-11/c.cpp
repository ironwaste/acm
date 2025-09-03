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

// 2025.07.11——19:23:03
/* 相当于向前移动k - 1位置 => 改动为向后以为就应该是
 * 向后移动n-k+1 位
 * [1 , 2, 3] => k = 2 [2, 3] + [1] <==> [] 移动两位
 * n = 3, k = 2  就是 n - k + 1 位置
//  * 时间复杂度为 第一个数字的个数 * m * log(当前选中的数字的个数的两倍)
 * 将每个数字的下标存在一个二维数组中 二分判断
 * 超时TLE
 * 其中我们可以发现一个性质就是、其一段数字内能增加解集的部分就是有一段
 * 重复的个数，但是是0的重复的个数才可以增加
 *
 * 双指针去做，因为当我判定了一段区间是没有解的情况下，
 * 我就会发现这一段区间无论如何都是不可能有解的，
 *
 * 如果我找到一个解的话，我只需要判断最前面0的个数就可以进行知道有多少个解集
 * 外循环循环最初开始的位置i 找0
 * 中间判断现在是否是有解的，
 * 如何判断有解，只需要存储现在的最小值mi即可
 * 如果出现了大于mi + 1 的值则无解直接跳过
 * 如果出现 mi+1 则将最小值更迭，
 * 还需要一个值来存储前缀0的个数也就是最终的答案数cnt0
 * 而其中 mi 只要到达了 m - 1即可 得出该区段解；
 * 然后寻找下一个 0的位置
 *
 *
 * 需要在双指针内部存在可加可减的数据结构
*/

void solve(){
    i64 m, n;
    cin >> n >> m;
    vector<i64>a(2 * n);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if(i!=n)a[i + n] = a[i];
    }
    // for (int i = 1;i <= 2 * n;i++) {
    //     cout << a[i] << " ";
    // }cout << endl;
    i64 i = 1, ans = 0;
    set<i64>st;
    while (i <= n) {
        // deb(i)
        vector<i64>dp(m, 0);
        i64 mi = 0;
        while (a[i] != 0 && i <= n) { i++; }
        if (i > n )break;
        i64 j = i;
        while (i + n > j && j <= n && a[j] == 0) {
            dp[0]++;
            j++;
        }
        while ( i + n > j && j <= 2*n && mi + 1 >= a[j] && mi < m - 1LL) {
            if (a[j] == 0) {
                if(j <= n)dp[0]++;
                st.insert(a[j]);
            } else {
                dp[a[j]] += dp[a[j] - 1];
                dp[a[j] - 1] = 0;
                st.erase(a[j] - 1);
                st.insert(a[j]);
                vector<i64>s;
                for (auto x: st) {
                    if (x < a[j]) {
                        s.pb(x);
                    } else { break; }
                }
                for (auto x : s) {
                    st.erase(x);
                    dp[x] = 0;
                }
            }
            mi = max(mi, a[j]);
            j++;
            // for (int i = 0;i < m;i++) {
            //     cout << dp[i] << " ";
            // }cout << endl;
        }
        if (mi == m - 1LL) {
            ans += dp[m-1];
        }
        i = j;
        // cout << endl;
    }
    cout << ans << endl;
}
// 2025.07.11——20:08:40 wa eeee......
/* 错误的样例
7 4
0 1 2 0 1 2 3
0 : 0
1 : 0
2 : 1

i = 3
0 : 1
i = 4
*/

// 2025.07.11——20:13:42 TLE 。。。
// 2025.07.11——20:33:52 双指针 + dp错了斯
// 2025.07.12——01:43:27
/* 错误样例 错误点在于当下标值大于n的时候还计算了最后的解集
10 2
0 1 1 0 1 1 0 1 0 0

*/

int main() {
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