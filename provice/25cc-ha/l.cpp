#include<bits/stdc++.h>
#include<climits>

#define fi first
#define se second
#define i64 long long 
#define all(x) x.begin(),x.end()
#define endl '\n'
#define de(x) cerr << #x << " " << x << " ";
#define deb(x) cerr << #x << " " << x << " \n";
using namespace std; 
using pll = pair<i64, i64>;


void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<vector<i64> >g(n + 1, vector<i64>(m + 1, 0));

    vector<pll>col(m + 1, { -1,-1 });

    for (int i = 0;i < k;i++) {
        i64 r, c;
        cin >> r >> c;
        col[c] = { i,r };
        g[r][c] = 1;
    }

    vector<vector<vector<i64> > > dp(n + 5,
        vector<vector<i64> >(m + 5, vector<i64>(1LL << k, -1)));
    
    queue<array<i64, 4>>q;
    // 
    for (int i = 1;i <= n;i++) {
        q.push({ 0,i,1, 0 });
    }
    vector<i64>ans(1LL << k, INT_MAX);

    int dx[] = { 1, 0, 0 };
    int dy[] = { 0, 1,-1 };
    while (!q.empty()) {
        auto [w, r, c, dk] = q.front();
        q.pop();
        if (dp[r][c][dk] != -1) {
            continue;
        }
        // de(w)de(r)de(c)deb(dk);
        // cerr << " w : " << w << " | " << " r : " << r << " | " << c << " |  " << dk << endl;

        dp[r][c][dk] = w;

        if (c == m) {
            ans[dk] = min(ans[dk], w);
        }
        for (int i = 0;i < 3;i++) {
            i64 nr = r + dy[i];
            i64 nc = c + dx[i];
            if (nr > n || nr <= 0 || nc <= 0 || nc > m || g[nr][nc] == 1) {
                continue;
            }
            i64 nw = w + 1;
            i64 ndk = dk;
            if (col[nc].fi != -1 && nc == c + 1) {
                // ndk = 1LL << col[nc].
                if (nr > col[nc].se) {
                    ndk |= (1LL << col[nc].fi);
                }
            }
            q.push({ nw,nr,nc,ndk });
        }
    }
    for (int i = 0;i < 1LL << k;i++) {
        cout << ((ans[i] == INT_MAX) ? -1 : ans[i]) << " \n"[i == ((1LL << k) - 1)];
    }





}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}