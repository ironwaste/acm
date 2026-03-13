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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.11.17——19:58:47
/*
 *
 *
 *
*/

using LL = long long;

struct p {
    LL w;
    int x, y;
    bool operator< (const p& t) const {
        return w > t.w;
    };
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    LL inf = 1e18;
    vector<vector<LL>> d(n + 1, vector<LL>(m + 1, inf));

    vector<vector<char>> s(n + 1, vector<char>(m + 1));

    vector<pair<int, int>> b(k);
    for (auto& [x, y] : b) cin >> x >> y;

    priority_queue<p> q;

    vector<vector<LL>> mn(n + 1, vector<LL>(m + 1, -1));

    for (int i = 0; i < k; i++)
    {
        auto [x, y] = b[i];
        if (!i) mn[x][y] = 0, q.push({0, x, y});
        else mn[x][y] = k - i;
    }

    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];

    vector<vector<int>> v(n + 1, vector<int>(m + 1));

    unsigned long long ans = 0;
    while (q.size())
    {
        auto [w, x, y] = q.top();
        q.pop();
        if (v[x][y] || w < mn[x][y]) continue;
        v[x][y] = 1;
        d[x][y] = w;
        ans += w * w;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m || s[nx][ny] == '#') continue;
            q.push({ max(mn[nx][ny], w + 1), nx, ny });
        }
    }

    cout << ans << endl;
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