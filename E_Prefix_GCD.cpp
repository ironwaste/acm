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

// 补题——题目链接: https://codeforces.com/contest/2013/problem/E
// 网址：
// 2025.09.19——11:57:18
// 2025.09.19——12:21:43 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    i64 base = 0;
    for (auto& x : a) {
        cin >> x;
        base = __gcd(x, base);
    }
    for (auto& x : a) { x /= base; }
    sort(all(a));
    // for (auto x : a) {
    //     cout << x << " ";
    // }cout << endl;
    vector<i64>vis(n, 0);
    vis[0] = 1;
    i64 ans = a[0];
    i64 anssum = n;
    while (ans > 1) {
        // de(ans);
        i64 gdb = ans, id = 0;
        anssum += ans - 1;
        for (int i = 0;i < n;i++) {
            if ( !vis[i] ) {
                i64 tmp = __gcd(ans, a[i]);
                if (tmp < gdb) {
                    id = i;
                    gdb = tmp;
                }
            }
        }
        // deb(id);
        vis[id] = 1;
        ans = gdb;
    }

    cout << anssum * base << endl;





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