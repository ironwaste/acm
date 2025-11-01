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
// 2025.10.28——22:51:41
/*
 *
 *
 *
*/
const i64 N = 1e18;
// 2 * 3 * 5 * 7 * 9 * 11
vector<i64>pri;
const i64 M = 1000 + 10;
i64 isnotp[M];
void init() {
    for (int i = 2;i < M;i ++) {
        if (!isnotp[i]) { pri.push_back(i); }
        for (int j = i;j < M;j +=i) {
            if (!isnotp[j])isnotp[j] = i;
        }
    }
}

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    i64 ans = LLONG_MAX;
    for (i64 & x : a) {
        cin >> x;
        if (x % 2 == 1) {
            ans = min(ans, 2LL);
        } else if (x % 3) {
            ans = min(ans, 3LL);
        }
        if (x - 1 >= 2 && x - 1 <= N) {
            ans = min(ans, x - 1);
        }
        if (x + 1 >= 2 && x + 1 <= N) {
            ans = min(ans,x + 1);
        }
    }
    for (auto p : pri) {
        for (int i = 0;i < n;i ++) {
            if (a[i] % p) {
                ans = min(ans, p);
            }
        }
    }
    cout << ((ans == LLONG_MAX) ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}