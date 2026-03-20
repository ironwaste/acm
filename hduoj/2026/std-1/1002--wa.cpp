// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
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
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 2026.03.20——20:05:38
/*
 * 这个答案可以是 非连续 就是单纯对于子序列的
 *
 *
*/
const int N = 2e5 + 10;
vector<i64>prx;


void init() {
    i64 cnt = 0;
    prx.push_back(0);
    for (int i = 1;;i++) {
        cnt += i;
        prx.push_back(cnt);
        if (cnt > N)break;
    }
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    if (n >= k) {
        cout << -1 << endl;
        return;
    }

    auto ptr = lower_bound(all(prx), k);
    ptr--;
    i64 idx = ptr - prx.begin();
    while (idx + (k - *ptr - 1) < n) {
        ptr--;
        idx--;
    }
    // de(idx)deb(*ptr);
    for (i64 i = 1;i <= idx;i++) {
        cout << i << " ";
    }
    int dif = k - *ptr - 1 + idx - n;
    // deb(dif)
    for (i64 i = k + 1, cnt = 1;cnt <= n - idx;cnt++, i += k) {
        cout << i << " ";
        i64 tk = 1;
        while (dif >= tk) {
            cout << i + tk << " ";
            dif -= tk;
            tk++;
            cnt++;
        }
    }
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}