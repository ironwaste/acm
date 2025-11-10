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

// 补题——题目链接: https://www.luogu.com.cn/problem/P3390
// 网址：
// 2025.11.10——14:04:15
// 2025.11.10——14:28:23
/*
 * 矩阵快速幂
 * 矩阵乘法是否写错 就是 * 号 写出 +
 * 快速幂 是否初始化 单位矩阵
 * 矩阵的行和 列 是否初始化
 *
 *
*/
const i64 MXN = 110;
const i64 MXM = 110;

struct mat {
    i64 row, col;
    ull a[MXN][MXM];
    mat() {
        memset(a, 0, sizeof a);
    }
    inline void build() {
        for (int i = 1;i <= min(this->row, this->col);i++) { a[i][i] = 1; }
    }
};
mat operator*(const mat& x, const mat& y) {
    mat z;

    int n, m, kk;
    kk = x.col;
    n = x.row, m = y.col;
    z.row = n, z.col = m;
    // k is 遍历
    // i 是 左矩阵的 行数
    // j 应该是 右矩阵的列数
    // 因为 左矩阵的列数 和 右矩阵的 
    // 行数应该在矩阵乘法的时候相同
    for (int k = 1;k <= kk;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                (z.a[i][j] += x.a[i][k] * y.a[k][j] % mod7) %= mod7;
            }
        }
    }
    return z;
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
    res.col = a.col;
    res.row = a.row;
    res.build();
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



void solve() {
    i64 n, k;
    cin >> n >> k;
    mat ak;
    ak.col = ak.row = n;
    // print(ak);

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> ak.a[i][j];
        }
    }
    // print(ak);

    mat ans = pw(ak, k);
    print(ans);
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