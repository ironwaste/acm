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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
#define ld long double 
using namespace std;

using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.11.18——20:12:29
/*
 *
 *
 *
*/

void solve() {
    i64 ppmx, a, b, c, d, e, f;
    cin >> ppmx >> a >> b >> c >> d >> e >> f;

    i64 accf = (300 * a + 300 * b + 200 * c + 100 * d + 50 * e);
    i64 accc = 300 * (a + b + c + d + e + f);
    i64 mxf = 320 * a + 300 * b + 200 * c + 100 * d + 50 * e;
    i64 mxc = (256 * (a + b + c + d + e + f));

    // mxf = 5 * mxf - 4 * mxc;
    mxf = max(0ll, mxf) * ppmx;

    i64 ans = mxf / mxc;
    mxf %= mxc;

    if (2 * mxf >= mxc) ans++;

    printf("%0.2lf%% %ld\n", (1.0 * accf / accc) * 100, ans);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}