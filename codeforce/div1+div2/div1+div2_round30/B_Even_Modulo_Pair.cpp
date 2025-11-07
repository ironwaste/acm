#include<bits/stdc++.h>
#include<climits>


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
// 2025.11.06——22:38:35
/*
 *
 *
 *
*/

void solve() {

    i64 n;
    cin >> n;
    vector<i64>a(n);
    // i64 even = 0;
    vector<i64>e, o;
    i64 idxe = -1;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            if (idxe == -1) { idxe = i; }
            e.push_back(a[i]);
        } else { o.push_back(a[i]); }
    }
    if (a[0] == 1) {
        cout << a[0] << " " << a[1] << endl;
        return;
    } else if (e.size() >= 2) {
        cout << e[0] << " " << e[1] << endl;
        return;
    } else if (idxe != -1) {
        i64 y = a[idxe];
        for (int i = 0;i < idxe;i++) {
            if ((y % a[i]) % 2 == 0) {
                cout << a[i] << " " << y << endl;
                return;
            }
        }
    }

    // 奇数倍
    i64 sz = o.size();
    i64 mx = o.back();


    for (int i = 0;i < sz - 1;i++) {
        i64 x = o[i];
        i64 lim = mx / x;
        for (i64 k = 1;k <= lim;) {
            i64 v = x * k, up = x * (k + 1);
            auto it = lower_bound(o.begin() + i + 1, o.end(), v);
            if (it != o.end() && *it <= up) {
                cout << x << " " << *it << endl;
                return;
            } else {
                if (it == o.end()) { break; }
                i64 tmpk = (*it) / x;
                if (tmpk % 2 == 0) { tmpk--; }
                k = max(k + 2LL, tmpk);
            }
        }
    }
    cout << -1 << endl;
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