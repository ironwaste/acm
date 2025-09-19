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

// 2025.09.16——12:26:08
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    i64 ans = 0,sk = sqrt(k);
    ans += max(0LL, (n - k)) * k;
    i64 r = min(n, k - 1);
    // ans +=
    // if (n < k - 1) {
    //     i64 f1 = k / n + 1, f2 = k / n;
    //     ans +=
    //     r =
    // }
    // deb(ans);
    for (i64 f = 2;r >= sk;r = min(r, k / f), f++) {
        i64 l = k / f;
        if (l > r) continue;
        i64 sz = r - l;
        ans += sz * k - (l + 1LL + r) * sz / 2 * (f - 1LL);
    }
    // de(r)deb(ans);
    for (i64 i = 2;i <= r;i++) {
        ans += k % i;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}