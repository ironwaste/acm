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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using i128 = __int128_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
using ull = unsigned long long;
ull M;
// 补题——题目链接: https://www.luogu.com.cn/problem/P2044
// 网址：
// 2025.11.10——16:42:24
/*
 *
 * X{n+1} = (a * X{n} + c) % m
 * xn  ->  a * xn + c
 * c   - > c
 * a 1
 * 0 1
 *
 * 在直接矩阵乘法的情况下 会导致 最终结果 爆 long long 的状态
 *
*/
struct mat {
    i64 col, row;
    i128 a[3][3];
    mat() { memset(a, 0, sizeof a); }
    void E() {
        i64 mi = min(this->col, this->row);
        for (int i = 1;i <= mi;i ++) {
            a[i][i] = 1;
        }
    }
};

mat operator*(const mat& x, const mat& y) {
    i64 n, m, kk;
    mat res;
    n = res.row = x.row;
    m = res.col = y.col;
    kk = x.col;
    for (int k = 1;k <= kk;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                (res.a[i][j] += x.a[i][k] * y.a[k][j] % M) %= M;
            }
        }
    }
    return res;
}
// 或者在 矩阵乘法中换成 按照二进制位 类似于快速幂的方式进行乘法
ll Wuguidechengfa(ll x, ll y) {
	ll ans=0;
	while(y)
	{
		if(y&1) (ans+=x)%=mod;
		(x+=x)%=mod;
		y>>=1;
	}
	return ans;
}

mat pw(mat a, i64 b) {
    mat res;
    res.row = a.row;
    res.col = a.col;
    res.E();

    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    ull a, c, x0, n, g;
    cin >> M >> a >> c >> x0 >> n >> g;

    mat x;
    x.row = 2;
    x.col = 1;
    x.a[1][1] = x0;
    x.a[2][1] = c;
    mat res;
    res.row = res.col = 2;
    res.a[1][2] = res.a[2][2] = 1;
    res.a[1][1] = a;

    res = pw(res, n) * x;
    cout << (ull)(res.a[1][1]) % g << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}