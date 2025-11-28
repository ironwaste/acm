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

// 补题——题目链接: https://codeforces.com/contest/2163/problem/C
// 网址：
// 2025.11.11——00:06:42
/*
 *
 *
 *
*/
pll maxin(pll a, pll b) {
    pll res = a;
    res.fi = min({ a.fi, b.fi ,a.se,b.se });
    res.se = max({ a.fi, b.fi ,a.se,b.se });
    return res;
}
void solve() {
    i64 n;
    cin >> n;
    vector<vector<i64> >a(2, vector<i64>(n, 0));
    vector<vector<pll>>mxi(2, vector<pll>(n, { 0,0 }));
    for (int i = 0;i < 2;i++) {
        for (int j = 0;j < n;j++) {
            cin >> a[i][j];
            mxi[i][j].se = mxi[i][j].fi = a[i][j];
        }
    }
    for (int i = n - 2;i >= 0;i--) {
        mxi[1][i] = maxin(mxi[1][i], mxi[1][i + 1]);
    }
    for (int i = 1;i < n;i++) {
        mxi[0][i] = maxin(mxi[0][i], mxi[0][i - 1]);
    }
    i64 mil = 0, mxr = 2 * n + 1;
    map<i64, i64>mp;
    for (int i = 0;i < n;i++) {
        pll res = mxi[0][i];
        res = maxin(mxi[1][i], res);
        if (mp.count(res.fi) && res.se >= res.fi) {
            i64 v = mp[res.fi];
            mp[res.fi] = min(v, res.se);
        } else {
            mp[res.fi] = res.se;
        }
    }
    i64 sum = 0, prl = 0;
    vector<i64>ans(2 * n + 10, 0);
    for (auto [x, y] : mp) {
        ans[x] = 2 * n + 1 - y;
    }
    i64 prmx = 0;
    for (int i = 2 * n + 1;i > 0;i--) {
        prmx = max(prmx, ans[i]);
        sum += prmx;
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        // deb(T);
        solve();
    }
    return 0;
}