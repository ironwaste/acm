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

// 补题——题目链接: https://www.luogu.com.cn/problem/P1962
// 网址：
// 2025.11.10——15:41:34
/*
 * 矩阵快速幂 加速 fib纳妾数列
 * i     - >  i + 1
 * i - 1  - > i
 * 1 1
 * 1 0
*/

const i64 MXN = 5;
const i64 MXM = 5;

struct mat {
    i64 row, col;
    ull a[MXN][MXM];
    mat() { memset(a, 0, sizeof a); }
    void E() {
        i64 mi = min(this->col, this->row);
        for (int i = 1;i <= mi;i++) { a[i][i] = 1; }
    }
};
void matass(mat& a, mat& b) {
    a.row = b.row;
    a.col = b.col;
}
mat operator*(const mat x, const mat y) {
    i64 n, m, kk;
    mat res;
    res.row = n = x.row;
    res.col = m = y.col;
    kk = x.col;
    
    for (int k = 1;k <= kk;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                (res.a[i][j] += (x.a[i][k] * y.a[k][j]) % mod7) %= mod7;
            }
        }
    }
    return res;
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

    res.E();
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    i64 n;
    cin >> n;
    if (n <= 2) {
        cout << 1 << endl;
        return;
    }

    n -= 2;
    mat ans, res;
    ans.col = 1;
    ans.row = 2;
    ans.a[1][1] = ans.a[2][1] = 1;

    res.row = res.col = 2;
    res.a[1][1] = res.a[1][2] = res.a[2][1] = 1;

    ans = pw(res, n) * ans;

    cout << ans.a[1][1] << endl;
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