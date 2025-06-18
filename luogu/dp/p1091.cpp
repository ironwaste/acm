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


void solve() {
    int n;
    cin >> n;
    vector<int>p1(n), p2(n);
    map<int, int>mp;
    for (int i = 0;i < n;i++) { cin >> p1[i]; }
    for (int i = 0;i < n;i++) {
        cin >> p2[i];
        mp[p2[i]] = i;
    }
    vector<int>dp(n + 1, 0);
    int ok = 0;


    for (int i = 0;i < n;i++) {
        if (mp[p1[i]] != i) {
            ok = 1;
        }
    }
    if (!ok) { cout << n << endl; return; }

    for (int i = 0;i < n;i++) {
        int id = mp[p1[i]];
        dp[id + 1] = max(dp[id+1],dp[id] + 1);
        for (int j = id + 2;j <= n;j++) {
            if (dp[j] >= dp[j - 1]) { break; }
            dp[j] = max(dp[j - 1], dp[j]);
        }
    }

    cout << dp[n] << endl;
}

int main(){
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}