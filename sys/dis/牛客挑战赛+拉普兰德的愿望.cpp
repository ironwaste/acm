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
using namespace std;


// 补题——题目链接: https://ac.nowcoder.com/acm/contest/2271/D
// 网址：
// 2025.09.03——22:44:25
/*
 *
 *
 *
*/
const i64 N = 2e6 + 10;
const i64 xi = 1e5 + 10;
// x < [-50000,50000]  - > [0,1e5]
// y < [-50000,50000]  -> [0,1e5] 
// x + y  [-1e5,1e5]
// x - y  [-1e5,1e5]
i64 tree[N];
i64 lowbit(i64 x) { return x & -x; }
void up(i64 x, i64 v) {
    for (;x < N;x += lowbit(x)) {tree[x] += v; }
    
}

i64 qry(i64 x) {
    i64 res = 0;
    for (;x > 0;x -= lowbit(x)) { res += tree[x]; }
    return res;
}
i64 qry(i64 x, i64 y) { return qry(x) - qry(y); }

using pll = pair<i64, i64>;
void solve() {
    i64 n, l, d;
    cin >> n >> d >> l;
    vector<pll>p(n);
    for (auto& v : p) {
        i64 i, j, x, y;
        cin >> i >> j;
        // i += xi, j += xi;
        x = i + j + xi, y = i - j + xi;
        v.fi = x, v.se = y;
    }
    sort(all(p));
    i64 ans = n * (n - 1) / 2;
    for (i64 i = 0, j = 0;i < n;i++) {
        i64 x = p[i].fi;
        i64 y = p[i].se;
        // de(x)deb(y)
        while (j < i && p[j].fi + d <= x) {
            up(p[j].se, -1);
            j++;
        }
        i64 mx = min(y + d - 1, N - 1LL);
        i64 mi = max(y - d, 0LL);
        // de(i)de(mi)deb(mx);
        ans -= qry(mx, mi);
        // deb(y);
        // deb(ans);
        up(y, 1);
        // de(i)de(mi)deb(mx);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}