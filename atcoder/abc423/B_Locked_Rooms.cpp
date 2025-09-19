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

// 补题——题目链接: https://atcoder.jp/contests/abc423/tasks/abc423_b
// 网址：
// 2025.09.18——15:08:01
// 2025.09.18——15:11:23 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>L(n, 0);
    i64 ans = 2;
    for (int i = 0;i < n;i++) { cin >> L[i]; }
    for (int i = 0;i < n;i++) {
        if (L[i]==0)ans++;
        else { break; }
    }
    for (int i = n-1;i >= 0;i--) {
        if (L[i]==0)ans++;
        else { break; }
    }
    ans = n + 1 - ans;
    cout << max(0LL, ans) << endl;

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
