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
#define N 510

using namespace std;


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/P8186
// 网址：
// 2025.11.11——17:32:12
// ed :2025.11.11——18:00:16
// 2025.11.11——20:11:33
/*
 *
 * 可达性判断 + 判环
 * 题面是  可能得到的 最好的礼物
 * 不需要最后给出的结果一定是匹配的
 *
*/

void solve() {
    i64 n;
    cin >> n;
    bitset<N>g[N];
    vector<i64>to[N];
    for (int i = 0;i < n;i++) {
        i64 x;
        for (int j = 0;j < n;j++) {
            cin >> x;
            x--;
            g[i][x] = 1;
            to[i].push_back(x);
            if (x == i) {
                j++;
                for (;j < n;j++) { cin >> x; }
                break;
            }
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (g[j][i]) g[j] |= g[i];
        }
    }

    for (int i = 0;i < n;i++) {
        i64 ok = 0;
        for (int j = 0;j < to[i].size();j++) {
            if (g[to[i][j]][i]) {
                cout << to[i][j] + 1 << endl;
                ok = 1;
                break;
            }
        }
        if (!ok)cout << i + 1 << endl;
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