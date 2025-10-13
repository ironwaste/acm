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

// 补题——题目链接: https://codeforces.com/contest/803/problem/C
// 网址：
// 2025.09.18——22:10:29
/*
 *
 *
 *
*/
const i64 N = 2e6;
void solve() {
    i64 n, k;
    cin >> n >> k;
    if (k >= N) {
        cout << -1 << endl;
        return;
    }
    i64 f = (k + 1LL) * k / 2;
    i64 l = 1, r = n / f, ans = -1;
    for (i64 i = 1;i * i <= n;i++) {
        if (n % i != 0)continue;
        i64 v = n - f * i, j = n / i;
        i64 v1 = n - f * j;
        if (v >= 0 && v % i == 0) {
            ans = max(i, ans);
        }
        
        if (v1 >= 0 && v1 % j == 0) {
            ans = max(j, ans);
        }
    }
    if (ans == -1) {
        cout << -1 << endl;
        return;
    }
    // vector<i64>v(k);
    for (int i = 0;i < k - 1;i++) {
        cout << ans * (i + 1) << " ";
        n -= ans * (i + 1);
    }
    cout << n << endl;

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

/* 测试样例：
3000000021 3
answer: 3 6 3000000012

24 2
answer: 8 16
*/