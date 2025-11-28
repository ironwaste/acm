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
#define N 300

using namespace std;

using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/P2835
// 网址：
// 2025.11.11——17:07:58
// 2025.11.11——17:31:46
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    bitset<N>g[N];
    for (int i = 0;i < n;i++) {
        i64 x;
        while (cin >> x) {
            if (x == 0)break;
            g[i][x - 1] = 1;
        }
        g[i][i] = 1;

    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (g[j][i]) {
                g[j] |= g[i];
            }
        }
    }

    i64 cnt = 0;
    vector<i64>vis(n, -1);
    for (int i = 0;i < n;i++) {
        if (vis[i] == -1) { vis[i] = cnt++; }
        // 因为这里是按照顺序来的 当最后一个 覆盖了全部所有
        // 所以要在最后进行一边
        for (int j = 0;j < n;j++) {
            if (g[i][j]) {
                vis[j] = vis[i];
            }
        }
    }
    unordered_set<i64>s;
    for (int i = 0;i < n;i++) {
        s.insert(vis[i]);
    }
    cout << s.size() << endl;
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