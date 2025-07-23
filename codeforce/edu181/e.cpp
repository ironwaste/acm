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

// 2025.07.22——23:47:59
/*
 *
 *
 *
*/

const int N = 2e5 + 10;
i64 frac[N],fsum[N];
void init() {
    frac[0] = 1LL;
    for (int i = 1;i < N;i++) {
        frac[i] = frac[i - 1] * i % mod3;
        fsum[i] = (fsum[i-1] + i) % mod3;
    }
}
i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1) res = res * a % mod3;
        a = a * a % mod3;
        b >>= 1;
    }
    return res % mod3;
}

i64 inv(i64 x) {
    return pw(x, mod3 - 2LL);
}
i64 C(i64 n, i64 m) {
    return frac[n] * inv(frac[n - m]) % mod3 * inv(frac[m]) % mod3;
}

void solve() {
    i64 n, x;
    cin >> n >> x;
    if (n > x) {
        cout << 0LL << endl;
        return;
    }
    if (n == 1LL) {
        cout << x % mod3 << endl;
        return;
    }
    if (n <= 2) {
        cout << C(x, n) << endl;
        return;
    }
    i64 diff = x - n;
    i64 ans = 0;
    for (i64 i = 2;i <= diff;i += 2LL) {
        ans = (ans + fsum[i]) % mod3;
    }
    cout << ans << endl;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}