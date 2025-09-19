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
// 2025.09.18——15:48:20
// 2025.09.18——16:27:34 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n, q;
    cin >> n >> q;
    vector<i64>a(n + 1, 0);
    for (int i = 1;i <= n;i++) { cin >> a[i]; }
    vector<i64>aj(n + 1, 0), ajj(n + 1, 0);
    vector<i64>prxjj(n + 1,0),prxa(n + 1, 0), prxj(n + 1, 0);
    for (i64 i = 1;i <= n;i++) {
        ajj[i] = a[i] - a[i] * i * i;
        aj[i] = i * a[i];
    }
    partial_sum(all(ajj), prxjj.begin());
    partial_sum(all(aj), prxj.begin());
    partial_sum(all(a), prxa.begin());

    while (q--) {
        i64 L, R;
        cin >> L >> R;
        i64 k = R - L - R * L;
        i64 vjj = prxjj[R] - prxjj[L - 1];
        i64 vj  = prxj[R] - prxj[L - 1];
        i64 v   = prxa[R] - prxa[L - 1];
        cout << vjj + vj * (L + R) + v * k << endl;
    }


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