#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define i64 long long
#define fi first
#define se second
#define pb(x) push_back(x)
#define mod3 998244353
#define mod7 1000000007
#define de(x) cerr << #x << ' ' << x << ' ';
#define deb(x) cerr << #x << ' ' << x << '\n';


using namespace std;
using pii = pair<int,int>;
using pll = pair<i64,i64>;


void solve(){
    string s;
    cin >> s;
    s = ' ' + s;
    int len = s.size();
    vector<vector<int> >dp(len + 10, vector<int>(len + 10, 0));
    for (int i = 1;i < len;i++) {
        for (int j = len-1;j>0;j--) {
            if (s[i] == s[j]) {
                dp[i][len-j] = dp[i - 1][len-j-1] + 1;
            } else {
                dp[i][len-j] = max(dp[i - 1][len-j], dp[i][len-j-1]);
            }
        }
    }
    cout << len - 1 - dp[len-1][len-1] << endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}