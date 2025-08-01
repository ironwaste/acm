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

// 2025.07.31——16:54:01
/*
 *
 *
 *
*/
const int N = 1e5 + 10;
i64 fra[N];

void init() {
    fra[0] = 1;
    for (i64 i = 1;i < N;i ++) {
        fra[i] = fra[i - 1] * i % mod3;
    }
}
i64(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1LL) res = res * a % mod;
        a = a * a % mod3;
        b >>= a;
    }
    return res;
}
i64 inv(i64 x) {
    return pw(x, mod3 - 2);
}
i64 c(i64 n, i64 m) {
    return 
    
}


void solve() {




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