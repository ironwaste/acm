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

using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 2025.08.07——14:51:49
/*
 *
 *
 *
*/

int pw(int a,int b) {
    int res = 1;
    while(b){
        if (b & 1) res = a * res;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n,U = (1LL<<30LL) - 1LL;
    cin >> n;
    vector<int>f(4 * n + 10, 0);
    // auto g = f, h = f;
    i64 g = 0, h = 0;
    cin >> f[0] >> f[1] >> f[2];
    f[0] = f[0] & U;
    f[1] = f[1] & U;
    f[2] = f[2] & U;
    for (int i = 0;i < 4 * n;i++) {
        int fi = i + 3;
        g = f[fi - 3] ^ ((f[fi - 3] * pw(2, 16)) & U);
        h = g ^ (g / pw(2,5));
        f[fi] = h ^ ((h * 2) & U) ^ f[fi - 2] ^ f[fi - 1];
        de(i)de(fi)deb(f[fi]);
    }
    int pre = 0;
    // for (int i = 0;i <= n-1;i++) {
    //     int fi = f[(i + 3)] % (n - i);
    //     if (fi) { pre = 1 - pre; }
    // }

    // // cout << pre;
    // // de(pre)
    // for (int i = 1;i < n;i++) {
    //     int fi = n + i * 3 + 3;
    //     int l = min(f[fi - 3] % n, f[fi - 2] % n);
    //     int r = max(f[fi - 3] % n, f[fi - 2] % n);
    //     int d = f[fi - 1] % n + 1;

    //     int len = r - l + 1;
    //     de(d)de(l)de(r)de(len)
    //     d = d % len;
    //     deb(d);
    //     if (d == 0) { cout << pre;continue; }
    //     int len1 = d % 2, len2 = (len - d) % 2;
    //     if (len1 * len2 % 2 == 0) {
    //         // pre = 1 - pre;
    //         // cout << pre;
    //         // de(pre);
    //     } else {
    //         // pre = 1 - pre;
    //         // cout << pre;
    //         // de(pre)
    //     }
    // }
    // cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}