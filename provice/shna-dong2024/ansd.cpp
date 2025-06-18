// ?????? 24? ???

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

const ll INF = 0x7FFFFFFFFFFFFFFF;
const ll MOD = 998244353;
using namespace std;

template<const ll MOD>
struct ModInt{
    ll x;
    ModInt(ll n = 0){ x = n;}
    ModInt<MOD> qmi(ll k){
        ModInt<MOD> res = 1;
        ModInt a = *this;
        while (k){
            if (k&1) (res.x *= a.x) %= MOD;
            (a.x *= a.x) %= MOD;
            k /= 2;
        }
        return res;
    }
    ModInt<MOD> inv(){ ModInt<MOD> a = *this; return a.qmi(MOD-2);}
    ModInt<MOD> friend operator+(ModInt<MOD> a,ModInt<MOD> b){ return (a.x + b.x) % MOD;}
    ModInt<MOD> friend operator-(ModInt<MOD> a,ModInt<MOD> b){ return (a.x - b.x + MOD) % MOD;}
    ModInt<MOD> friend operator*(ModInt<MOD> a,ModInt<MOD> b){ return a.x % MOD * b.x % MOD;}
    ModInt<MOD> friend operator/(ModInt<MOD> a,ModInt<MOD> b){ return a * b.inv();}
    ModInt<MOD> friend operator<=(ModInt<MOD> a,ModInt<MOD> b){ return a.x <= b.x;}
    ModInt<MOD> friend operator<(ModInt<MOD> a,ModInt<MOD> b){ return a.x < b.x;}
    ModInt<MOD> friend operator>=(ModInt<MOD> a,ModInt<MOD> b){ return a.x >= b.x;}
    ModInt<MOD> friend operator>(ModInt<MOD> a,ModInt<MOD> b){ return a.x > b.x;}
    ModInt<MOD> friend operator==(ModInt<MOD> a,ModInt<MOD> b){ return a.x == b.x;}
    friend std::ostream& operator<< (std::ostream& out,ModInt<MOD>& a){ return out << a.x;}
    friend std::istream& operator>> (std::istream& in, ModInt<MOD>& a){ return  in >> a.x;}
};

inline ll read(){
	ll x=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')flag=0;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	if(flag) return x;
	return ~(x-1);
}

void solve() {
	__int128 p = read(), a = read(), b = read();
	__int128 q = read(), c = read(), d = read();
	ull m = read(), t = read();
	__int128 now = 0;
	__int128 x = m / p;
	if (m < p) {
		cout << m << endl;
		return;
	}
	while (1) {
//		cout << x << " " << m << " " << now << endl;
		__int128 shang = p * (x + 1) - m;
		if (shang <= 0) {
			x = m / p;
			continue;
		}
		__int128 xia = x * (q - p);
		__int128 duoshao = shang / xia + (shang % xia ? 1 : 0);
		if (now + duoshao * (x * (a + c) + b + d) > t) break;
		now += duoshao * (x * (a + c) + b + d);
		m += duoshao * (q - p) * x;
		x++;
	}
	__int128 shengyu = t - now; 
	if (shengyu <= 0) {
		cout << m << endl;
		return;
	}
	ll l = 0; ll r = 1e18; 
	ll ans = 1e18; 
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (mid * (a + c) + (mid / x + (mid % x ? 1 : 0)) * (b + d)> shengyu) {
			r = mid - 1;
			ans = mid;
		} 
		else { 
			l = mid + 1;
		}
	}
	cout << (ll)(ans - 1) * (ll)(q - p) + (ll)m << endl;
	return;
}

int main() {
	__int128 T;
	T = read();
	while (T--) {
		solve();
	}
	return 0;
}