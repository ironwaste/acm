#include<bits/stdc++.h>
#include<climits>


#define ai64(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define i64 long long
#define fi first
#define se second

#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define ai64(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using int128 = __int128;
using pii = pair<i64, i64>;
using pi64 = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.10.19——13:03:50
/*
 *
 *
 *
*/
int128 pow10[21];

void init() {
    pow10[0] = 1;
    for (i64 i = 1; i <= 20; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }
}

i64 digits(i64 x) {
    if (x == 0) return 1;
    i64 cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int128 lw_bound(int128 x) {
    if (x <= 0) return 0;
    int128 l = 0, r = 1;
    while (r * r < x) {
        l = r;
        r *= 2;
    }
    while (l < r) {
        int128 mid = l + (r - l) / 2;
        if (mid * mid >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int128 up_bound(int128 x) {
    if (x <= 0) return 0;
    int128 l = 0, r = 1;
    while (r * r <= x) {
        l = r;
        r *= 2;
    }
    while (l < r) {
        int128 mid = l + (r - l + 1) / 2;
        if (mid * mid <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void solve() {
    i64 c, d;
    cin >> c >> d;
    i64 mi = digits(c + 1);
    i64 mx = digits(c + d);
    int128 ans = 0;
    for (i64 i = mi; i <= mx; i++) {

        int128 limi = max(pow10[i - 1], (int128) (c + 1));
        int128 limx = min(pow10[i] - 1, (int128) (c + d));

        if (limi > limx) continue;

        int128 base = (int128) c * pow10[i];
        int128 i1 = base + limi;
        int128 i2 = base + limx;
        int128 mii = lw_bound(i1);
        int128 mxx = up_bound(i2);
        // de(mii)deb(mxx);
        if (mii <= mxx) {
            ans += (mxx - mii + 1);
        }
    }
    cout << (i64)ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}