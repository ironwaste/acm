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

/*
以求最小的纸币数量
*/
void solve() {
    int n, w;
    cin >> n >> w;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }

    vector<i64>dp(w + 10, INT_MAX);
    dp[0] = 0;
    for (int i = 0;i < n;i ++) {
        int v = a[i];
        for (int j = 0;j <= w - v;j ++) {
            dp[j + v] = min(dp[j + v], dp[j] + 1LL);
        }
    }


    /*
        上述解法，和下述解法的区别在于，上面的方法摈弃了可能从 前向后的方式以导致某一个纸币被多次应用
        但是由于该题面可以被多次应用，而非01背包、多重背包的问题，是无限背包可以被使用。

        如下解方法，在我看来是应该会超时的，因为 其n=1e3 1<=w <=1e4 >=1e4a>=1
        时间复杂度为 O(n * w * (sigma(1+w)/a))
        如果a全部为1 ，则出现 O(n * w * w )的情况
    */
    // for (int i = 0;i < n;i ++) {
    //     i64 v = a[i];
    //     for (int j = w;j >= v;j--) {
    //         for (int k = 1; k * v <= w;k ++) {
    //             i64 diff = k * v;
    //             dp[j] = min(dp[j - diff] + k, dp[j]);
    //         }
    //     }
    // }
    cout << dp[w] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}