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
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto& x : a) { cin >> x; }

    vector<int>dp(3, 0);

    for (int i = 0;i < n;i++) {
        if (a[i] == 1) {
            (dp[0] += 1) %= mod3;
        } else if (a[i] == 2) {
            (dp[1] += (dp[0] + dp[1]) % mod3) %= mod3;
        } else if(a[i] == 3){
            (dp[2] += dp[1]) %= mod3;
        }
    }
    cout << dp[2] << endl;
    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}