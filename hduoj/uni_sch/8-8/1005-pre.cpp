#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdlib>
using namespace std;
#define endl '\n'
#define ll long long
#define mod1 998244353
#define mod2 1000000007
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define debug(x) cerr << #x <<" "<<x <<endl;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <const ll MOD>
struct ModInt{
    ll x;
    ModInt(ll n = 0){
        x = n % MOD;
        if (x < 0) x += MOD;
    }
    //快速幂
    ModInt<MOD> pw(ll k){
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
    ModInt<MOD> inv(){ return pw(MOD - 2); }
    // 算术运算符
    friend ModInt<MOD> operator+(ModInt<MOD> a,ModInt<MOD> b){
        return (a.x + b.x) % MOD;
    }
    friend ModInt<MOD> operator-(ModInt<MOD> a,ModInt<MOD> b){
        return (a.x + MOD - b.x) % MOD;
    }
    friend ModInt<MOD> operator*(ModInt<MOD> a,ModInt<MOD> b){
        return (a.x * b.x) % MOD;
    }
    // 修复2：正确的除法实现
    friend ModInt<MOD> operator/(ModInt<MOD> a,ModInt<MOD> b){
        return a * b.inv();  // 使用重载的乘法
    }
    // 比较运算符
    friend bool operator<=(ModInt<MOD> a, ModInt<MOD> b){ return a.x <= b.x; }
    friend bool operator<(ModInt<MOD> a, ModInt<MOD> b){ return a.x < b.x; }
    friend bool operator>=(ModInt<MOD> a, ModInt<MOD> b){ return a.x >= b.x; }
    friend bool operator>(ModInt<MOD> a, ModInt<MOD> b){ return a.x > b.x; }
    friend bool operator==(ModInt<MOD> a, ModInt<MOD> b){ return a.x == b.x; }
    // 流运算符
    friend ostream& operator<<(ostream& out,const ModInt<MOD>& a){
        return out << a.x;
    }
    friend istream& operator>>(istream& in,ModInt<MOD>& a){
        ll n;
        in >> n;
        a = ModInt<MOD>(n);  // 使用构造函数处理范围
        return in;
    }
    ModInt<MOD>& operator+=(const ModInt<MOD>& a){
        *this = *this + a;
        return *this;
    }
    ModInt<MOD>& operator-=(const ModInt<MOD>& a){
        *this = *this - a;
        return *this;
    }
    ModInt<MOD>& operator*=(const ModInt<MOD>& a){
        *this = *this * a;
        return *this;
    }
    ModInt<MOD>& operator/=(const ModInt<MOD>& a){
        *this = *this / a;
        return *this;
    }
};
using mint = ModInt<mod1>;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int a[20][30] = { 0 };
    // for(int i=0;i<20;i++){
    //     for(int j=0;j<30;j++){
    //         // if(a[i][j] == 0) cout << '.';
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }

    vector<array<int, 3> >kk(k);

    int tap = 1;
    int sek = k;
    while (k--) {
        // debug(k)
        int x, y;
        cin >> x >> y;
        x += 9;
        y += 9;
        kk[k][0] = x, kk[k][1] = y, kk[k][2] = tap;
        // a[x][y] = tap;
        // a[x-1][y] = tap;
        // for(int i=y-2;i<=y+2;i++)
        //     a[x-2][i] = tap;
        // for(int i=y-1;i<=y+1;i++)
        //     a[x-3][i] = tap;
        // a[x-4][y] = tap;
        tap++;
    }
    sort(all(kk));
    // for (auto [a, b, c] : kk) {
    //     de(a)de(b)debug(c);
    // }
    for (int i = 0;i < sek;i++) {
        tap = kk[i][2];
        int x = kk[i][0], y = kk[i][1];
        // de(x)debug(y);
        a[x][y] = tap;
        a[x - 1][y] = tap;
        for(int i=y-2;i<=y+2;i++)
            a[x-2][i] = tap;
        for(int i=y-1;i<=y+1;i++)
            a[x-3][i] = tap;
        a[x-4][y] = tap;
    }



    for(int i=10;i<n+10;i++){
        for(int j=10;j<m+10;j++){
            if(a[i][j] == 0) cout << '.';
            else cout << a[i][j];
        }
        cout << endl;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}