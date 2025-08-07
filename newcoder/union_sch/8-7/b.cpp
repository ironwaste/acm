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
// 2025.08.07——16:56:22 accpted
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
    i64 f0 ,f1, f2, f3 = 0,a,b,c;
    // auto g = f, h = f;
    i64 g = 0, h = 0;
    cin >> f0 >> f1 >> f2;
    a = f0 = f0 & U;
    b = f1 = f1 & U;
    c = f2 = f2 & U;
    // for (int i = 0;i < 4 * n;i++) {
    //     int fi = i + 3;
    //     g = f[fi - 3] ^ ((f[fi - 3] * pw(2, 16)) & U);
    //     h = g ^ (g / pw(2,5));


    //     f[fi] = h ^ ((h * 2) & U) ^ f[fi - 2] ^ f[fi - 1];
    // }
    int pre = 0;
    for (int i = 0;i <= n-1;i++) {
        g = f0 ^ ((f0 * pw(2, 16)) & U);
        h = g ^ (g / pw(2, 5));
        f3 = h ^ ((h * 2) & U) ^ f1 ^ f2;
        int fi = f3 % (n - i);
        f0 = f1;
        f1 = f2;
        f2 = f3;
        if (fi) { pre = 1 - pre; }
    }
    // 这个时候 f3 为n - 1
    cout << pre;
    for (int i = n;i <= n + 3;i++) {
        g = f0 ^ ((f0 * pw(2, 16)) & U);
        h = g ^ (g / pw(2, 5));
        f3 = h ^ ((h * 2) & U) ^ f1 ^ f2;
        if (i == n + 3)break;
        f0 = f1;
        f1 = f2;
        f2 = f3;
    }
    // 要f3 = n + 3;
    // f2 = n + 2
    // f1 = n + 1;
    // f0 = n;
    // de(pre)
    for (int i = 1;i < n;i++) {
        int l = min(f0 % n, f1 % n);
        int r = max(f0 % n, f1 % n);
        int d = f2 % n + 1;
        int len = r - l + 1;
        d = d % len;
        if (d == 0) {
            cout << pre;
            for (int j = n + 3 * i + 1;j <= n + 3 * i + 3;j++) {
            f0 = f1;
            f1 = f2;
            f2 = f3;
            g = f0 ^ ((f0 * pw(2, 16)) & U);
            h = g ^ (g / pw(2, 5));
            f3 = h ^ ((h * 2) & U) ^ f1 ^ f2;
        }continue;
        }
        int len1 = d % 2, len2 = (len - d) % 2;
        if (len1 * len2 % 2 == 0) {
            cout << pre;
        } else {
            pre = 1 - pre;
            cout << pre;
        }
        for (int j = n + 3 * i + 1;j <= n + 3 * i + 3;j++) {
            f0 = f1;
            f1 = f2;
            f2 = f3;
            g = f0 ^ ((f0 * pw(2, 16)) & U);
            h = g ^ (g / pw(2, 5));
            f3 = h ^ ((h * 2) & U) ^ f1 ^ f2;
        }
        // de(f0)de(f1)de(f2)deb(f3);
    }
    cout << endl;
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