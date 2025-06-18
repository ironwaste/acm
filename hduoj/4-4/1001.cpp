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


void solve(){
    i64 n, m, v;
    cin >> n >> m >> v;
    vector<i64>g(n);
    for (auto& x : g) { cin >> x; }

    vector<vector<i64> >dp(m + 10,vector<i64>(v + 10 , 0));
    dp[0][0] = 1;
    for (int i = 0;i < n;i ++) { // 
        i64 gv = g[i];
        for (int j = m-1;~j ;j --) { // m
            for (int k = v;~k;k--) {// v
                i64 cnt = 1LL;
                if (dp[j][k]) {
                    while (cnt + j <= m && cnt *gv+k <= v) {
                        (dp[j + cnt][cnt * gv + k] += dp[j][k]) %= mod7;
                        cnt++;
                    }
                }
            }
        }
        
    }
    i64 ans = 0;
    for (int i = 0;i <= v;i++) {
        // de(m)de(i)deb(dp[m][i])
        (ans += dp[m][i]) %= mod7;
    }
    cout << ans << endl;

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}