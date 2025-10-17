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


void solve() {
    i64 n, rk, ck, rd, cd;
    cin >> n;
    cin >> rk >> ck >> rd >> cd;
    i64 dr = rk - rd, dc = ck - cd;
    i64 r, c;
    r = rk < rd;
    c = ck < cd;
    if (r == 1) {
        r = 0;
    } else { r = n; }

    if (c == 1) {
        c = 0;

    } else { c = n; }

    if (dr == 0) {
        cout << abs(c - cd) << endl;
    } else if (dc == 0) {
        cout << abs(r - rd) << endl;
    } else {
        cout << max(abs(r - rd), abs(c - cd)) <<endl;
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
