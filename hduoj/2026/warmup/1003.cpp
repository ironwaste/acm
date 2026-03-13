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

// 2026.03.13——19:16:52
// 2026.03.13——19:47:23 ac
/*
 *
 *
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    if (n > m)swap(n, m);
    if (n == 1) {
        cout << (m + 2) / 2 << endl;
        return;
    }
    i64 ans = n;
    i64 res = m - n;
    i64 tk = res / 2;
    if (res % 2 == 1) {
        ans += tk + 1;
    } else {
        ans += tk;
    }
    // res = min(res,)
    // i64 k  = m  / (n + 1);
    // i64 re = m % (n + 1);

    
    cout << ans << endl;
    

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