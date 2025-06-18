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


void solve(){
    i64 h1, m1, h2, m2, n;
    char ch;
    cin >> h1 >> ch >> m1 >> h2 >> ch >> m2 >> n;
    int time = h2 * 60 + m2 - h1 * 60 - m1;

    vector<i64>t(n), c(n), p(n);
    for (int i = 0;i < n;i ++) {
        cin >> t[i] >> c[i] >> p[i];
    }

    vector<i64>dp(time + 10, LLONG_MIN);
    dp[0] = 0;
    for (int i = 0;i < n;i++) {
        i64 ti = t[i], ci = c[i], pi = p[i];
        if (!pi) {
            for (int j = 0;j <= time && j + ti <= time;j ++) {
                dp[j + ti] = max(dp[j + ti], dp[j] + ci);
                // de(i)de(j + ti)deb(dp[j + ti])
            }
        } else {
            for(int j = time;~j;j --) {
                for (int k = 1;k <= pi && j - k*ti >= 0;k ++) {
                    dp[j] = max(dp[j], dp[j - k * ti] + k * ci);
                    // de(i)de(j)de(j-k*ti)de(dp[j - k * ti])deb(dp[j])
                }
            }
        }
        
    }
    // for (int i = 0;i <= time;i ++) {
    //     cout << "i : "<<i << "   value: "<<dp[i] << endl;
    // }

    
    cout << dp[time] << endl;


    
}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}