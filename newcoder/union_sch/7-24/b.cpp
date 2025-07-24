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

// 2025.07.24——13:27:43
/*
 *
 *
 *
*/
const int dir[][2] = { {1,0},{0,1},{0,-1} };
const int dir1[][2] = { {1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };

void solve(){
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<string>s(n + 2);
    // O(n * m)
    // s  是 n+1,m+1[1,1;n,m];
    // 0列为空格
    // 0行和n+1行为 1
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    s[0] = s[n];
    s[n + 1] = s[n];
    // O(m)
    for (int i = 1;i <= m + 1LL;i++) { s[0][i] = '1';s[n + 1][i] = '1'; }
    // O(n * m) 去求出所有可以走到的位置包括障碍
    queue<pll>q, q1;
    q.push({1,1});
    vector<vector<i64> >vis(n + 10, vector<i64>(m + 10, 0));
    vis[1][1] = 1;
    // for (int i = 0;i <= m;i++) { vis[0][i] = vis[n + 1][i] = 1; }
    auto check1 = [&](i64 x, i64 y)->bool {
        if (0 <= x && x <= n + 1&& y >= 1 && y<= m) {
            return true;
        }
        return false;
        };
    auto check = [&](i64 x, i64 y)->bool {
        if (1<=x && x <= n && y >= 1 && y<= m) {
            return true;
        }
        return false;
        };
    vector<vector<pll> >block;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0;i < 3;i++) {
            i64 nx = x + dir[i][0], ny = y + dir[i][1];
            if (check(nx,ny) && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                if (s[nx][ny] == '0') {
                    q.push({ nx,ny });
                } else {
                    q1.push({ nx, ny });
                    vector<pll>b;
                    b.push_back({ nx,ny });
                    while (!q1.empty()) {
                        auto [x1, y1] = q1.front();
                        q1.pop();
                        for (int i = 0;i < 8;i ++) {
                            i64 nnx = x1 + dir1[i][0], nny = y1 + dir1[i][1];
                            // de(nnx)de(nny)de(vis[nnx][nny])deb(s[nnx][nny]);
                            if (check1(nnx, nny) && !vis[nnx][nny] && s[nnx][nny] == '1') {
                                // cout << "insert 1 :  ";de(nnx)deb(nny);
                                vis[nnx][nny] = 1;
                                q1.push({ nnx,nny });
                                b.push_back({ nnx,nny });
                            }
                        }
                    }
                    block.push_back(b);
                    b.clear();
                }
            }
        }
    }
    // O(2 * n*(m-k) );
    // 根据列的位置按顺序存 障碍的位置二维数组保存，保存下来的条件 vis被遍历，且 s为‘1’
    //如果两个障碍上下紧挨着直接跳过
    i64 sz = block.size();// 存储的是 x,y的值
    vector<i64>bsz(sz);
    // p数组代表的当位置为y的情况下，其中包含多少个障碍，并且从小到大按顺序排列

    // x,y 先判断y根据y 来排序，从大到小
    // 然后再根据x从小到大排序
    for (int i = 0;i < sz;i++) {
        sort(all(block[i]), [&](pll a, pll b) {
            if (a.se != b.se)return a.se > b.se;
            return a.fi < b.fi;
            });
        bsz[i] = block[i].size();
    }

    // 需要求可以遍历到的y值最大的0，然后
    vector<vector<i64> >vvis(n + 10, vector<i64>(m + 10, 0));
    // 从最大的y开始扫描,当遇到0(vis为1的可以遍历到的,其次vvis没有遍历过的)就开始扫描
    // vvis 代表现在的遍历
    // vector<array<i64, 2> >mxi(m + 10, { 0LL,INT_MAX });
    vector<i64>range[m + 10];
    auto concheck = [&](i64 x, i64 y)->bool {
        if (s[x][y] == '1' || !vis[x][y] || vvis[x][y]) {
            return true;
        }
        return false;
        };
    for (i64 i = 0;i < sz;i++) {
        i64 ssz = bsz[i];
        i64 mx = block[i][0].se, mi = block[i][ssz - 1].se;// y的最大最小值
        // range[y].push_back(0);
        for (i64 j = 0;j < ssz;j++) {
            i64 y = block[i][j].se;
            i64 x = block[i][j].fi;
            range[y].push_back(x);
            // 求出该块每个y坐标情况下, x的最大和最小值;
            // 然后遍历该区间,将该区间的值判断是否存在可以走到的0并且没被vvis遍历过,
            // 而后查找每个点的  y 值情况下,x是否在范围内二分查找;
            // y值相同的情况下,x小的在前面,也就是会被先push进去,所以其本身就是有序的
        }
        // 当有解直接退出循环
        auto bfs = [&](i64 a, i64 b)->bool {
            priority_queue<pll,vector<pll>,greater<pll> >qq;
            qq.push({ b,a });
            vvis[a][b] = 1;
            de(a)deb(b);
            while (!qq.empty()) {
                
                auto [y, x] = qq.top();
                if (y + k <= b + 1) {return true;}// 死路
                qq.pop();
                for (int i = 0;i < 3;i++) {
                    i64 nx = x - dir[i][0], ny = y - dir[i][1];
                    cout << "bfd : ";de(nx)deb(ny);
                    if (check(nx, ny) && vis[nx][ny] && s[nx][ny] == '0' && !vvis[nx][ny]) {
                        cout << "check : ";de(nx)deb(ny);
                        qq.push({ ny,nx });
                        vvis[nx][ny] = 1;
                        if (upper_bound(all(range[ny]), nx) == range[ny].end() ||
                            upper_bound(all(range[ny]), nx) == range[ny].begin() ) {
                            return false;
                        }
                        
                    }
                }
            }
            return false;
            };
        de(mx)deb(mi);
        for (i64 y = mx;y >= mi;y--) {
            for (i64 x = range[y][0];x <= range[y].back();x++) {
                // de(x)deb(y);
                if (concheck(x, y)) { continue; }
                if (bfs(x, y)) {
                    // de(x)deb(y)

                    cout << "YES\n";
                    return;
                }

            }
        }
    }
    cout << "NO\n";
    return;

}
/*
1
3 5 2
00010
01110
00000

1
5 5 2
00000
00110
00010
01010
00010
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}