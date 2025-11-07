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

// 补题——题目链接: https://codeforces.com/problemset/problem/2121/F
// 网址：https://codeforces.com/blog/entry/143822
// 2025.11.04——03:42:32
/*
 * two pointer
 * wok !! 好题！！！！ 一种特殊另类的双指针
 * 但是好题
 *
*/

void solve() {
    i64 n, s, x;
    cin >> n >> s >> x;
    vector<i64>a(n), prx(n + 1, 0);
    for (auto& x : a) { cin >> x; }
    for (int i = 0;i < n;i++) { prx[i + 1] = prx[i] + a[i]; }
    map<i64, i64>cnt;
    i64 sum = 0;
    for (int r = 0, lef = 0;r < n;r++) {
        if (a[r] == x) {
            for (int i = lef;i <= r;i++) { cnt[prx[i]]++; }
            lef = r + 1;
        }
        if (a[r] > x) { cnt.clear(); lef = r + 1;continue; }
        i64 v = prx[r + 1] - s;
        sum += cnt[v];
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
        solve();
    }
    return 0;
}