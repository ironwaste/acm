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
 *
 *
 *
*/
const int N = 2e5 + 10;
vector<i64>prx;


void init() {
    i64 cnt = 0;
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
    int idx = ptr - prx.begin() + 1;
    // int v = *ptr;

    while (idx + k - *ptr - 1 < 0) {
        ptr--;
        idx--;
    }
    for (int i = 1;i <= idx;i ++) {
        cout << i << " ";
    }

    for (int i = k + 1, cnt = 1;cnt <= n - idx;cnt ++,i += k) {
        cout << i << " ";
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