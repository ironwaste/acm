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

// 补题——题目链接: https://codeforces.com/contest/2154/problem/B
// 网址：
// 2025.10.19——22:41:30
// 2025.10.19——22:50:24
/*
 *
*/

void solve() {

    i64 n;
    cin >> n;
    vector<i64>a(n), mx(n, 0);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if (i != 0) {
            mx[i] = max(a[i], mx[i - 1]);
        } else {
            mx[i] = a[i];
        }
    }
    i64 ans = 0;
    for (int i = 1;i < n;i += 2) {
        if (mx[i] > a[i]) {
            a[i] = mx[i];
        }
    }

    for (int i = 0;i < n;i += 2) {
        i64 v = LLONG_MAX;
        if (i + 1 < n) {
            v = min(v, a[i + 1]);
        }
        if (i - 1 > 0) {
            v = min(v, a[i - 1]);
        }
        v--;
        ans += max(0LL, a[i] - v);
    }
    cout << ans << endl;

}

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