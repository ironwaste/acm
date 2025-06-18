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

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void solve() {
    i64 n, m;
    cin >> n >> m;
    // 4 * n * m

    vector<vector<i64> >a(n, vector<i64>(m,0));
    auto vis = a;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }
    // i64 cnt = 0;
    map<i64, i64>mp;
    vector<i64>ans;
    // n m log (n * m)
    
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (!vis[i][j]) {
                queue<pii>q;
                q.push({ i,j });
                vis[i][j] = 1;
                int cnt = 1;
                while (!q.empty()) {
                    pii k = q.front();
                    q.pop();
                    int nx = k.fi, ny = k.se;
                    for (int k = 0;k < 4;k++) {
                        int x = nx + dir[k][0], y = ny + dir[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]&& a[x][y] == a[nx][ny]) {
                            q.push({ x,y });
                            vis[x][y] = 1;
                            cnt++;
                        } else {
                            continue;
                        }
                    }
                }

                if (cnt >= 2) {
                    mp[a[i][j]] = 2;
                } else if(!mp.count(a[i][j])){
                    mp[a[i][j]] = 1;
                }
            }
        }
    }


    i64 sum = 0,mx= 0;
    // sort(all(ans));
    for (auto [x,y] : mp) {
        sum += y;
        mx = max(mx, y);
        // de(y)
    }
    cout << sum - mx << endl;

}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}


/*
  for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int kk = 1;

            if (!mp.count(a[i][j])) {
                mp[a[i][j]] = cnt++;
                ans.pb(kk);
            }
            for (int k = 0;k < 4;k++) {
                // de(i)deb(j)
                int nx = i + dir[k][0], ny = j + dir[k][1];
                // de(nx)deb(ny)
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[i][j] == a[nx][ny]) {
                    kk = 2;
                    break;
                }
            }
            ans[mp[a[i][j]]] = kk;

        }
    }
    */