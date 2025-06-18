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
// edu 2 剩余19 mins到 E
vector<i64>zebra;
// 1 5 21 85 341 
// 4 16 64 256 
const i64 N = 1e18 + 10;
// map<i64, i64>mp[55];
// 4 16 64 256  
// 2 ^ 2 、2 ^ 4、2^6、2^8、2^10
// 8 20 64 
// 2 ^ 2 + 2^2 ==> 2^3 、2^2  + 2^4 ==> 
// 、、、


void init() {
    i64 res = 1LL;
    // zebra.pb(res);
    for (;res >= 1 && res < N; res = (res << 2LL) + 1LL) {
        // deb(res)
        zebra.pb(res);
    }
}
// 有一句  逆逻辑  其中表明的是
// 和范围配套使用，因为如果有一个数字是 最少数量的斑马数字的和
// 那么 就不可能存在一个斑马数存在 一个分解数四次以上
// 如果有的话，那么就说明其斑马数的数字不是最小的。
// 

map<pll, i64>dp;


i64 calc(i64 n, i64 k) {


    if (dp.count(make_pair(n, k))) return dp[make_pair(n, k)];
    // i64 memeryd = dp[make_pair(n,k)];
    // if (n < 0)return dp[make_pair(n, k)] = 0LL;
    if (k > 4LL * zebra.size() || k < 0LL) return dp[make_pair(n, k)] = 0LL;

    if (n == 0LL) return dp[make_pair(n, k)] = 0LL;
    // 为什么 n == 1LL 的时候
    // k == 0 会return 1LL 有一个解呢？
    // 到最后的时候 判断 多余的 当 n == 1 了 但是 还有多个k的时候就会没解
    // 

    if (n == 1LL) {
        if (k == 0)return dp[make_pair(n, k)] = 1LL;
        else return dp[make_pair(n,k)] = 0LL;
    }


    auto it = lower_bound(all(zebra), n);
    it--;
    i64 y = *it;// 小于的最大的一个 。
    return dp[make_pair(n, k)] = calc(n - y, k - 1LL) + calc(y, k);

}

void solve() {
    i64 l, r, k;
    cin >> l >> r >> k;

    cout << calc(r + 1LL, k) - calc(l, k) << endl;

    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}