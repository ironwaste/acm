#include<bits/stdc++.h>
#include<climits>


#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define i64 long long
#define fi first
#define se second

#define endl '\n'
#define mod3 998244353LL
#define mod7 1000000007
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using i128 = __int128;
// 补题——题目链接:
// 网址：
// 2025.08.05——20:07:05
// 2025.08.05——20:51:33 wa 过了 45.24 
// 而后添加 ggcd 中 b<= 0 直接return 的部分
// 2025.08.05——20:52:32 还是一样 ？？
// 竟然错在了 快速幂 一开始的时候没有模除a 吗？ 其gcd可能超过 1e9 还真是 无语了。。。。
// 2025.08.05——21:53:06 accpted
/*
 *
*/

i64 pw(i64 a,i64 b) {
    i64 res = 1LL;
    a %= mod3;
    if (a == 0)return 0LL;
    b = b % (mod3 - 1LL);
    while (b) {
        if (b & 1) res = a * res % mod3;
        a = a * a % mod3;
        b >>= 1;
    }
    return res % mod3;
}

void ggcd(i64 a, i64 b, i64 c, i64 d ,i64 & ans) {
    i64 e = __gcd(a, c);
    if (b > d) {
        swap(a, c), swap(b, d);
    }
    if (e == 1 || b == 0 || d == 0) {
        return;
    }
    ans = ans * pw(e, b) % mod3;
    ggcd(a / e, b, e, d - b, ans);
}

void solve() {
    i64 a, b, c, d, ans = 1;
    cin >> a >> b >> c >> d;
    ggcd(a, b, c, d,ans);

    cout << ans << endl;
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