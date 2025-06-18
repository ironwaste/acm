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


bool diff(i64 cntup, i64 cntdown, i64 mxup, i64 mxdown) {
    i64 to = cntdown * mxdown / __gcd(cntdown,mxdown);
    if (cntup * (to / cntdown) > mxup * (to / mxdown)) {
        return true;
    }
    return false;
}


void solve(){
    i64 n, B, bias;
    cin >> n >> B >> bias;

    vector<i64>a(n),psum(n,0);
    i64 sum = 0;
    vector<pll>dp(n), ndp(n + 1);
    // ndp[0].fi = 0, ndp[0].se = 0;
    for (auto& x : a) {
        cin >> x;
        sum += x;
    }
    dp[0].fi = a[0], dp[0].se = 1;
    for (int i = 1;i < n;i++) {
        
        dp[i].fi = dp[i - 1].fi + a[i];
        dp[i].se = dp[i - 1].se + 1;
        
        if ((dp[i - 1].fi + a[i] - a[i - dp[i - 1].se]) * (bias + (dp[i].se + B) / B) < dp[i].fi * (bias + (dp[i - 1].se + B) / B)) {
            dp[i].fi = dp[i - 1].fi + a[i] - a[i - dp[i - 1].se];
            dp[i].se = dp[i - 1].se;
        }
        if ((dp[i - 1].fi + a[i]) * (bias + 1LL) < a[i] * (bias + (dp[i - 1].se + B) / B)) {
            dp[i].fi = a[i];
            dp[i].se = 1;
        }
    }
    // i64 sz = pl.size();
    // partial_sum(all(a).pre.begin() + 1);
    // psum[n - 1] = sum;
    i64 mxfrac = 0, mxdown = 1;

    for (int i = 0;i < n;i++) {
        i64 cntup = dp[i].fi , cntdown = (bias + ((dp[i].se + B - 1) / B));
        // de(cntup)deb(cntdown);
        if (diff(cntup, cntdown, mxfrac, mxdown)) {
            mxfrac = cntup;
            mxdown = cntdown;
        }
        
    }
    i64 gd = __gcd(mxfrac, mxdown);
    cout << mxfrac / gd << "/" << mxdown / gd << endl;
    return ;
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