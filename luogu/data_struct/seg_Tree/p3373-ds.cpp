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

const int N = 1e5 + 10;
i64 seg[4 * N], lazy_add[4 * N], lazy_mul[4 * N];
i64 mod;
vector<i64> a;

void push_down(i64 p, i64 s, i64 t) {
    if (lazy_mul[p] == 1 && lazy_add[p] == 0) return;
    i64 mid = s + ((t - s) >> 1);
    i64 len1 = mid - s + 1, len2 = t - mid;

    // 更新左子树
    seg[p*2] = (seg[p*2] * lazy_mul[p] % mod + lazy_add[p] * len1 % mod) % mod;
    lazy_mul[p*2] = (lazy_mul[p*2] * lazy_mul[p]) % mod;
    lazy_add[p*2] = (lazy_add[p*2] * lazy_mul[p] % mod + lazy_add[p]) % mod;

    // 更新右子树
    seg[p*2+1] = (seg[p*2+1] * lazy_mul[p] % mod + lazy_add[p] * len2 % mod) % mod;
    lazy_mul[p*2+1] = (lazy_mul[p*2+1] * lazy_mul[p]) % mod;
    lazy_add[p*2+1] = (lazy_add[p*2+1] * lazy_mul[p] % mod + lazy_add[p]) % mod;

    // 清空当前节点标记
    lazy_mul[p] = 1;
    lazy_add[p] = 0;
}

void build(i64 s, i64 t, i64 p) {
    lazy_add[p] = 0;
    lazy_mul[p] = 1;
    if (s == t) {
        seg[p] = a[s] % mod;
        return;
    }
    i64 mid = s + ((t - s) >> 1);
    build(s, mid, p * 2);
    build(mid + 1, t, p * 2 + 1);
    seg[p] = (seg[2 * p] + seg[2 * p + 1]) % mod;
}

void add(i64 l, i64 r, i64 s, i64 t, i64 x, i64 p) {
    if (l <= s && t <= r) {
        i64 len = (t - s + 1) % mod;
        seg[p] = (seg[p] + x * len) % mod;
        lazy_add[p] = (lazy_add[p] + x) % mod;
        return;
    }
    push_down(p, s, t);
    i64 mid = s + ((t - s) >> 1);
    if (l <= mid) add(l, r, s, mid, x, p * 2);
    if (r > mid) add(l, r, mid + 1, t, x, p * 2 + 1);
    seg[p] = (seg[p*2] + seg[p*2+1]) % mod;
}

void mul(i64 l, i64 r, i64 s, i64 t, i64 x, i64 p) {
    if (l <= s && t <= r) {
        seg[p] = (seg[p] * x) % mod;
        lazy_mul[p] = (lazy_mul[p] * x) % mod;
        lazy_add[p] = (lazy_add[p] * x) % mod; // 乘法操作影响加法标记
        return;
    }
    push_down(p, s, t);
    i64 mid = s + ((t - s) >> 1);
    if (l <= mid) mul(l, r, s, mid, x, p * 2);
    if (r > mid) mul(l, r, mid + 1, t, x, p * 2 + 1);
    seg[p] = (seg[p*2] + seg[p*2+1]) % mod;
}

i64 gsum(i64 l, i64 r, i64 s, i64 t, i64 p) {
    if (l <= s && t <= r) {
        return seg[p] % mod;
    }
    push_down(p, s, t);
    i64 mid = s + ((t - s) >> 1);
    i64 res = 0;
    if (l <= mid) res = (res + gsum(l, r, s, mid, p * 2)) % mod;
    if (r > mid) res = (res + gsum(l, r, mid + 1, t, p * 2 + 1)) % mod;
    return res % mod;
}

void solve() {
    i64 n, q;
    cin >> n >> q >> mod;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= mod;
    }
    build(1, n, 1);
    while (q--) {
        i64 op, x, y, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            mul(x, y, 1, n, k % mod, 1);
        } else if (op == 2) {
            cin >> x >> y >> k;
            add(x, y, 1, n, k % mod, 1);
        } else {
            cin >> x >> y;
            cout << gsum(x, y, 1, n, 1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // 初始化懒惰乘法标记为1
    for (int i = 0; i < 4 * N; i++) {
        lazy_mul[i] = 1;
    }
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}