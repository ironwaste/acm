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

// 补题——题目链接: https://codeforces.com/problemset/problem/1034/A
// 网址：
// 2025.09.17——15:19:55
/*
 *
 * 如果不将 所有数字的 共同gcd 除去之后在进行找最大的数
 * 则会产生误差 样例
 * 3
 * 2 4 8
 * answer : 1
 *
 * 5
 * 8 6 7 3 7
 * answer : 3
 *
*/
const i64 N = 2e7 + 10;
i64 minp[N];

void init() {
    minp[1] = 1;
    for (i64 i = 2;i < N;i++) {
        if (!minp[i]) {
            minp[i] = i;
            for (i64 j = i * i;j < N;j += i) {
                if (!minp[j]) { minp[j] = i; }
            }
        }
    }
}

void solve() {
    init();
    i64 n;
    cin >> n;
    map<i64, i64>mp;
    vector<i64>a(n);
    i64 gd = 0;
    for (int i = 0;i < n;i++) {
        i64 x;
        cin >> x;
        a[i] = x;
        gd = __gcd(gd, x);
    }
    for (int i = 0;i < n;i ++) {
        i64 x = a[i] / gd;
        while (x > 1) {
            i64 v = minp[x];
            mp[v]++;
            while (x % v == 0) { x /= v; }
        }
    }

    i64 ans = -1;
    for (auto [x, y] : mp) {
        ans = max(ans, y);
    }
    if (ans == -1)cout << ans << endl;
    else cout << n - ans << endl;
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