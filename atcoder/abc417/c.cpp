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

// 2025.08.02——20:21:18
// 2025.08.02——20:27:33 accpted
/* 
 * 题目意思： 给定一个整数 序列 长度为n 的序列A
 * 问有多少对数对 存在 j - i = a[i] + a[j]
 * n >= j > i >= 1
 *
 * j - a[j] = a[i] + i; ?
 * 维护两个数组来判断， 维护前缀 中 所有的 a[i] + i
 * 遍历一般 j 即可
 *
*/

void solve() {
    int n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }

    map<i64, i64>cnt;
    i64 ans = 0;
    for (int j = 1;j <= n;j++) {
        i64 pos = j - 1;
        ans += cnt[j - a[pos]];
        cnt[j + a[pos]] ++ ;
    }
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