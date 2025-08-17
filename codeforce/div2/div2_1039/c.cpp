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

// 2025.07.27——23:19:52
// 2025.07.27——23:35:58 accepted
/*
 * 题目意思 ： 就是a数组全部为0
 * 然后可以执行以下操作：
 * 1、 选择一个大于 a数组的最小值的 一个值x
 * 2、 从左到右找到第一个小于 x的值，将该值增加x
 * 
 * 给出数组b 看是否能够通过以上操作变成
 * 差分一下， 如果 差分出来的值，大于前一个数字的值 则绝对不可能
 *
 * 或者说，前一个值大于前面任何一个值都是不可能的，
 * 所以需要预处理一下，前i个数字的最小值和差分数据
 *
 * 如果 ai 需要加上 值x ，那么说明前面所有的值都大于等于x
 * 如果要将 ai加到 x1 
 * 目标是 40 60 90
 * 40  0  0 x = 29
 * 40 29 ？  x = 31
 * 40 60   所以 一个值最大 只有 a[i-1]的值两倍减去1
 * 其实是最小值的两倍减去1
*/

void solve() {
    int n;
    cin >> n;
    vector<i64>a(n + 1), mi(n + 1,INT_MAX);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        mi[i] = min(mi[i - 1],a[i]);
    }
    int ok = 1;
    for (int i = 1;i <= n;i ++) {
        if (2LL * mi[i] - 1LL < a[i]) {
            ok = 0;
        }
    }
    cout << ((ok) ? "YES\n" : "NO\n");



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