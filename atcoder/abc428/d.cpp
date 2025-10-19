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

// 补题——题目链接: https://atcoder.jp/contests/abc428/tasks/abc428_d
// 网址：
// 2025.10.19——12:21:51
/*
 * 末尾只能是 0 1 4 5 6 9
 *
 *  c * 10 ^ log(c + d) + c + d
 *  只可能存在 8 * n + 1  或者 8 * n + 4 的两种情况
 *  奇数 为 8 * n  + 1;
 *  偶数 为 8 * n  + 4;
 *  cc + d
 * 不该这样算
 *
 * 应该就是预处理 + 分块 二分
 *
 *
 */
i64 sz;
const i64 N = 2e16 + 5e10;
vector<vector<i64>>f;
void init() {
    for (i64 i = 1;i < N / i;i++) {
        vector<i64>b;
        for (i64 j = 0;j < 1e6&& i < N / i;i++,j++) {
            b.push_back(i * i);
        }
        f.push_back(b);
    }
    sz = f.size();
}

void solve() {
    i64 c, d, cc;
    cin >> c >> d;
    i64 ansc = c;
    cc = c;
    while (cc) {
        ansc *= 10LL;
        cc /= 10;
    }
    ansc += c;
    deb(ansc);
    i64 ans = 0;
    for (i64 i = 0;i < sz;i ++) {
        if (f[i].back() > ansc && f[i][0] <= ansc+d) {
            i64 tmp = upper_bound(all(f[i]), ansc + d) - upper_bound(all(f[i]), ansc);
            auto it = upper_bound(all(f[i]), ansc);
            i64 cnt = 0;
            while (cnt < tmp) {
                de(*it);
                it ++ ;
                cnt++;
            }
            
            deb(tmp);
            ans += tmp;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}