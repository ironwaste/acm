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


// 补题——题目链接:https://acm.hdu.edu.cn/contest/problem?cid=1177&pid=1008
// 网址：
// 2025.08.06——11:22:19
// 2025.08.06——13:03:35 accpted
/* 
 * 总结 ： 一个是 状压情况下 所有数组情况的总数量 
 *
 *
*/
const int N = 1e5 + 10;
i64 lgg[N];
i64 lowbit(i64 x) {
    return x & (-x);
}
void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<vector<i64>>a(n, vector<i64>(m, 0));
    k = min(m, k);
    i64 vm = (1LL << m);
    // deb(vm);
    vector<i64>val(vm + 10, 0);
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
        // j & (j - 1) 可以将最后一位1 消去
        // 那么如何取其 缺少的那一位 取log
        vector<i64>bitval(vm + 10LL, 0);
        for (int j = 1;j < vm;j++) {
            i64 t = j & (j - 1LL);
            bitval[j] = bitval[t] + a[i][lgg[j - t]];
            val[j] = max(val[j], bitval[j]);
        }
    }
    // cout << val[13] << endl;
    // de(val[2])deb(val[13]);
    vector<vector<i64> >dp(k + 1, vector<i64>(vm + 10LL, 0));
    for (int i = 0;i < vm;i++) {
        dp[0][i] = val[i];
    }

    for (int i = 1;i < k;i++) {
        // 如何将集合拆分后 再进行 合并呢? 
        for (int j = 1;j < vm;j++) {
            // 有多种方式 假设设为 j 是最终合并 的解 那么 j ^ t 
            // for (int i = 0; i < 1 << m; i++) {
            //     for (int j = i; j; j = (j - 1) & i)
            //         dp[p][i] = max(dp[p][i], dp[p - 1][j] + mx[i ^ j]);
            //     dp[p][i] = max(dp[p][i], dp[p - 1][0] + mx[i]);
            // }

            for (int t = 1;t < vm;t++) {
                // de(t)de(j)deb((t & j));
                if ((t & j) == 0) {
                    dp[i][t + j] = max(dp[i][t + j], dp[i - 1][t] + val[j]);
                    // dp[i][t + j] = max(dp[i][t + j], dp[i - 1][j] + val[t]);
                }
            }
        }
    }
    cout << dp[k - 1LL][vm - 1LL] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2;i < N;i++) {
        lgg[i] = lgg[i / 2] + 1LL;
    }
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}