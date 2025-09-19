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

// 补题——题目链接: https://codeforces.com/problemset/problem/1694/C
// 网址：
// 2025.09.19——16:04:23
/*
 * 很像杭州省赛2025 的题目 ？？？
 * 第三题铜牌题那道
 * 这种题目 我真的不会写 。。。。
 *
*/

void solve() {
    i64 n,sum =0;
    cin >> n;
    vector<i64>a(n), b(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        sum += a[i];
        if (i >= 1)b[i] = a[i] + b[i - 1];
        else { b[i] = a[i]; }
    }
    i64 ok = 1;
    if (sum != 0)ok = 0;
    for (int i = 0, j = INT_MAX;i < n;i++) {
        if (b[i] == 0) {
            j = min(j, i);
        } else if (b[i] < 0) {
            ok = 0;
            break;
        } else if (j < i) {
            ok = 0;
            break;
        }
    }
    cout << ((ok) ? "Yes" : "No") << endl;
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