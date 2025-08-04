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

// 2025.08.04——12:02:10
// 2025.08.04——12:09:50 wa
// 2025.08.04——12:09:57 accpted
/*
 * 需要所有数字的乘积 为正整数
 * 负数情况 则直接找 正整数的最小值 或者 负数的最大值
 * 0 的情况 统计 负数的个数 以及 0的个数，其最终解就是0的个数
 * 
*/

void solve(){
    i64 n;
    cin >> n;
    vector<i64>a(n);
    i64 cnt0 = 0, cntne = 0, mipo = INT_MAX, mxne = INT_MIN;
    for (auto& x : a) {
        cin >> x;
        if (x == 0) {
            cnt0++;
        } else if (x < 0) {
            mxne = max(mxne, x - 1);
            cntne++;
        } else {
            mipo = min(mipo, x + 1);
        }
    }

    if (cnt0) {
        cout << cnt0 << endl;
    } else if (cntne % 2 == 1) {
        cout << min(abs(mxne),mipo) << endl;
    } else {
        cout << 0 << endl;
    }
}

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