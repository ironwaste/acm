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

// 2025.07.24——15:53:19
/*
 *
 *
 *
*/
const int dir[][2] = { {1,0},{0,1},{0,-1} };

void solve() {
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


    auto check = [&](i64 a, i64 b)->bool {
        if (a >= 1 && a <= n && b >= 1 && b <= m) {return true;}
        return false;
        };
    vector<vector<i64> >vis(n + 10, vector<i64>(m + 10, 0));
    auto vis2 = vis;
    auto vis3 = vis;
    queue<pll>q;
    q.push({ 1,1 });
    vis[1][1] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0;i < 3;i++) {
            i64 nx = x + dir[i][1], ny = y + dir[i][0];
            if (check(nx, ny) && !vis[nx][ny] && s[nx][ny] == '0') {
                q.push({ nx,ny });
                vis[nx][ny] = 1;
            }
        }
    }
    q.push({ 1,m });
    vis2[1][m] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0;i < 3;i ++) {
            i64 nx = x - dir[i][1], ny = y - dir[i][0];
            if (check(nx, ny) && !vis2[nx][ny] && s[nx][ny] == '0') {
                q.push({ nx,ny });
                vis2[nx][ny] = 1;
            }
        }
    }

    // 建图

    auto cantp = [&](i64 x, i64 y)->bool {
        if (vis[x][y] && !vis2[x][y]) {return true;}
        return false;
        };
    i64 mx = 0;
    vector<vector<i64> >dp(n + 10, vector<i64>(m + 10, 0));
    
    auto change = [&](auto self,i64 x, i64 val, i64 y)->void {
        if (!cantp(x, y))return;
        if (dp[x][y] >= val)return;
        dp[x][y] = val;
        mx = max(mx, val);
        self(self,x + 1, val, y);
        self(self,x - 1, val, y);
        };

    for (int y = m;y >= 1;y--) {
        vector<pll>p;// 距离值 和 x的位置
        for (int x = 1;x <= n;x++) {
            if (!cantp(x, y)) { continue; }
            if (check(x, y + 1) && cantp(x, y + 1)) {
                p.push_back({ dp[x][y + 1] + 1LL,x });
            } else {
                p.push_back({ 1LL ,x });
            }
        }
        sort(all(p), [&](pll a, pll b) {return a.fi > b.fi;});
        for (auto [v, x] : p) { change(change, x, v, y); }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            mx = max(dp[i][j], mx);
        }cout << endl;
    }

    cout << ((mx >= k) ? "YES\n" : "NO\n");
}

int main(){
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