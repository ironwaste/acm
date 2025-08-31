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
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/P3964
// 网址：
// 2025.09.01——03:01:13
// 2025.09.01——03:23:25 accpted
/*
 *
 * 切比雪夫 转 曼哈顿距离
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<pll>xy(n);
    vector<i64>xid(n), yid(n);
    for (int i = 0;i < n;i++) {
        i64 xx, yy;
        cin >> xx >> yy;
        i64 x = (xx + yy), y = (xx - yy);
        xy[i].fi = x;
        xy[i].se = y;
        xid[i] = x;
        yid[i] = y;
        // 转化为二倍曼哈顿距离
    }
    sort(all(xid));
    sort(all(yid));
    vector<i64>prex(n), prey(n);
    partial_sum(all(xid), prex.begin());
    partial_sum(all(yid), prey.begin());

    i64 mxdis = LLONG_MAX;

    for (int i = 0;i < n;i++) {
        i64 x, y;
        x = xy[i].fi, y = xy[i].se;
        i64 dis = 0;
        i64 xnum = lower_bound(all(xid), x) - xid.begin();
        dis += (xnum + 1) * x - prex[xnum];
        i64 cnt = n - xnum - 1;
        dis += prex[n - 1] - prex[xnum] - cnt * x;
        i64 ynum = lower_bound(all(yid), y) - yid.begin();
        dis += (ynum + 1) * y - prey[ynum];
        cnt = n - ynum - 1;
        dis += prey[n - 1] - prey[ynum] - cnt * y;
        // de(i)deb(dis);
        mxdis = min(mxdis, dis);

    }
    cout << mxdis / 2 << endl;

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