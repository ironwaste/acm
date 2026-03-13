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

using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 2026.03.13——18:30:56
// 2026.03.13——18:40:11
// 2026.03.13——18:43:18
// 2026.03.13——19:16:30 ac
/*
 *
 *
 *
*/

void solve() {
    // vector<i64>a(100);
    // iota(all(a), 3);
    i64 n;
    cin >> n;
    // for (i64 n : a) {
    i64 ans = 1;

    for (i64 i = 3;i <= n / i + 1;i++) {
        if (n % i == 0) {
            ans = max(ans, n / i);
        }
        i64 gd = i;
        if ((n - i) % gd == 0 && n - i > i) {
            ans = max(gd, ans);
        }
    }
    if ((n - 2) % 2 ==0 && n- 2 > 2) {
        ans = max(2LL, ans);
    }
    cout << ans << endl;
    // cout <<"X :" << n <<" | " << "ans : " << ans << endl;

    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}