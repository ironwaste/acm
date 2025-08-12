#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <numeric>
using namespace std;
#define endl '\n'
#define ll long long
#define mod1 998244353
#define mod2 1000000007
#define de(x) cerr << #x <<" "<<x <<" ";
#define debug(x) cerr << #x <<" "<<x <<endl;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <const ll MOD>
struct ModInt {
    ll x;
    ModInt(ll n = 0) {
        x = n % MOD;
        if (x < 0) x += MOD;
    }
    //快速幂
    ModInt<MOD> pw(ll k) {
        ModInt<MOD> res = 1;
        ModInt a = *this;
        while (k) {
            if (k & 1) res *= a;
            a *= a;
            k /= 2;
        }
        return res;
    }
    //逆元
    ModInt<MOD> inv() { return pw(MOD - 2); }
    // 算术运算符
    friend ModInt<MOD> operator+(ModInt<MOD> a, ModInt<MOD> b) {
        return (a.x + b.x) % MOD;
    }
    friend ModInt<MOD> operator-(ModInt<MOD> a, ModInt<MOD> b) {
        return (a.x + MOD - b.x) % MOD;
    }
    friend ModInt<MOD> operator*(ModInt<MOD> a, ModInt<MOD> b) {
        return (a.x * b.x) % MOD;
    }
    // 修复2：正确的除法实现
    friend ModInt<MOD> operator/(ModInt<MOD> a, ModInt<MOD> b) {
        return a * b.inv();  // 使用重载的乘法
    }
    // 比较运算符
    friend bool operator<=(ModInt<MOD> a, ModInt<MOD> b) { return a.x <= b.x; }
    friend bool operator<(ModInt<MOD> a, ModInt<MOD> b) { return a.x < b.x; }
    friend bool operator>=(ModInt<MOD> a, ModInt<MOD> b) { return a.x >= b.x; }
    friend bool operator>(ModInt<MOD> a, ModInt<MOD> b) { return a.x > b.x; }
    friend bool operator==(ModInt<MOD> a, ModInt<MOD> b) { return a.x == b.x; }
    // 流运算符
    friend ostream& operator<<(ostream& out, const ModInt<MOD>& a) {
        return out << a.x;
    }
    friend istream& operator>>(istream& in, ModInt<MOD>& a) {
        ll n;
        in >> n;
        a = ModInt<MOD>(n);  // 使用构造函数处理范围
        return in;
    }
    ModInt<MOD>& operator+=(const ModInt<MOD>& a) {
        *this = *this + a;
        return *this;
    }
    ModInt<MOD>& operator-=(const ModInt<MOD>& a) {
        *this = *this - a;
        return *this;
    }
    ModInt<MOD>& operator*=(const ModInt<MOD>& a) {
        *this = *this * a;
        return *this;
    }
    ModInt<MOD>& operator/=(const ModInt<MOD>& a) {
        *this = *this / a;
        return *this;
    }
};
using mint = ModInt<mod1>;

ll xiao(ll a, ll b, ll c, ll d) {
    return min(min(a, b), min(c, d));
}
void solve() {
    ll a1, b1, a2, b2, a3, b3, a4, b4;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;
    if (a1 == a3 && b1 == b3 && a2 == a4 && b2 == b4) {
        cout << 0 << endl;
        return;
    }
    int hs1, hs2;
    if (a1 == a2) hs1 = 1;
    else if (b1 == b2) hs1 = 0;
    if (a3 == a4) hs2 = 1;
    else if (b3 == b4) hs2 = 0;
    ll x = xiao(llabs(a3 - a1), llabs(a3 - a2), llabs(a4 - a1), llabs(a4 - a2));
    ll y = xiao(llabs(b3 - b1), llabs(b3 - b2), llabs(b4 - b1), llabs(b4 - b2));
    ll cha = min(x, y);
    ll res = 0;
    de(x)debug(y)
    res += cha * 2;
    x -= cha;
    y -= cha;
    res += x * 2;
    res += y * 2;
    if (hs1 != hs2) res++;
    else res += 2;
    cout << res << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
