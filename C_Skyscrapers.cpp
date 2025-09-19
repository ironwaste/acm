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

// 补题——题目链接: https://codeforces.com/problemset/problem/1138/C
// 网址：
// 2025.09.19——19:35:21
// 2025.09.19——19:47:21 accpted
/*
 *
 * 做的很快 感觉没什么参考意义，但是 unique使用还是
 * 不熟练 是先sort 然后unique 返回指针，erase 到end就好
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64> >a(n, vector<i64>(m));
    vector<i64>row[m], col[n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> a[i][j];
            i64 v = a[i][j];
            row[j].push_back(v);
            col[i].push_back(v);
        }
    }
    for (int i = 0;i < n;i++) {
        sort(all(col[i]));
        col[i].erase(unique(all(col[i])),col[i].end());
    }
    for (int i = 0;i < m;i++) {
        sort(all(row[i]));
        row[i].erase(unique(all(row[i])),row[i].end());
    }
    vector<vector<i64> >h(n, vector<i64>(m));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            i64 v = a[i][j];
            i64 r = lower_bound(all(row[j]), v) - row[j].begin();
            i64 c = lower_bound(all(col[i]), v) - col[i].begin();
            i64 w = max(r, c);
            i64 ww = max(row[j].size() - r, col[i].size() - c);
            h[i][j] = w + ww;
            cout << w + ww << " ";
        }cout << endl;
    }
    // for () {
        
    // }
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