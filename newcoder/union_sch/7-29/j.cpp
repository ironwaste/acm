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

// 2025.07.29——14:37:24
/*
 * 给出 一个 01 的地图，然后1 可以向上下左右扩散将白色的转换为黑块
 * 然后被扩散的 黑块 可以继续 扩散
 *
 * 先 bfs 出 所有点的时间值，然后根据时间值来存储每一个点的坐标
 * 其次 我们将按照 时间来存储坐标点，然后没有被遍历到的点当作为
 * 时间值为最大
 *
 * 其次 二分查找最小的时间值
 * check  是否存在一个点，使得到所有超过最小时间值的点
 * 曼哈顿距离 在时间值之内
 *
*/
const int dir[][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<i64> >g(n + 1, vector<i64>(m + 1LL,0));
    auto vis = g;
    auto v = vis;
    int ok = 0;
    queue<array<i64 ,3> > q;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> g[i][j];
            ok += g[i][j];
            if (g[i][j]) {
                vis[i][j] = 1;
                q.push({ i,j ,0});
            }
        }
    }
    // deb(ok)
    if (!ok) {
        cout << n / 2 + m / 2 << endl;
        return;
    }
    auto check = [&](i64 x, i64 y)->bool {
        if (x >= 1 && x <= n && y >= 1 && y <= m)
            return true;
        return false;
        };
    i64 mxt = 0;
    while (!q.empty()) {
        auto [x, y, t] = q.front();
        t++;
        q.pop();
        for (int i = 0;i < 4;i++) {
            i64 nx = x + dir[i][0], ny = y + dir[i][1];
            if (check(nx,ny) && !vis[nx][ny]) {
                v[nx][ny] = t;
                q.push({ nx,ny,t });
                vis[nx][ny] = 1;
                mxt = max(mxt, t);
            }
        }
    }
    vector<vector<pll> > p(mxt + 10);
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            i64 x = i + j, y = i - j;
            i64 t = v[i][j];
            p[t].push_back({ x,y });
        }
    }

    auto chck = [&](i64 mid)->bool {
        i64 mix = LLONG_MAX, miy = LLONG_MAX;
        i64 mxx = LLONG_MIN, mxy = LLONG_MIN;

        for (int i = mid + 1LL;i <= mxt;i++) {
            for (auto k : p[i]) {
                i64 x = k.fi, y = k.se;
                mix = min(mix, x);
                mxx = max(mxx, x);
                miy = min(miy, y);
                mxy = max(mxy, y);
            }
        }
        if (mxx - mix >= 2 * mid + 1LL || mxy - miy >= 2 * mid + 1LL) {
            return false;
        }
        return true;
        };
    i64 l = 0, r =  mxt;
    while (l < r) {
        i64 mid = l + (r - l >> 1);
        if (chck(mid)) {
            r = mid;
        } else {
            l = mid + 1LL;
        }
    }
    // de(l)deb(r);
    cout << r << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // for (int i = 0;i < 4;i ++) {
    //     i64 nx = dir[i][0], ny = dir[i][1];
    //     de(i)de(nx)deb(ny)
    // }

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
