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

// 补题——题目链接: https://www.luogu.com.cn/problem/P2568
// 网址： 
// 2025.09.17——09:26:39
/*
 *
 *
 *
*/

const i64 N = 1e7 + 10;
i64 phi[N], pri[N], prx[N + 10];
vector<i64>p;
void init() {
    phi[1] = 1;
    for (i64 i = 2;i < N;i++) {
        if (!pri[i]) {
            p.push_back(i);
            phi[i] = i - 1;
        }
        for (auto x : p) {
            if (i * x >= N)break;
            pri[i * x] = 1;
            i64 gd = __gcd(i, x);
            phi[i * x] = phi[i] * phi[x] * gd / phi[gd];
            if (i % x == 0) {
                // phi[i * x] = phi[i] * x;
                break;
            }
        }
    }
    for (int i = 1;i <= N;i++) { prx[i] = prx[i - 1] + phi[i]; }
}
void solve() {
    i64 n;
    cin >> n;
    i64 ans = 0;
    for (auto x : p) {
        if (x > n)break;
        i64 l = 1, r = n / x;
        i64 v = prx[r] - prx[0];
        ans += v * 2LL - 1LL;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}