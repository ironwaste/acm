#include<bits/stdc++.h>
#include <cmath>
using namespace std;
#define endl '\n'
#define ll long long
#define mod1 998244353
#define mod2 1000000007
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

vector <int> gaoj(ll a,ll b){
    vector <int> lb(23,0);
    int tap = 0;
    while(a > 0){
        lb[tap] = a % 10;
        a /= 10;
        tap++;
    }
    for(int i=0;i<tap;i++){
        lb[i] = lb[i] * b;
        int vab = i;
        for(int i=0;i<22;i++){
            if(lb[i] > 9){
                lb[i+1] += lb[i]/10;
                lb[i] %= 10;
            }
        }
    }
    return lb;
}
int bijiao(vector <int> a,vector <int> b){
    for(int i=21;i>=0;i--){
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return 2;
    }
    return 0;
}
vector <pll> ysfj(ll n){
    vector <pll> vab;
    for(int i=2;i <= n / i;i++){
        int tap = 0;
        while(n % i == 0){
            n /= i;
            tap++;
        }
        if(tap > 0)
            vab.push_back({i,tap});
    }
    if(n > 1)
        vab.push_back({n,1});
    return vab;
}


void solve() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    vector <pll> fen_a = ysfj(a),fen_c = ysfj(c);
    mint res = 1;
    for (auto x : fen_a)
        for(auto y : fen_c){
            if(x.first == y.first){
                mint vab = x.first;
                int tap = bijiao(gaoj(b,x.second),gaoj(d,y.second));
                // int tap = cp(b,x.second,d,y.second);
                if(tap == 0 || tap == 1){
                    for(int i=0;i<y.second;i++)
                        res *= vab.pw(d);
                }
                else{
                    for(int i=0;i<x.second;i++)
                        res *= vab.pw(b);
                }
                break;
            }
        }
    cout << res << endl;
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
