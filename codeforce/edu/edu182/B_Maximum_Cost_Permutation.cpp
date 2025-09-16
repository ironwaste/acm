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

// 2025.09.15——22:43:02
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n + 1), freq(n + 1, 0);
    i64 miv = LLONG_MAX, mxv = LLONG_MIN;
    i64 mi = INT_MAX, mx = INT_MIN;
    i64 cnt0 = 0, cnt = 0;
    vector<i64>idx;
    for (i64 i = 1;i <= n;i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (i64 i = 1;i <= n;i++) {
        if (freq[0] == 1 && freq[i] == 0 && a[i] == 0)continue;
        if (a[i] != i) {
            mi = min(i, mi);
            mx = max(mx, i);
        }
    }
    cout << max(mx - mi + 1LL, 0LL) << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}