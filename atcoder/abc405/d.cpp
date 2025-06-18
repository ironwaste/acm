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

// < , ^ , v , >
i64 dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
const string str = "<^v>";

void solve(){
    i64 h, w;
    cin >> h >> w;
    vector<string>mp(h);
    for (auto& x : mp) { cin >> x; }
    // vector<pll>E;
    queue<pll>E;
    auto ans = mp;
    for (i64 i = 0;i < h;i++) {
        for (i64 j = 0;j < w;j++) {
            if (mp[i][j] == 'E') {
                E.push(make_pair(i,j));
            }
        }
    }

    while (!E.empty()) {
        pll q = E.front();
        E.pop();
        i64 x = q.fi, y = q.se;
        for (i64 i = 0;i < 4;i ++) {
            i64 nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= h || nx < 0 || ny >= w || ny < 0) {continue;}
            if (ans[nx][ny] == '.') {
                ans[nx][ny] = str[i];
                E.push(make_pair(nx, ny));
            }
        }
    }

    for (int i = 0;i < h;i ++) {
        cout << ans[i] << endl;
    }

    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
