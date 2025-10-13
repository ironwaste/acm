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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://atcoder.jp/contests/abc427/tasks/abc427_d
// 网址：
// 2025.10.11——20:23:38
/*
 *
 *
 *
*/
// true -> alice
// false -> bob


i64 get(bool a) {
    if (a) { return 1; }
    return 0;
}

bool get(i64 a) {
    if (a == 1) { return true; }
    return false;
}
void solve() {
    i64 n, m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    // deb(s)
    // a/b 的选择点 , vertex , step
    vector<vector<i64>>g(n);
    vector<i64>du(n);
    for (int i = 0;i < m;i++) {
        i64 u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        du[u] ++;
    }
    vector<vector<i64> >dp(30, vector<i64>(n, -1));
    function<bool(bool, i64, i64)>dfs;
    dfs = [&](bool ab, i64 u, i64 step)->bool {
        if (dp[step][u] != -1) {
            return get(dp[step][u]);
        }
        if (step == 0) {
            dp[step][u] = (s[u] == 'A');
            return (s[u] == 'A');
        }
        if (du[u] == 1) {
            return dp[step][u] = dfs(!ab, g[u][0], step - 1);
        }

        bool a = false, b = false;
        // ab = true 为 a 
        // dfs  返回的bool 应该为最后的答案
        // true 也就是 alice 
        // false 为 bob
        // ab= false && dfs == false -> return false;
        // false -> true - > true
        // 只要在 ab为 false 的 情况下出现 false 则为false 
        // ab  true  dfs  true => true
        //               false => false
        for (auto v : g[u]) {
            if (dfs(!ab, v, step - 1)) {
                a = true;
                if (ab) { return dp[step][u]=true; }
            } else {
                b = true;
                if (!ab) { return dp[step][u]=false; }
            }
            // ok = ab & dfs(!ab, v, step - 1);
        }
        if (ab && a) {
            return dp[step][u]=true;
        } else if (!ab && b) {
            return dp[step][u]=false;
        } else if (a) {
            return dp[step][u]=true;
        } else {
            return dp[step][u]=false;
        }
        };

    cout << ((dfs(true, 0, 2 * k)) ? "Alice" : "Bob") << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}