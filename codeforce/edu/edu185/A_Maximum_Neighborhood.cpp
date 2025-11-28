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

// 补题——题目链接: https://codeforces.com/contest/2170/problem/0
// 网址：
// 2025.11.28——22:35:59
// 2025.11.28——22:42:05
/*
 *
 *
 *
*/

void solve(){
    int n;
    cin >> n;
    i64 mi = 1LL;
    vector<vector<i64>>g(n + 2, vector<i64>(n + 2, 0));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            g[i][j] = mi;
            mi++;
        }
    }
    i64 ans = 1LL;
    int dx[] = { -1,0,1,0 };
    int dy[] = { 0,1,0,-1 };
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j ++) {
            i64 tmp = g[i][j];
            for (int p = 0;p < 4;p ++) {
                int nx = i + dx[p];
                int ny = j + dy[p];
                tmp += g[nx][ny];
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}