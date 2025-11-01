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
// 2025.10.28——22:39:58
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    i64 oko = 0, oke = 0;
    vector<i64>a(n);
    // vector<pll>idx_o, idx_e;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) { oko = 1; }
        else { oke = 1; }
    }
    auto b = a;
    sort(all(b));
    if (oke && oko) {
        for (int i = 0;i < n;i ++) {
            cout << b[i] << " \n"[i == n - 1];
        }
    } else {
        
        for (int i = 0;i < n;i ++) {
            cout << a[i] << " \n"[i == n - 1];
        }
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