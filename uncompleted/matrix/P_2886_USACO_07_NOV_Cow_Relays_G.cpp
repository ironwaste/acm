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


using pii = pair<int, int>;
using pll = pair<i64, i64>;
const i64 MXN = 110;
// 补题——题目链接: https://www.luogu.com.cn/problem/P2886
// 网址： https://www.luogu.com/article/hr6lem5m
// 2025.11.11——22:25:27
// 2025.11.11——23:46:06
/*
 * 和 图结合 的相关的矩阵快速幂
 *
*/

struct mat {
    i64 row, col;
    i64 marix[MXN][MXN];
    // marix
    mat() { memset(marix, 0x3f, sizeof marix); }
    void E(int n) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                this->marix[i][j] = 1;
            }
        }
    }

    i64* operator[](int i) {
        return marix[i];
        //这样可以 不使用成员运算符或者.号
    }
    const i64* operator[](int i) const {
        return marix[i];
    }
};
mat operator*(const mat& a, const mat& b) {
    i64 n, m, kk;
    mat res;
    n = res.row = a.row;
    m = res.col = b.col;
    kk = a.col;
    for (int k = 1;k <= kk;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                res[i][j] = min(res[i][j],
                    a[i][k] + b[k][j]);
            }
        }
    }
    return res;
}

mat mpw(mat a, i64 b) {
    mat res = a;
    // res.row = res.col = a.row;
    // for (int i = 1; i <= res.row; i++) {
    //     res[i][i] = 0;
    // }
    b--;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, t, s, ed;
    cin >> n >> t >> s >> ed;
    i64 cnt = 0;
    mat e;
    map<i64, i64>mp;
    for (int i = 0;i < t;i++) {
        i64 u, v, d;
        cin >> d >> u >> v ;
        if (!mp.count(u)) { mp[u] = ++cnt; }
        if (!mp.count(v)) { mp[v] = ++cnt; }
        u = mp[u], v = mp[v];
        e[u][v] = e[v][u] = min(d, e[v][u]);
    }
    e.row = e.col = cnt;
    s = mp[s];
    ed = mp[ed];
    mat ans = e;
    ans = mpw(e, n);

    cout << ans[s][ed] << endl;
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