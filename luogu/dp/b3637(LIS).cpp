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
    for (int i = 0;i < n;i++) { cin >> a[i]; }
    int mx = 0;
    vector<int>dp(n + 1, 0), num;
    for (int i = 0;i < n;i ++) {
        if (num.size() == 0) {
            num.pb(a[i]);
            dp[i] = 1;
        } else if (num.back() < a[i]) {
            num.pb(a[i]);
            dp[i] = num.size();
        } else {
            int id = lower_bound(all(num), a[i]) - num.begin();
            num[id] = a[i];
            dp[i] = id;
        }
        mx = max(mx, dp[i]);
    }

    cout << mx << endl;

    return;
}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}