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

// 2025.08.28——22:41:34
// 2025.08.28——22:55:28 wa 2 ??!!
// 2025.08.28——23:05:14 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<i64>ans(n, 0), idx0;
    i64 sum = 0;
    for (int i = 0;i < k;i++) {
        if (s[i] == '0') { idx0.push_back(i); }
        sum += (int) (s[i] - '0');
    }

    if (sum == k) {
        cout << "NO" << endl;
        return;
    }
    for (int j = 0, i = k;i < n;i++, j++) {
        if (s[i] == '0') { idx0.push_back(i); }
        sum -= (int) (s[j] - '0');
        sum += (int) (s[i] - '0');

        if (sum == k) {
            cout << "NO" << endl;
            return;
        }

    }

    i64 cnt = n;
    for (auto x : idx0) {
        ans[x] = cnt--;
    }
    for (int i = 0;i < n;i++) {
        if (!ans[i]) {
            ans[i] = cnt--;
        }
    }
    cout << "YES" << endl;
    for (int i = 0;i < n;i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return;

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