// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
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
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 2025.08.03——17:13:56
// 2025.08.03——18:45:07 wa
/* https://atcoder.jp/contests/abc417/tasks/abc417_d
 * 
 *
*/

void solve(){
    i64 n, tot = 0;
    cin >> n;
    vector<array<i64, 3> >pab(n);
    // 当这个时候 auto  && 才可以对于执行 vector<array<i64 ,3> >对于其中的值进行赋值
    // 而 auto [&&s,&& b,&&c] :  vec<arr>
    // 以及 auto& [&s,& b,&c] ： vec<arr>
    // 都是行不通的
    vector<i64> sum_B(n + 1, 0);
    for (auto&& [p, a, b] : pab) {
        cin >> p >> a >> b;
        tot += b;
    }
    for (int i = 1;i <= n;i++) {
        sum_B[i] = sum_B[i - 1] + pab[i-1][2];
    }
    i64 mx = 1010;
    vector<vector<i64> > dp(n + 1, vector<i64>(mx + 10, 0LL));
    for (int i = 0;i < mx + 10;i++) {
        dp[n][i] = i;
    }
    
    for (int i = n - 1;i >= 0;i--) {
        auto [p, a, b] = pab[i];
        de(i)de(p)de(a)deb(b);
        for (int j = 0;j < mx + 10;j++) {
            if (j <= p) {
                dp[i][j] = dp[i + 1][j + a];
            } else {
                dp[i][j] = dp[i + 1][max(0LL, j - b)];
            }
       }
    }
    i64 Q;
    cin >> Q;
    while (Q --) {
        i64 x;
        cin >> x;
        i64 pos = lower_bound(all(sum_B), x - 1000) - sum_B.begin();
        if (pos > n) {
            cout << x - tot << endl;
        } else {
            cout << dp[pos][x - sum_B[pos]] << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}