#include <bits/stdc++.h>
#include <climits>

#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define i64 long long
#define fi first
#define se second

#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define de(x) cerr << #x << " " << x << " ";
#define deb(x) cerr << #x << " " << x << endl;
using namespace std;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

template <const i64 MOD>
struct ModInt {
    i64 x;
    // 修复1：正确处理负数
    ModInt(i64 n = 0) {
        x = n % MOD;
        if (x < 0) x += MOD;
    }

    ModInt<MOD> qmi(i64 k) {
        ModInt<MOD> res = 1;
        ModInt a = *this;
        while (k) {
            if (k & 1) res *= a;
            a *= a;
            k /= 2;
        }
        return res;
    }

    ModInt<MOD> inv() { return qmi(MOD - 2); }

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
        i64 n;
        in >> n;
        a = ModInt<MOD>(n);  // 使用构造函数处理范围
        return in;
    }

    // 修复3：正确的复合赋值运算符（返回引用）
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
using Mint = ModInt<998244353>;

void solve() {
    i64 N;
    cin >> N;
    Mint ans = Mint(N) * Mint(1LL + N) / Mint(2LL);

    i64 i = 1LL;
    while (i <= N) {
        i64 now = N / i;
        i64 r = min(N, N / now);
        ans -= Mint(r - i + 1LL) * Mint(now);  // 显式转换
        i = r + 1;
    }
    cout << ans << endl;
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