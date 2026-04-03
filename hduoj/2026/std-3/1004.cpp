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

// 2026.04.03——20:08:23
/*
 *
 *
 *
*/
const i64 N = 2e5 + 10;
i64 num[N];

void init() {
    for (i64 i = 1;i < N;i++) {
        for (i64 j = 2;j * i < N;j++) {
            num[i * j]++;
            // num[i]++;
        }
    }
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>a;
    for (i64 i = 1;i <= n;i++) {
        i64 cv = max(0LL, (n / i) - 1LL);
        i64 v = num[i] + cv;
        a.push_back(v);
        // de(i)deb(v)
    }
    // 1 2
    // 1 3
    // 1 4
    // 2 4

    // 1 -> 3
    // 2 -> 2
    // 3 -> 1
    // 4 -> 2 
    sort(all(a));
    cout << a[n - k] << endl;
    // for (auto x : a) {
    //     de(x)
    // }
    // cout << endl;
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