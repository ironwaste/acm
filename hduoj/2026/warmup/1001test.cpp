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

// 2026.03.13——19:02:59
/*
 *
 *
 *
*/

void solve() {
    vector<i64>a(100, 0);
    iota(all(a), 3);
    for (auto x : a) {
        i64 ans = 1,a,b;
        if (x % 2 == 0) {
            a = x / 2 + 1, b = x / 2 - 1;
            
        } else {
            a = x / 2 + 1, b = x / 2;
        }
        for (;b >= 1;b--, a++) {
            ans = max(ans, __gcd(a, b));
        }
        cout << "X :  " << x << " | " << " ans " << ans << endl;
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}