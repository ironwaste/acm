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

// 补题——题目链接: https://codeforces.com/contest/2152/problem/D
// 网址：
// 2025.10.04——00:21:25
/*
 *
 * 就是 判断是否是 2 的 指数倍
 * 如果不是 一定可以使其 + 1
 *
 * 多个值存在时 只有 多个 2 ^ k + 1的值原本 解是 k
 * 而之后的 解为 k + 1
 * 找最高位的 1 的 位置 L
 * 答案为 L - 1 如果是 指数倍
 *
 * 否则 是 L 除了 2 ^ k + 1
 *
 *
*/
const i64 limit = 1e9 + 10;
set<i64>wv;
void init() {
    for (i64 i = 2;i < limit;i *= 2LL) {
        wv.insert(i + 1LL);
    }
}
bool is2(i64 x) {
    i64 num = __builtin_popcountll(x);
    if (num == 1) { return true; }
    return false;
}

i64 calc(i64 x) {
    if (x == 2) {
        return 1LL;
    } else {
        x--;
        i64 tmp = x;
        i64 L = 0;
        while (tmp > 0) {
            tmp >>= 1LL;
            L ++;
        }
        if (is2(x)) {
            return L - 1;
        } else {
            return L;
        }
    }
}
void solve() {
    i64 n, q;
    cin >> n >> q;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    vector<i64>v(n, 0), f(n, 0);
    for (int i = 0;i < n;i++) {
        v[i] = calc(a[i]);
        if (wv.count(a[i])) { f[i] = 1; }
    }
    vector<i64>prv(n + 1, 0), prf(n + 1, 0);
    partial_sum(all(v), prv.begin() + 1);
    partial_sum(all(f), prf.begin() + 1);
    while (q--) {
        i64 l, r;
        cin >> l >> r;
        i64 ans = prv[r] - prv[l - 1];
        ans += max(0LL, prf[r] - prf[l - 1]) / 2;
        cout << ans << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}