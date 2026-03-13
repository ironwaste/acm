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

// 补题——题目链接: https://codeforces.com/contest/2169/problem/B
// 网址：
// 2025.11.14——22:45:57
// 2025.11.14——23:04:22
/*
 *
 *
 *
*/

void solve() {
    string s;
    cin >> s;
    i64 n = s.size();
    i64 ok = 0;
    for (int i = 0;i < n - 1;i++) {
        if (s[i] == '>' && s[i + 1] == '<') { ok = 1; }
        if (s[i] == '*' && s[i + 1] == '<') { ok = 1; }
        if (s[i] == '>' && s[i + 1] == '*') { ok = 1; }
        if (s[i] == '*' && s[i + 1] == '*') { ok = 1; }
    }
    if (ok == 1) { cout << -1 << endl; return; }
    int ans = 0;
    vector<int>dis(n + 1, 0);
    for (int i = 0;i < n;i++) {
        int j = i + 1;
        if (s[i] == '<' || s[i] == '*') {
            dis[j] = dis[j - 1] + 1;
            ans = max(ans, dis[j]);
        } else {
            break;
        }
    }
    vector<int>suf(n + 1, 0);
    for (int i = n - 1;i >= 0;i--) {
        if (s[i] == '>' || s[i] == '*') {
            // deb(i)
            suf[i] = suf[i + 1] + 1;
            ans = max(ans, suf[i]);
        } else {
            break;
        }
    }
    // for (int i = 0;i <= n;i++) {
    //     de(i)
    //         deb(suf[i]);
    // }
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