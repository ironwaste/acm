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

// 补题——题目链接:
// 网址：
// 2025.11.01——20:14:24
/*
 *
 *
 *
*/

void solve() {
    i64 n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<i64>pra(n + 1, 0), prb(n + 1, 0);
    for (int i = 1;i <= n;i++) {
        pra[i] = pra[i - 1];
        prb[i] = prb[i - 1];
        if (s[i] == 'a') {
            pra[i]++;
        } else {
            prb[i]++;
        }
    }
    i64 ans = 0;
    for (int l = 1;l <= n;l++) {
        i64 r = lower_bound(all(pra), pra[l - 1] + a) - pra.begin();
        i64 br = lower_bound(all(prb), prb[l - 1] + b) - prb.begin() - 1;
        ans += max(0LL, br - r + 1);
    }
    cout << ans << endl;
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