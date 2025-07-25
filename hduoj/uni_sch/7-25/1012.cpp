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

// 2025.07.25——13:55:56
/*
 *
 *
 *
*/


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
using Mint = ModInt<mod7>;
using pll = pair<i64, i64>;



void solve() {
    i64 n;
    cin >> n;
    vector<pll>x_id(n+1), y_id(n+1);
    vector<i64>a(n+1);
    for (int i = 1;i <= n;i++) {
        i64 x, y;
        cin >> x >> y >> a[i];
        x_id[i].fi = (x + y), x_id[i].se = i;
        y_id[i].fi = (x - y), y_id[i].se = i;
    }
    
    sort(x_id.begin() + 1, x_id.end());
    sort(y_id.begin() + 1, y_id.end());
    Mint ans = 0;

    vector<Mint>sumx(n + 2,0) , sumy(n + 2,0);
    for (int i = 1;i <= n;i ++) {
        sumx[i] = (sumx[i - 1] + x_id[i].fi) ;
        sumy[i] = (sumy[i - 1] + y_id[i].fi);
    }

    for (int i = 1;i <= n;i++) {
        Mint now_x = x_id[i].fi, now_y = y_id[i].fi;
        i64 xid = x_id[i].se, yid = y_id[i].se;
        Mint precnt = i - 1, sufcnt = n - i;
        Mint prex = sumx[i - 1], sufx = sumx[n] - sumx[i];
        Mint prey = sumy[i - 1], sufy = sumy[n] - sumy[i];
        
        ans += a[xid] * ((precnt * now_x - prex) + (sufx - sufcnt * now_x));
        ans += a[yid] * ((precnt * now_y - prey) + (sufy - sufcnt * now_y));
        
    }
    ans /= Mint(2LL);
    cout << ans << endl;
}
/*
1
2
1 1 500
1 2 2000
*/

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