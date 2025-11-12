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

// 补题——题目链接: https://qoj.ac/contest/1799/problem/9917
// 网址：
// 2025.11.12——16:26:34
// 2025.11.12——16:35:18
/*
 * 
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    i64 mx = -1;
    for (auto& x : a) {
        cin >> x;
    }
    mx = *max_element(all(a));
    for (int i = 0;i < n;i++) {
        if (a[i] == mx) {
            cout << i + 1 << " ";
        }
    }cout << endl;
    return;

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