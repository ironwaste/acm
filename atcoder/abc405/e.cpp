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

const i64 N = 4e6 + 10;
i64 frac[N];
i64 pw(i64 a,i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod3;
        a = a * a % mod3;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 a) {
    return pw(a, mod3 - 2LL) % mod3;
}
void init() {
    // i64 res = 1LL;
    frac[0] = 1;
    for (i64 i = 1;i < N;i++) {
        frac[i] = frac[i - 1] * i % mod3;
    }
}
i64 CC(i64 n, i64 m) {
    return (frac[n]) * inv(frac[n - m]) % mod3 * inv(frac[m]) % mod3;
}
void solve() {
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    i64 sum = 0;
    for (i64 i = 0;i <= c;i ++) {
        (sum += CC(a+ b + i ,b) * CC(d-1+c-i,c-i) % mod3) %= mod3;
    }
    cout << sum << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    init();
    while (T--) {
        solve();
    }
    return 0;
}