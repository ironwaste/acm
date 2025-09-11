// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
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

// 2025.09.11——02:41:02
// 2025.09.11——03:09:04 wa2 
// 2025.09.11——03:27:34 accpted
/*
 * 没初始化 。。。
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>a(n);
    map<i64, i64>mp, mp2;
    for (auto& x : a) {
        cin >> x;
        mp[x]++;
    }
    i64 ans = 0, mex1 = LLONG_MAX;
    for (i64 i = 0;i <= n;i++) {
        if (!mp.count(i)) { mex1 = min(i, mex1);break; }
    }
    for (auto [x, y] : mp) {
        if (x > mex1 || y > 1) {
            ans += mex1 * y;
            mp2[mex1] += y;
        } else {
            ans += x;
            mp2[x]++;
        }
    }
    if (k == 1) { cout << ans << endl; return; }
    mp = mp2;
    mp2.clear();
    mex1 = LLONG_MAX, ans = 0;
    for (i64 i = 0;i <= n;i++) {
        if (!mp.count(i)) { mex1 = min(i, mex1);break; }
    }
    for (auto [x, y] : mp) {
        if (x > mex1 || y > 1) {
            ans += mex1 * y;
            mp2[mex1] += y;
        } else {
            ans += x;
            mp2[x]++;
        }
    }
    if (k % 2 == 0) { cout << ans << endl; return; }
    mp = mp2;
    mp2.clear();
    mex1 = LLONG_MAX, ans = 0;
    for (i64 i = 0;i <= n;i++) {
        if (!mp.count(i)) { mex1 = min(i, mex1);break; }
    }
    for (auto [x, y] : mp) {
        if (x > mex1 || y > 1) {
            ans += mex1 * y;
            mp2[mex1] += y;
        } else {
            ans += x;
            mp2[x]++;
        }
    }
    if (k % 2 == 1) { cout << ans << endl; return; }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}