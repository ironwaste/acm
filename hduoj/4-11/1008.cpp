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
const i64 N = 1e6 + 10;
i64 frac[N];

void init() {
    frac[0] = 1;
    for (i64 i = 1;i < N;i++) {
        frac[i] = frac[i - 1] * i % mod7;
    }
}
i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1) res = res * a % mod7;
        a = a * a % mod7;
        b >>= 1;
    }
    return res % mod7;
}
i64 inv(i64 a) {
    return pw(a, mod7 - 2);
}
i64 C(i64 n, i64 m) {
    return frac[m] * inv(frac[m - n]) % mod7 * inv(frac[n]) % mod7;
}

i64 FF(i64 n) {
    if (n == 1LL | n == 2LL)return 1LL;
    i64 res = 1LL;
    for (i64 i = 2;i <= n;i ++) {
        (res *= C(2LL,i)) %= mod7;
    }
    // i64 res = frac[n] * inv(2LL);
    return res % mod7;
}

void solve() {
    int n;
    cin >> n;
    vector<i64>a(n);
    map<i64, i64>cnt;
    for (auto& x : a) { cin >> x;cnt[x]++; }
    sort(all(a));

    i64 kind = 1LL, mx = 0LL, tmp = a[n - 1];
    i64 mxid = tmp;

    for (int i = n - 2;~i;i--) {
        mx = (mx + (tmp * a[i]) % mod7) % mod7;
        (tmp += a[i]) %= mod7;
    }

    // (kind *= FF(cnt[mxid])) %= mod7;
    for (int i = 2;i <= n;i ++) {
        (kind *= C(2, i))%= mod7;
    }

    // (kind *= FF(cnt.size())) %= mod7;
    cout << mx << " " << kind << endl;
    // 9 + (6*3) + (2*9) + (2 *11)
    // 27 + 18 = 45 + 22
    // 67

    // 2 + 2 
    // 3 3 1
    // 4 + 3 = 7
    // 4 3
    // 12 
    // 4 + 4 + 5 + 6

    // 2 2 2 3 3 
    // 5 5 2 (6 + 6)
    // 7 2 (12 + 10 )
    // 9 (12 + 14)

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