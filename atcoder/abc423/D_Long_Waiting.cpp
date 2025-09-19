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
// 2025.09.18——15:31:30
// 2025.09.18——15:47:58 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>a(n), b(n), c(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<i64>ans(n, 0);
    priority_queue<pll, vector<pll>, greater<pll>>q;
    i64 cntk = 0;
    for (i64 i = 0, t = 0;i < n;) {
        while (i < n && k - cntk >= c[i]) {
            i64 st = max(t, a[i]);
            i64 ed = st + b[i];
            cntk += c[i];
            q.push({ ed,c[i] });
            ans[i] = st;
            i++;
        }

        while (i < n && !q.empty()&& k - cntk < c[i]) {
            auto [st, v] = q.top();
            cntk -= v;
            t = st;
            q.pop();
        }
    }

    for (int i = 0;i < n;i++) {
        cout << ans[i] << endl;
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