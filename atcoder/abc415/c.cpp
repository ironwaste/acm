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

// 2025.07.19——20:15:13
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    i64 sum = (1LL << n) - 1LL;
    if (s[sum - 1] == '1') {
        cout << "No\n";return;
    }
    vector<i64>dp(sum + 10LL,0);
    dp[sum] = 1;
    for (i64 i = sum;i;i--) {
        if (!dp[i])continue;
        for (i64 j = 0;j < 18;j++) {
            i64 v = i -(1LL << j);
            if (((i >> j) & 1LL )&& s[v - 1] != '1') {
                dp[i - (1LL << j)] = 1;
            }
        }
    }

    cout << ((dp[0]) ? "Yes\n" : "No\n");
}
// 2025.07.19——21:11:40

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