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

// 补题——题目链接: https://codeforces.com/contest/2169/problem/C
// 网址：
// 2025.11.14——23:04:38

// 2025.11.14——23:24:52
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);

    i64 sum = 0;
    for (auto& x : a) { cin >> x;sum += x; }

    vector<i64>prx(n + 1, 0);

    partial_sum(all(a), prx.begin() + 1);

    i64 mx = 0;
    for (i64 l = 1, r = 1;l <= n && r <= n;l++) {
        if (l <= r) {
            r = l;
        }
        while (r <= n && prx[r] - prx[l - 1] <= (r - l + 1) * (l + r)) {
            mx = max(mx, (r - l + 1LL) * (l + r) - (prx[r] - prx[l - 1]));
            r++;
        }
    }

    cout << mx + sum << endl;

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
