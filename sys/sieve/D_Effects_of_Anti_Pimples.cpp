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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://codeforces.com/problemset/problem/1877/D
// 网址：
// 2025.09.17——21:18:00
/*
 *
 *
 *
*/
i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1) res = a * res % mod3;
        a = a * a % mod3;
        b >>= 1;
    }
    return res;
}
void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n + 1,0);
    for (int i = 1;i <= n;i ++) { cin >> a[i]; }
    vector<i64>mx(n + 1, 0);
    for (i64 i = 1;i <= n;i ++) {
        i64 v = a[i];
        for (i64 j = i;j <= n;j += i) {
            v = max(a[j], v);
            mx[i] = v;
        }
        // de(mx[i])

    }
    i64 ans = 0;
    sort(all(mx), greater<i64>());
    for (i64 i = 1;i <= n;i++) {
        (ans += mx[i - 1] * pw(2LL, n - i) % mod3) %= mod3;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}