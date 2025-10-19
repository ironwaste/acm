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
// 2025.10.18——00:28:40
/*
 *
 *
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<pll> lr;
    vector<i64>a(n + 1, 0), st(n, 0), ed(n, 0);
    i64 one = -1;
    for (i64 i = 0;i < m;i++) {
        i64 l, r;
        cin >> l >> r;
        l--, r--;
        // if (l != r) {
        st[l] = 1;
        ed[r] = 1;
        // }
        // if (l == r) { st[l] = 1, ed[r] = 1; }
        lr.push_back({ l,r });
        a[l]++;
        a[r + 1]--;
    }

    // deb(one);
    auto prx = a;
    partial_sum(all(a), prx.begin());
    i64 ok = -1;
    for (int i = 0;i < n;i++) {
        if (prx[i] == m) { ok = i; }
    }
    vector<i64>ans(n, -1);
    i64 one1 = -1;
    if (ok == -1) {
        for (int i = 0;i < n - 1;i++) {
            if (!ed[i]) {
                one = i;
                ans[i + 1] = 1;
                ans[i] = 0;
                break;
            }
            if (!st[i + 1]) {
                one1 = i + 1;
                ans[i + 1] = 0;
                ans[i] = 1;
                break;
            }
        }
    }
    i64 mex = 0;
    if (ok != -1) {
        ans[ok] = 0;
        mex = 1;
        for (int i = 0;i < n && mex < n;i++, mex++) {
            while (i < n && ans[i] != -1) { i++; }
            ans[i] = mex;
        }
    } else if (one != -1 || one1 != -1) {
        mex = 2;
        for (int i = 0;i < n && mex < n;i++, mex++) {
            while (i < n && ans[i] != -1) { i++; }
            ans[i] = mex;
        }

    } else {
        ans[0] = 0;
        ans[1] = 2;
        ans[2] = 1;
        for (int i = 3;i < n;i++) {
            ans[i] = i;
        }
    }
    for (int i = 0;i < n;i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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