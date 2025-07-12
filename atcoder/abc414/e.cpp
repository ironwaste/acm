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
// const i64 MOD = 998244353;
// #define MOD 
using pii = pair<int,int>;
using pll = pair<i64, i64>;

template<const i64 MOD>
struct ModInt {
    i64 x;
    ModInt(i64 n = 0) { x = n % MOD; }
    ModInt<MOD> qmi(i64 k) {
        ModInt<MOD>res = 1;
        ModInt a = *this;
        while (k) {
            if (k & 1) (res.x *= a.x) %= MOD;
            (a.x *= a.x) %= MOD;
            k /= 2;
        }
        return res;
    }

    ModInt<MOD> inv() { ModInt<MOD> a = *this; return a.qmi(MOD - 2); }
    ModInt<MOD> friend operator+(ModInt<MOD> a, ModInt<MOD> b) { return (a.x + b.x) % MOD; }
    ModInt<MOD> friend operator-(ModInt<MOD> a, ModInt<MOD> b) { return (a.x + MOD - b.x) % MOD; }
    ModInt<MOD> friend operator*(ModInt<MOD> a, ModInt<MOD> b) { return (a.x * b.x) % MOD; }
    ModInt<MOD> friend operator/(ModInt<MOD> a, ModInt<MOD> b) { return (a.x * b.inv()) % MOD; }
    ModInt<MOD> friend operator<=(ModInt<MOD> a, ModInt<MOD> b) { return a.x <= b.x; }
    ModInt<MOD> friend operator< (ModInt<MOD> a, ModInt<MOD> b) { return a.x < b.x; }
    ModInt<MOD> friend operator>=(ModInt<MOD> a, ModInt<MOD> b) { return a.x >= b.x; }
    ModInt<MOD> friend operator> (ModInt<MOD> a, ModInt<MOD> b) { return a.x > b.x; }
    ModInt<MOD> friend operator==(ModInt<MOD> a, ModInt<MOD> b) { return a.x == b.x; }
    friend ostream& operator<< (ostream& out, ModInt<MOD>& a) { return out << a.x; }
    friend istream& operator>> (istream& in, ModInt<MOD>& a) { return  in >> a.x; }
    ModInt<MOD> operator+= (const ModInt<MOD>& a) { return *this = x + a; }
    ModInt<MOD> operator-= (const ModInt<MOD>& a) { return *this = x - a; }
    ModInt<MOD> operator*= (const ModInt<MOD>& a) { return *this = x * a; }
    ModInt<MOD> operator/= (const ModInt<MOD>& a) { return *this = x / a; }

};
using Mint = ModInt<998244353>;

// 2025.07.12——21:18:27
/*  性质 a，b，c都小于N
 * 且a,b,c都不相同
 * 且a % b == c;
 * 确定b 相当于间接确定了c,
 * 0 <= c < b
 * 且 N >= a > b;
 * 遍历一次 b 有 1e12
 *
 * 进行分块 通过 a = k*b + c
 * 根据 k 的 值 来进行分块，从 k 的1 开始
 * b = 1 有 n个
 * b = 2 c 有 0，1,a
 * 总共有 N - b 种类
 * 如果选择的值 在于 0 ~ N的话，c 不能取0则代表其不能整除，
 * 也就是会少 N / b 下取整个数字
 * 
 * 有 N - b - (N / b - 1(不包含自己)) 种
 * N + 1 - (b - N/b)
 * sum N （2<=b <= N-1）
 * */

// i64 pw(i64 a, i64 b) {
//     i64 res = 1LL;
//     while (b) {
//         if (b & 1)res = res * a % mod3;
//         a = a * a % mod3;
//         b >>= 1LL;
//     }
//     return res % mod3;
// }

// i64 inv(i64 a) {
//     return pw(a, mod7 - 2) % mod3;
// }

void solve() {
    i64 N;
    cin >> N;
    // 那么就可以进行分块根据 N/b个数的不同

    Mint ans = Mint(N) * (1LL + N) / Mint(2LL);

    i64 i = 1LL;
    while (i <= N) {
        i64 now = N / i;
        // 关键 以判断下一部分的下限
        // 在这里是下取整，所以在反过来的下取整种就会得到一个上取整
        i64 r = min(N, N / now);
        ans -= Mint(r - i + 1LL) * now;
        i = r + 1;
    }
    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}