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

using pll = pair<i64, i64>;
// 补题——题目链接:
// 网址：
// 2025.08.13——17:34:04
/*
 * 顺序为 一开始 的最小值为 5时
 * 则 S将会变成 1 2 3 4 .....
 * 而后 变成 2 3 4
 * 1 3 4
 * 1 2 4
 * 1 2 3
 *
 * 2 4 7 11 21
 * x 2 
 * 0 1 4 
*/
const i64 N = 100;
i64 frac[N];
vector< i64 > dp(N, 0);
void init() {
    dp[0] = 1;
    frac[0] = 1;
    for (i64 i = 1;i < 40;i++) {
        dp[i] = i * frac[i - 1] % mod7;
        frac[i] = dp[i] * frac[i - 1] % mod7;
    }
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>s(n);
    for (auto& x : s) { cin >> x; }
    sort(all(s));

    auto dfs = [&](auto self,i64 bit, i64 jk)->i64 {
        i64 res = bit;
        if (jk == 0) {
            return 1LL;
        }
        jk--;
        i64 mi = min(bit, 32LL);

        for (i64 i = 1;i < mi;i++) {
            i64 subk = 1LL << (i - 1LL);
            if (jk > subk) {
                res = res * dp[i] % mod7;
                jk -= subk;
            } else {
                res = res * self(self, i, jk) % mod7;
                break;
            }
        }
        return res % mod7;
        };
    i64 ans = 1LL;
    for (int i = 0;i < n;i++) {
        i64 v = s[i];
        i64 ksub = (1LL << (v - 1LL));
        // de(v)deb(ksub);
        if (v <= 30LL && k >= ksub) {
            ans = ans * dp[v] % mod7;
            k -= ksub;
        } else {
            ans = ans * dfs(dfs, v, k) % mod7;
            k = 0;
            break;
        }
    }
    cout << ans % mod7 <<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    // for(int i = 0;i < 10;i++) {
    //     de(f[i].se);
    // }cout << endl;
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}