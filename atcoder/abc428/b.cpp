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

// 补题——题目链接: https://atcoder.jp/contests/abc428/tasks/abc428_b
// 网址：
// 2025.10.19——11:38:22
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<string, i64>mp;
    for (int i = 0;i < n - k + 1;i++) {
        string tmp = s.substr(i, k);
        // cout << tmp << endl;
        mp[tmp]++;
    }
    i64 mx = 0;
    for (auto [x, y] : mp) {
        mx = max(y, mx);
    }
    vector<string>ans;
    for (auto [x, y] : mp) {
        if (y == mx) {
            ans.push_back(x);
        }
    }
    i64 sz = ans.size();
    cout << mx << endl;
    for (int i = 0;i < sz;i ++) {
        cout << ans[i] << " \n"[i == sz - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}