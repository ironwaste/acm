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

// 补题——题目链接: https://codeforces.com/problemset/problem/1337/D
// 网址：
// 2025.09.19——22:53:49
// 2025.09.19——23:47:52 accpted
/*
 * 我想到了答案 但是不确定不敢写。。。
 * 这就很难受了
 * 这道题 真的是看谁代码实现来的好了 。。。
 * 按照中间值区分
 *
*/
i64 pp(i64 x) {
    return x * x;
}
i64 calc(i64 x, i64 y, i64 z) {
    return pp(x - y) + pp(y - z) + pp(x - z);
}

void solve() {
    i64 n, m, q;
    cin >> n >> m >> q;
    vector<i64>r(n), g(m), b(q);
    for (auto& x : r)cin >> x;
    for (auto& x : g)cin >> x;
    for (auto& x : b)cin >> x;
    sort(all(r));
    sort(all(g));
    sort(all(b));
    i64 ans = LLONG_MAX;
    for (int i = 0;i < n;i++) {
        i64 v = r[i];
        i64 g1 = g[max(0LL, upper_bound(all(g), v) - g.begin() - 1LL)],
            g2 = g[min(m - 1, lower_bound(all(g), v) - g.begin())];

        i64 b1 = b[max(0LL, upper_bound(all(b), g1) - b.begin() - 1LL)],
            b2 = b[min(q - 1, lower_bound(all(b), g1) - b.begin())],
            b3 = b[min(q - 1, lower_bound(all(b), v) - b.begin())],

            b4 = b[max(0LL, upper_bound(all(b), v) - b.begin() - 1)],
            b5 = b[min(q - 1, lower_bound(all(b), v) - b.begin())],
            b6 = b[min(q - 1, lower_bound(all(b), g2) - b.begin())];

        ans = min(ans, calc(v, g1, b1));
        ans = min(ans, calc(v, g1, b2));
        ans = min(ans, calc(v, g1, b3));
        ans = min(ans, calc(v, g2, b4));
        ans = min(ans, calc(v, g2, b5));
        ans = min(ans, calc(v, g2, b6));
    }
    cout << ans << endl;
}

// 正解 优解
// void solve() {
//     i64 n, m, q;
//     cin >> n >> m >> q;
//     vector<i64>R(n), G(m), B(q);
//     for (auto &x : R)cin >> x;
//     for (auto &x : G)cin >> x;
//     for (auto &x : B)cin >> x;
//     sort(all(R));
//     sort(all(G));
//     sort(all(B));
//     i64 ans = LLONG_MAX;
//     function<void(vector<i64>& r, vector<i64>& g, vector<i64>& b)>check;
//     check = [&](vector<i64>& r, vector<i64>& g, vector<i64>& b)->void {
//         i64 szy = g.size(), szz = b.size();
//         // de(szy)deb(szz)
//         for (auto x : r) {
//             // de(x)
//             i64 y = g[max(upper_bound(all(g), x) - g.begin() - 1, 0LL)];
//             i64 z = b[min(lower_bound(all(b), x) - b.begin(), szz - 1)];
//             ans = min(ans, calc(x, y, z));
//             // de(ans)de(x)de(y)deb(z)
//         }
//         // deb('-')
//         };
//     check(R, G, B);
//     check(R, B, G);
//     check(G, R, B);
//     check(G, B, R);
//     check(B, G, R);
//     check(B, R, G);
 
//     cout << ans << endl;
// }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
