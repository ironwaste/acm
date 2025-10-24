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

// 补题——题目链接: https://codeforces.com/contest/2154/problem/C2
// 网址：
// 2025.10.19——23:12:29
/*
 *
 * 0 和 1 的情况都很好解决，
 * 就是成本为2 的情况如何取最小值
 *
 * 求所有的因子 ， sqrt(n);
 * 那么就是 500 左右 刚好 1e8
 * 特殊样例 ：
 * 1
 * 5 77
 * 2 19
 *
*/
const i64 N = 2e5 + 10;
i64 minp[N];
vector<set< i64 > >pfac(N + 1);
void init() {
    minp[1] = 1;
    for (int i = 2;i < N;i++) {
        for (int j = i;j < N;j += i) {
            if (!minp[j])minp[j] = i;
        }
    }
    for (i64 i = 2;i < N;i++) {
        i64 x = i;
        while (x > 1) {
            i64 v = minp[x];
            pfac[i].insert(v);
            while (v == minp[x]) {
                x /= v;
            }
        }
    }
}



void solve() {
    i64 n;cin >> n;
    vector<pll>a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i].se;
    }

    for (int i = 0;i < n;i++) {
        cin >> a[i].fi;
    }
    sort(all(a));
    i64 ans = a[0].fi + a[1].fi;
    map<i64, i64>cnt;
    for (int i = 0;i < n;i++) {
        i64 v = a[i].se;

        for (auto x : pfac[v]) {
            if (cnt.count(x)) { ans = 0; }
            cnt[x]++;
        }
    }

    for (int i = 0;i < n;i++) {
        i64 w = a[i].fi,v = a[i].se;
        for (auto x : pfac[v]) {
            cnt[x]--;
        }
        for (auto x : pfac[v + 1]) {
            if (cnt.count(x) && cnt[x] > 0) {
                ans = min(ans, w);
            }
        }
        for (auto x : pfac[v]) {
            cnt[x] ++;
        }
    }


    set<i64>check;
    for (int i = 1;i < n;i++) {
        i64 w = a[i].fi, v = a[i].se;
        for (auto x : pfac[v]) {
            check.insert(x);
        }
    }
    i64 w = a[0].fi, v = a[0].se;
    for (auto x : check) {
        i64 k = x - (v % x);
        if (k == x) { x = 0; }
        ans = min(ans, k * w);
    }
    cout << ans << endl;









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