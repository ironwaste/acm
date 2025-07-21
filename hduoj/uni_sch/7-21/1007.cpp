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

// 2025.07.21——16:01:30
/*
 *
 *
 *
*/
template <const i64 MOD>
struct ModInt {
    i64 x;
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
    friend ModInt<MOD> operator+(ModInt<MOD> a, ModInt<MOD> b) { return (a.x + b.x) % MOD; }
    friend ModInt<MOD> operator-(ModInt<MOD> a, ModInt<MOD> b) { return (a.x + MOD - b.x) % MOD; }
    friend ModInt<MOD> operator*(ModInt<MOD> a, ModInt<MOD> b) { return (a.x * b.x) % MOD; }
    friend ModInt<MOD> operator/(ModInt<MOD> a, ModInt<MOD> b) { return a * b.inv();  }
    friend bool operator<=(ModInt<MOD> a, ModInt<MOD> b) { return a.x <= b.x; }
    friend bool operator<(ModInt<MOD> a, ModInt<MOD> b) { return a.x < b.x; }
    friend bool operator>=(ModInt<MOD> a, ModInt<MOD> b) { return a.x >= b.x; }
    friend bool operator>(ModInt<MOD> a, ModInt<MOD> b) { return a.x > b.x; }
    friend bool operator==(ModInt<MOD> a, ModInt<MOD> b) { return a.x == b.x; }
    friend ostream& operator<<(ostream& out, const ModInt<MOD>& a) { return out << a.x; }
    friend istream& operator>>(istream& in, ModInt<MOD>& a) { i64 n;in >> n;a = ModInt<MOD>(n);  return in;}
    ModInt<MOD>& operator+=(const ModInt<MOD>& a) {*this = *this + a;return *this;}
    ModInt<MOD>& operator-=(const ModInt<MOD>& a) {*this = *this - a;return *this;}
    ModInt<MOD>& operator*=(const ModInt<MOD>& a) {*this = *this * a;return *this;}
    ModInt<MOD>& operator/=(const ModInt<MOD>& a) {*this = *this / a;return *this;}
};
using Mint = ModInt<1000000007>;
                 // 998244353
const int N = 5e3 + 400;
Mint frac[N];

void init() {
    frac[0] = 1;
    for (Mint i = 1;i < N;i++) {
        frac[i] = frac[i-1LL] * i;
    }
}

Mint C(i64 n,i64 m) {
    return frac[n] / frac[m] / frac[n - m];
}
void solve() {
    i64 n,r;
    cin >> n >> r;
    vector<i64>a(n);
    for (int i = 0;i < n;i ++) {
        cin >> a[i];
    }
    Mint ans = 0;
    vector<i64>bmi(n + 1,0);
    for (int i = n - 1;~i;i--) {
        bmi[i] = max(bmi[i + 1] + 1LL, a[i]);
    }
    i64 v = r - bmi[0];
    if (v < 0) {
        cout << 0LL << end;
        return;
    } else if (v == 0) {
        cout << 1LL << endl;
        return;
    }
    Mint ans = 1LL;
    i64 lim = min(v, n);
    for (int i = 1;i <= min(v, n);i++) {
        ans += C(n,i) * (Mint(1+n-i) *Mint(n-i))

        
    }





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