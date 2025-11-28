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

// 补题——题目链接: https://codeforces.com/contest/2170/problem/C
// 网址：
// 2025.11.28——22:51:30
// 2025.11.28——23:20:07 ac
/*
 * r <= k // 2 的有用
 * x = y + r 即可  则 y > r 且 x >= 2 * r
 * q 几乎可以任意
 * sb 四舍五入  傻逼翻译
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>q(n), r(n);
    int cnt1 = 0;
    for (auto& x : q) { cin >> x; }
    for (auto& x : r) { cin >> x; }
    sort(all(q), greater<i64>());
    sort(all(r));
    int itq = cnt1, itr = 0;
    i64 ans = 0;
    // two pointor 咋双啊。。。
    // for (;itq < n && q[itq] <= k;itq ++) {
        // i64 v = q[itq];
        // x / y = v = qi;
        // x % y = r;
        // 假设 y >= r
        // 应该先遍历r
    //     while (itr < n&&) {
    //     }
    // }
    
    for (;itr < n && r[itr] < k;itr++) {
        i64 y = r[itr] + 1;
        i64 vr = r[itr];
        // 求 qi = round(x/y);
        // i64 x = y + r[itr];
        while (itq < n && q[itq]  * y + vr > k) {
            itq++;
        }
        if (itq < n && q[itq] * y + vr <= k) {
            // de(itq)de(q[itq])de(itr)deb(vr)
            itq++;
            ans++;
        }
    }

    cout << ans << endl;
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