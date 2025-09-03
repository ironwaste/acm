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

// 2025.09.03——01:05:00
/* https://ac.nowcoder.com/acm/contest/view-submission?submissionId=78514053
 * 完美避过 难写的调试部分
 * 对于取模部分 的 实现不太清楚
 * 并且对于曼哈顿距离 转化为 切比雪夫距离
 * 与 坐标系点转换  以及路径选择 产生了模糊
 * 其只能够转化距离 并且有相关的 特殊性 和问题的存在
*/
const int dir[][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void solve() {
    int n, m;  
    cin >> n >> m;
    vector<vector<i64> >g(n + 1, vector<i64>(m + 1LL,0));
    auto vis = g;
    auto v = vis;
    int ok = 0;
    queue<array<i64, 3> > q;
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

    // 判断边界 x + y , x - y
    // 1 , n + m (x + y)
    // 1 - m , n - 1 (x - y) // 1 - m
//     i64 y1 = 1 - m,y2 = n - 1,x1 = 1,x2 = n + m; 
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
        // 1 2 3 4
        // 4 - 1 = 3
        // 3 / 2 = 1;
        // 1 2 3
        // 2 / 2 = 1;
        // mid = 1
        i64 v0 = mxx - mix ,v1 = mxy - miy;
        i64 mx = max(v1, v0);
        // if (mxx - mix >= 2 * mid + 1LL || mxy - miy >= 2 * mid + 1LL) {
        //     return false;
        // }
        // de(v1)de(v0)de(mid)deb(mx);
        if (v1 == v0 && (v1 % 2 == 0) && ((miy +mix)% 2== 1)) {
            if((mx + 1)/2 + 1> mid)return false;
        }else if ( (mx + 1) / 2> mid) {return false;}
        
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

    cout << l << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
