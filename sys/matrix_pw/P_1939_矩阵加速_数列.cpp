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

using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/P1939
// 网址：
// 2025.11.10——14:28:30
/*
 * 矩阵快速幂 加速数列
 * 基本应用
 * 矩阵
 * 
 * i    ->  i + 1
 * i-1  ->  i
 * i-2  ->  i - 1
 *
 * f[i + 1] = f[i] + f[i - 2]
 * 1 0 1
 * 1 0 0
 * 0 1 0
 */

const i64 MXM = 110;
const i64 MXN = 110;

struct mat {
    i64 row, col;
    ull a[MXN][MXM];
    mat() { memset(a, 0, sizeof a); }
    void build() {
        i64 mi = min(this->col, this->row);
        for (int i = 1;i <= mi;i++) { this->a[i][i] = 1; }
    }
};
mat operator* (const mat x, const mat y) {
    mat res;
    i64 n, m, kk;
    res.row = n = x.row, res.col = m = y.col;
    kk = x.col;
    for (int k = 1;k <= kk;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                (res.a[i][j] += x.a[i][k] * y.a[k][j] % mod7) %= mod7;
            }
        }
    }

    return res;
}
void matass(mat& x, mat& y) {
    x.row = y.row, x.col = y.col;
}

void print(mat x) {
    int n, m;
    n = x.row, m = x.col;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cout << x.a[i][j] << " ";
        }cout << endl;
    }
    return;
}

mat pw(mat a, i64 b) {
    mat res;
    matass(res, a);
    res.build();
    while (b) {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


void solve() {
    i64 n;
    cin >> n;
    if (n <= 3) {
        cout << 1 << endl;
        return;
    }
    n -= 3;
    mat res;
    mat a;
    a.row = 3;
    a.col = 1;

    a.a[1][1] = 1;
    a.a[2][1] = 1;
    a.a[3][1] = 1;

    res.col = res.row = 3;
    res.a[1][1] = res.a[1][3] = res.a[2][1] = res.a[3][2] = 1;
    a = pw(res, n) * a;
    cout << a.a[1][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}