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


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/P4648
// 网址：
// 2025.09.04——03:01:48
/*
 * 三维前缀和 + 三维树状数组优化
 * 或者 二维前缀和预处理
 *
 * 切比雪夫距离转化后 使用 数据结构优化
 *
 *
*/
i64 b, n, d, m;
i64 lowbit(i64 x) { return x & -x; }
void solve1() {
    vector<i64>a(n);
    for (auto& x : a) {
        cin >> x;
    }
    sort(all(a));
    i64 ans = 0;
    for (int i = 0, j = 0;i < n;i++) {
        i64 x = a[i];
        while (j < i && a[j] + d < x) {
            j++;
        }
        ans += i - j;
    }
    cout << ans << endl;
}
const i64 N = 2e5;
const i64 M2 = 75000;

void solve2() {
    i64 tree2[N];
    i64 ans = 0;
    vector<pll>a(n);
    // x + y = 75 000 + 75 000 -> 15 0000

    for (int i = 0;i < n;i++) {
        i64 x, y;
        cin >> x >> y;
        a[i].fi = x + y;
        a[i].se = x - y + M2;
        // mx = a[i].se;
    }
    for (int i = 0;i < N;i ++) {
        tree2[i] = 0;
    }
    sort(all(a));
    auto up = [&](i64 x, i64 v) ->void {
        for (;x < N;x += lowbit(x)) { tree2[x] += v; }
        };
    auto qry = [&](i64 x) ->i64 {
        i64 res = 0;
        for (;x > 0;x -= lowbit(x)) { res += tree2[x]; }
        return res;
        };
    auto qr = [&](i64 x, i64 y)->i64 {
        return qry(x) - qry(y);
        };
    for (int i = 0, j = 0;i < n;i++) {
        i64 x = a[i].fi, y = a[i].se;
        while (j < i && a[j].fi + d < x) {
            up(a[j++].se, -1);
        }
        i64 mi = max(0LL, y - d - 1);
        i64 mx = min(N - 1LL, y + d);
        ans += qr(mx, mi);
        up(y, 1);
    }

    cout << ans << endl;
}
const i64 N3 = 230;
const i64 M3 = 75;
using a3 = array<i64, 3>;
using a4 = array<i64, 4>;
void solve3() {
    i64 ans = 0;
    vector<a4>a(n);
    vector<vector<vector<i64> > >
        tree(N3, vector<vector<i64> >(N3, vector<i64>(N3, 0)));
    for (int i = 0;i < n;i++) {
        i64 x, y, z;
        cin >> x >> y >> z;
        i64 x1 = x + y + z, x2 = x - y + z + M3, x3 = x + y - z + M3;
        i64 x4 = y + z - x + M3;
        a[i][0] = x1;
        a[i][1] = x2;
        a[i][2] = x3;
        a[i][3] = x4;
    }
    sort(all(a));
    auto up = [&](i64 x,i64 y, i64 z, i64 v) ->void {
        
        for (i64 xx = x;xx < N3;xx += lowbit(xx)) {
            for (i64 yy = y;yy < N3;yy += lowbit(yy)) {
                for (i64 zz = z;zz < N3;zz += lowbit(zz)) {
                    tree[xx][yy][zz] += v;
                }
            }
        }
        };
    auto qry = [&](i64 x,i64 y,i64 z) ->i64 {
        i64 res = 0;
        for (i64 xx = x;xx;xx -= lowbit(xx)) {
            for (i64 yy = y;yy ;yy -= lowbit(yy)) {
                for (i64 zz = z;zz ;zz -= lowbit(zz)) {
                    res += tree[xx][yy][zz];
                }
            }
        }
        return res;
        };
    auto qr = [&](i64 x, i64 y,i64 z,i64 xx,i64 yy,i64 zz)->i64 {
        i64 res = qry(x, y, z) - qry(xx, y, z) - qry(x, yy, z);
        res = res - qry(x, y, zz) - qry(xx, yy, zz);
        res += qry(xx, yy, z) + qry(xx, y, zz) + qry(x, yy, zz);

        return res;
        };
    for (int i = 0, j = 0;i < n;i ++) {
        i64 k = a[i][0], x = a[i][1], y = a[i][2],z = a[i][3];
        while (j < i && a[j][0] + d < k) {
            up(a[j][1], a[j][2], a[j][3], -1);
            j++;
        }

        i64 mix = max(0LL, x - d - 1), mxx = min(N3 - 1, x + d);
        i64 miy = max(0LL, y - d - 1), mxy = min(N3 - 1, y + d);
        i64 miz = max(0LL, z - d - 1), mxz = min(N3 - 1, z + d);
        ans += qr(mxx, mxy, mxz, mix, miy, miz);
    
        up(x, y, z, 1);
    }
    cout << ans << endl;
}

void solve() {
    cin >> b >> n >> d >> m;
    if (b == 1) {
        solve1();
    } else if (b == 2) {
        solve2();
    } else {
        solve3();
    }



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