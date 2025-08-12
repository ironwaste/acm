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

// 2025.08.12——14:52:57
/*
 *
 *
 *
*/
const int N = 20;
i64 a[N][N], b[N][N];
void solve() {
    int n;
    cin >> n;
    for (int i = n;i>=1;i--) {
        for (int j = i;j <= n;j++) {
            cin >> a[i][j];
            if (i == 1) {
                b[i][j] = a[i][j];
            }
        }
    }
    for (int i = 2;i <= n;i ++) {
        for (int j = i;j <= n;j ++) {
            b[i][j] = max(b[i][j], a[i][j] + b[i - 1][j - 1]);
            b[i][j] = max(b[i][j], a[i][j] + b[i - 1][j]);
        }
    }

    cout << b[n][n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}