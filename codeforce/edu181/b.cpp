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

// 2025.07.22——22:40:48
/*
 * 可以先将小的置为0，然后只减去大数即可，那么最后的解集就只有0，1，2
 *
 * 当 x == y == 0时为0
 * 那么当 x % [0,k]之间的数字为零，且其倍数关系和y的相同
 * 形式化来说：
 * x = kx * a1
 * y = ky * a2;
 * k>= a1,a2 >= 0 && kx == ky;
 * 那么kx 和 ky就是x和y的最大公约数
*/

void solve() {
    i64 a, b, k;
    cin >> a >> b >> k;
    // if (a == b && a == 0) { cout << 0 << endl; return; }
    i64 c = __gcd(a, b);
    i64 vx = a / c, vy = b / c;
    if (vx <= k && vy <= k) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}
// 2025.07.22——22:49:48 accpted
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