// ?????? 24? ???

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define i64 long long
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
	i64 n, m;
	cin >> n >> m;
	vector<i64>a(2 * n + 1);
	for (int i = 1;i <= 2 * n;i++) {
		cin >> a[i];
		a[i+n] = a[i];
	}
	i64 ans = 0;
	for (int i = 1;i <= n;i ++) {
		if (a[i] == 0) {
			i64 cnt0 = 1;
			while (a[i + 1] == 0 && i <= n) {
				i++;
				cnt0++;
			}
			i64 mi = 0;
			for (int j = i;j <= i + n;j++) {
				if (mi + 1 <= a[j]) {
					mi = max(mi,a[j]);
				} else {
					break;
				}
			}
			if (mi == m - 1) { ans += cnt0; }

		}
	}
	cout << ans << endl;

}

int main() {
	// __int128 T;
	// T = read();
	// std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
     
    int n, m;
    std::cin >> n >> m;
 
    std::vector<int> a(n);
    for (auto &x: a) {
        std::cin >> x;
    }
    a.insert(a.end(), a.begin(), a.end());
 
    std::vector<int> pos(m);
    std::iota(pos.rbegin(), pos.rend(), 2 * n);
 
    int ans = 0;
    for (int i = 2 * n - 2, cnt = m - 1; i >= 0; i--) {
        int v = a[i];
        if (v > 0 and pos[v - 1] < pos[v]) {
            cnt++;
        }
        if (v + 1 < m and pos[v] > pos[v + 1]) {
            cnt--;
        }
        if (i < n and cnt == 0) {
            ans++;
        }
        pos[v] = i;
    }
    std::cout << ans << "\n";
     
	// int T = 1;
	// while (T--) {
	// 	solve();
	// }
	return 0;
}