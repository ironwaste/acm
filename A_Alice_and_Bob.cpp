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

// 补题——题目链接: https://codeforces.com/contest/2169/problem/A
// 网址：
// 2025.11.14——22:35:21
// 2025.11.14——22:45:31
/*
 *
 *
 *
*/

void solve() {
    i64 n,v;
    cin >> n >> v;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    sort(all(a));
    i64 l = lower_bound(all(a), v) - a.begin();
    i64 r = n - (upper_bound(all(a), v) - a.begin());
    // de(l)deb(r);
    if (r >= l) {
        cout << v + 1 << endl;
    }else{
        cout << max(v - 1,0LL) << endl;
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