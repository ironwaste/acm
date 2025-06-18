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
    i64 n, k;
    cin >> n >> k;
    if (k % 2 == 1LL) {
        cout << 0LL << endl;
        return ;
    }
    i64 ans = 0;
    i64 st = k / 2LL;
    n -= st;
    i64 res = n % k;
    n -= res;
    i64 sum = n / k;
    ans += (k) * ((1LL + sum) * sum / 2LL);
    ans += res * (sum + 1LL);

    // de(ans)de(sum)de(res);
        
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    return 0;
}