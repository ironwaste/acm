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

// 补题——题目链接: https://codeforces.com/contest/1138/problem/D
// 网址：
// 2025.09.19——19:52:37
// 2025.09.19——19:56:51 re， 没考虑到除数为0的情况
// 2025.09.19——20:00:07 wa 6 ？？？！！！
/*
 * 字符串 拓展KMP Z函数加 + 字符串哈希。。。。
 * 确实不熟练且不会啊 要补一下了 先暂留
 *
*/

void solve() {
    string s, t;
    cin >> s >> t;
    i64 t1 = 0, t0 = 0, s0 = 0, s1 = 0;
    i64 sz = s.size(), tz = t.size();
    for (int i = 0;i < sz;i++) {
        if (s[i] == '1') { s1++; } else { s0++; }
    }
    for (int i = 0;i < tz;i++) {
        if (t[i] == '1') {
            t1++;
        } else { t0++; }
    }
    i64 k = 0;
    if (t1 && t0) {
        k = min(s1 / t1, s0 / t0);
    } else if (t1) {
        k = s1 / t1;
    }else{
        k = s0 / t0;
    }
    s1 -= k * t1;
    s0 -= k * t0;
    for (int i = 0;i < k;i++) {
        cout << t;
    }
    for (int i = 0;i < s1;i ++) {cout << '1';}
    for (int i = 0;i < s0;i++) { cout << '0'; }
    return;
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