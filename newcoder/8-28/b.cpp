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
using pll = pair<i64, i64>;

// 2025.08.28——19:16:23
// 2025.08.28——19:56:40 accpted
/*
 * 问题在于 第一个值可能和第二个值是对应关系
 * 所以选了第一个值 则可能会导致第二个值发生改变
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<vector<i64> >g(410, vector<i64>(410, 0));
    vector<i64>a(n), ans(410, 0);
    vector<pll>p;
    for (auto& x : a) { cin >> x; }
    i64 res = n;
    if (n % 2 == 1) { res--; }
    for (int i = 0;i < n / 2;i++) {
        i64 st = a[i] + 200, ed = a[n - i - 1] + 200;
        if (st != ed) {
            p.push_back({ st,ed });
            g[st][ed]++;
            g[ed][st]++;
            ans[ed]++, ans[st]++;
        } else {
            res -= 2;
        }
    }
    i64 tres = res;
    for (int i = 0;i <= 400;i++) {
        // deb(i)
        for (int j = 0;j <= 400; j++) {
            if (j == i)continue;
            i64 tmp = tres;
            tmp -= (ans[i] + ans[j] - g[i][j]);
            res = min(tmp, res);
            // if (i == 199 && j == 201) {
            //     de(j)deb(tmp);
            // }
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}