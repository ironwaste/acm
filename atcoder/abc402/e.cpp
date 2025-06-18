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
// const i64 N = (1LL << 9LL);

void solve(){
    i64 n, x;
    cin >> n >> x;
    i64 N = (1LL << (n + 1LL) ) - 1LL;
    vector<i64>s(n), c(n), p(n);
    for (int i = 0;i < n;i ++) {cin >> s[i] >> c[i] >> p[i];}
    vector<vector<double> >dp(N+10LL,vector<double>(x+10,0.0));
    
    for (i64 v = 0;v <= x;v++) {
  
        for (i64 i = 0;i < n;i++) {
            i64 pp = p[i], q = 100LL - p[i];
            i64 score = s[i], cost = c[i];
            if (v + cost > x)continue;
            for (i64 k = 0;k <= N; k++) {
                if (k & (1LL << i))continue;
                double val = (dp[k + (1LL << i)][v] * q  + pp * (dp[k][v] + score)) / 100.0;
                dp[k + (1LL << i)][v + cost] = max(dp[k + (1LL << i)][v + cost], val);
            }
        }
    }
    printf("%0.08lf",dp[N][x]);
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