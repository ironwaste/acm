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

// 2025.07.17——12:02:58
/*
 * 即求 x mod k + k mod x == y mod k + k mod y;
 * x % k == y % k
 * k % x == k % y;
 * 就是当k == 1 的时候 ，只需要特判其中一个是1LL 另外一个不是1LL 的情况
 * 当 x 为1的时候， y ==2
 * k % x == 0  k！= 1LL x % k == 1LL
 * y % k + k % y == 1LL
 * k % y == 0LL k = z * y; y
 * 即求 1LL mod k == y mod k + k mod y;
 */

void solve(){
    i64 x, y;
    cin >> x >> y;
    if ((x == 1LL && y != 1LL) || (x != 1LL && y == 1LL)) {
        cout << -1 << endl;
    } else {
        cout << 1LL << endl;
    }
}
// 2025.07.17——12:14:40 accepted
int main() {
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