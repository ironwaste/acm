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

// 补题——题目链接:
// 网址：
// 2025.09.19——14:31:22
// 2025.09.19——14:34:43 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n, g, b;
    cin >> n >> g >> b;
    i64 v = g + b;
    i64 d = (n + 1) / 2;
    i64 k = d / g, res = d % g;
    i64 ans = 0;
    if (res == 0) {
        ans = k * v - b;
    } else {
        ans = k * v + res;
    }
    cout << max(ans,n) << endl;
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