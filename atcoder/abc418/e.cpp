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

// 2025.08.09——21:24:11
// 2025.08.10——00:47:28 re + tle
// 2025.08.10——01:12:52 tle 就是 map + gcd 的时间复杂度过大导致的
/*
 * 计算斜率 ，每两个点之间的斜率， 然后看每种斜率有多少个 不同的两对点
 * 一组内 存在 x个假设 ，那么就有  C(x,2) 种不相同的组合
 * 斜率 k 为 (y1 - y2) / (x1 - x2)
 * 可能存正负 无所谓
 *
 * x1 == x2 斜率不存在？ 特殊处理 即可
 * 可以用gcd 替代
 *
 * 无法判两条线 斜率相同 但是可能重复用了 同一个点？
 * 为什么呢 不是保证三点不共线吗 ？
 *
 * C（N , 2） == |(N-1)| ??? 为什么？
 * 前 N - 1 个 自然数相加
 *
 * 梯形  斜率相同 但是 边长不同？？
 * 并不是判断是否是 边长不同 而是判断 是否存在矩形，
 * 也就是说 边长相同且 边垂直
 *
 * 但是在判断矩形的情况下 会导致 矩形的垂直的两条边
 * 会被重复计算。
 *
 * 而且平行四边形 也不是矩形
*/

i64 dis2(i64 x1, i64 y1, i64 x2, i64 y2) {
    i64 y = abs(y1 - y2), x = abs(x1 - x2);
    return y * y + x * x;
}
i64 dis2(pll p1, pll p2) {
    i64 y = abs(p1.se * 4 - p2.se), x = abs(p1.fi * 4 - p2.fi);
    return y * y + x * x;
}

bool is_rec(pll p1, pll p2, pll p3, pll p4) {
    i64 x1 = 4 * p1.fi, x2 = 4 * p2.fi, x3 = 4 * p3.fi, x4 = 4 * p4.fi;
    i64 y1 = 4 * p1.se, y2 = 4 * p2.se, y3 = 4 * p3.se, y4 = 4 * p4.se;
    i64 xc = (x1 + x2 + x3 + x4) / 4;
    i64 yc = (y1 + y2 + y3 + y4) / 4;

    // i64 xc1 = (x3 + x4) / 2;
    // i64 yc1 = (y3 + y4) / 2;

    i64 d1 = dis2(x1, y1, xc, yc);
    i64 d2 = dis2(x2, y2, xc, yc);
    i64 d3 = dis2(x3, y3, xc, yc);
    i64 d4 = dis2(x4, y4, xc, yc);
    if (d1 == d2 && d2 == d3 && d3 == d4) {
        return true;
    }
    return false;
}

bool is_parallelogram(pll p1, pll p2, pll p3, pll p4) {
    vector<pll>p;
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    sort(all(p));
    p1 = p[0], p2 = p[1], p3 = p[3], p4 = p[2];
    i64 x1 = p1.fi, x2 = p2.fi, x3 = p3.fi, x4 = p4.fi;
    i64 y1 = p1.se, y2 = p2.se, y3 = p3.se, y4 = p4.se;
    // de(x1)deb(y1);
    // de(x2)deb(y2);
    // de(x3)deb(y3);
    // de(x4)deb(y4);
    i64 xc1 = (x1 + x3), yc1 = (y1 + y3);
    i64 xc2 = (x2 + x4), yc2 = (y2 + y4);
    if (xc1 == xc2 && yc1 == yc2) {
        return true;
    }
    return false;
}



const int N = 1e6 + 10;
vector<vector<pll> >id(1);

void solve() {
    i64 n;
    cin >> n;
    // map<array<i64,3>, i64>cnt;
    vector<pll>a(n);
    for (int i = 0;i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(all(a), [&](pll a1, pll a2) {
        return a1.se > a2.se;
        });
    i64 cnt = 1;
    map<pll, i64>mp;
    // 时间复杂度为 n ^ 2 * (logn^2) n 为 2000
    // 2e3 ^2 == 4 e 6 
    // logn = 11
    // 121 * 4e6 > 4000
    for (int i = 0;i < n;i++) {
        i64 x1 = a[i].fi, y1 = a[i].se;
        for (int j = i + 1;j < n;j++) {
            i64 x2 = a[j].fi, y2 = a[j].se;
            i64 dy = y1 - y2, dx = x1 - x2;
            if (x1 == x2) {
                id[0].push_back({ i,j });
            } else {
                i64 gd = __gcd(dx, dy);
                dx = dx / gd, dy = dy / gd;
                if (mp.count({ dx,dy })) {
                    i64 pos = mp[{dx, dy}];
                    id[pos].push_back({ i,j });
                } else {
                    vector<pll>k;
                    k.push_back({ i,j });
                    id.push_back(k);
                    mp[{dx, dy}] = cnt++;
                }
            }
        }
    }
    i64 ans = 0, rec = 0;
    for (int c = 0;c < cnt;c++) {
        i64 sz = id[c].size();
        // de(c)deb(sz);
        // de(sz)deb(c)
        for (int i = 0;i < sz;i++) {
            i64 p1 = id[c][i].fi, p2 = id[c][i].se;
            // de(i)de(p1)deb(p2);
            for (int j = i + 1;j < sz;j++) {
                i64 p3 = id[c][j].fi, p4 = id[c][j].se;
                // de(j)de(p3)deb(p4);
                if (p1 == p3 || p2 == p4 || p1 == p4 || p2 == p3) {
                    continue;
                }
                if (is_parallelogram(a[p1], a[p2], a[p3], a[p4])) {
                    rec++;
                    // deb(rec);
                    continue;
                }
                ans++;
            }
        }
    }

    cout << ans + rec / 2 << endl;

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