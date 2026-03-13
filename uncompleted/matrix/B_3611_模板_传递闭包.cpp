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


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/B3611
// 网址：
// 2025.11.11——16:36:14
// 2025.11.11——16:40:17 ac
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<vector<i64> >g(n, vector<i64>(n, 0));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> g[i][j];
        }
    }
    for (int k = 0;k < n;k++) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j ++) {
                if (!g[i][j]) {
                    g[i][j] |= (g[i][k] & g[k][j]);
                }
            }
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << g[i][j] << " ";
        }cout << endl;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}