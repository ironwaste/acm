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

// 2025.08.16——20:25:25
/*
 *
 * 差分数组dp 很像牛客那题
 * 先将最前面长度 为 L 的数组成为 M倍数
 * 而后 根据差分数组 双指针所指向的之后的值应该为消去后的值
 * 或者两者 同余
 * 前缀和同余 的话 可能会比 差分方便一点
 *
 * 只要把区间和 的 值 变为同一个值 即可
 *
 * 那么怎么求最小操作呢？
 * 遍历所有的模数
 * 最小操作 的难点在于对于其中一个值进行增加的话
 * 其会影响多组，也就是前缀和无法维护的问题
 *
 * 区间和差分 呢
 * 其差分数组 的值应该为 m,m,km, -m即m的倍数
 * 对于一个值增加 将会更改 该值所能作用到的 最后一个子数组 和其下一个子数组的差值
 *
 * 也可 直接开一个前缀和数组？
 *  而后 从后往前 dp
 * dp[i] = min(dp[n] + need , need + dp[i + for (0,l) + 该区间的need])
 *
 * 不晓得啊，赛时最后想到的是将所有数组的和其倍数的余数求出来
 * 需要对于 数组余数进行dp 但是不知道怎么dp
 *
 *
 * 其抓住了一种性质，即最终状态如果是 长度为L的子数组模除 m为0
 * 那么则 1 和 L + 1 将会同余
 * 所以 只需要遍历长度为L的子数组 和其 每一种余数即可
 * 1 和所有 %L 的同余下标值，将其所有的花费进行直接求和，
 * 当我们求出第一个数组的 长度为L的子数组  的解的时候
 * 那么
 * 其他所有的解就被求出来了
*/

void solve() {

    i64 n, m, L;
    cin >> n >> m >> L;
    vector<i64>a(n),b;
    for (int i = 0;i < n;i++) {cin >> a[i];}
    vector<vector<i64> > f(L, vector<i64>(m + 10, 0));
    for (int i = 0;i < n;i ++) {
        i64 id = i % L , v = a[i];        
        for (int j = 0;j < m;j++) {
            if (j >= v) {
                f[id][j] += j - v;
            }else{
                f[id][j] += (m - v + j ) % m;                
            }
        }
    }
    vector<i64 > dp(vector<i64>(m + 10, INT_MAX));
    // for (int i = 0;i < m;i ++) {dp[i] = f[0][i];}
    dp[0] = 0;
    for (int i = 0;i < L;i ++) {
        vector<i64 > ndp(vector<i64>(m + 10, INT_MAX));
        
        for (int j = 0;j < m;j++) {
            for (int k = 0;k < m;k++) {
                i64 nxk = (j + k) % m;
                ndp[nxk] = min(ndp[nxk], dp[j] + f[i][k]);
            }
        }
        dp = ndp;
    }

    cout << dp[0] << endl;

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