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

// 2025.09.13——23:25:40
/*
 *
 *
 *
*/

void solve() {
    i64 n, mxk = 0;;
    cin >> n;
    vector<vector<i64> >a(n);
    for (int i = 0;i < n;i++) {
        i64 k;
        cin >> k;
        mxk = max(k, mxk);
        a[i].push_back(k);
        for (int j = 0;j < k;j++) {
            i64 x;cin >> x;
            a[i].push_back(x);
        }
    }


    vector<i64>dp(mxk + 1, INT_MAX);
    for (int j = 1;j <= mxk;j++) {

        for (int i = 0;i < n;i++) {
            i64 k = a[i][0];
            if (k < j)continue;
            if (a[i][j - 1] != dp[j - 1]) {
                dp[j] = min(dp[])
            }
                dp[j + 1] =
        }
    }




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