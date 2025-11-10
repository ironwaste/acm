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

// 补题——题目链接: https://codeforces.com/contest/2163/problem/B
// 网址：
// 2025.11.10——23:09:26
/*
 * 从1的位置往外扩
 * 如果可以合并就 合并  不会写啊。。。。
 * 分为前缀最大 值+下标  前缀最小值+下标
 * 后缀最大值 + 下标  后缀最小值+下标
 *
 *
 * 直接判断 最大值 最小值
 * 以及 最大位置  最小位置 是否能被 变1
 * 即可求出解
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    string t;
    cin >> t;
    // for (int i =) {

    // }
    if (t[0] == '1' || t[n - 1] == '1') {
        cout << -1 << endl;
        return;
    }
    vector<pll>cnt1, cnt0;
    i64 mi = n + 1, mx = -1;
    i64 mil = n + 1, mxr = -1;
    i64 idn = 0, id1 = 0;

    for (i64 i = 0;i < n;i++) {
        if (a[i] == n) { idn = i; }
        if (a[i] == 1) { id1 = i; }
        if (t[i] == '1') {
            cnt1.push_back({ a[i],i });
            mil = min(mil, i);
            mxr = max(mxr, i);
            mi = min(mi, a[i]);
            mx = max(mx, a[i]);
        } else {
            cnt0.push_back({ a[i],i });
        }
    }
    if (cnt1.size() == 0) { cout << 0 << endl; return; }
    if (mi == 1 || mx == n) {
        cout << -1 << endl; return;
    }


    i64 mx1n = max(id1, idn), mi1n = min(id1, idn);
    if (mi1n < mil && mx1n > mxr) {
        cout << 1 << endl;
        cout << mi1n + 1 << " " << mx1n + 1 << endl;
        return;
    } else {
        cout << 5 << endl;
        cout << mi1n + 1 << " " << mx1n + 1 << endl;
        cout << 1 << " " << mx1n + 1 << endl;
        cout << mx1n + 1 << " " << n << endl;
        cout << 1 << " " << mi1n + 1 << endl;
        cout << mi1n + 1 << " " << n << endl;
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

