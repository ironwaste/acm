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

// 2025.07.11——19:05:14
/*
 *
 *
 *
*/

i64 f(i64 x) {
    i64 res = 0;
    for (i64 i = 0;i < 64;i++,x >>= 1LL) {
        res += x & 1LL;
    }
    return res;
}// 计算 x在二进制情况下1的个数

i64 g(i64 x) {
    i64 mx1 = 0, t = x, res = 0;
    for (i64 i = 0;i < 64;i ++,x >>= 1LL) {
        if (x & 1LL)mx1 = max(mx1, i);
    }
    for (int i = 0;i < mx1;i ++,t >>=1LL) {
        if ( !(x &1LL) ) {
            res++;
        }
    }
    return res + 1LL;
}// 计算x在二进制情况下0的个数

void print(i64 x) {
    i64 mx1 = 0, t = x, res = 0;
    for (i64 i = 0;i < 64;i ++,x >>= 1LL) {
        if (x & 1LL)mx1 = max(mx1, i);
    }
    for (i64 i = mx1;~i;i--) {
        // cout << i << " ";
        cout << ((t >> i) & 1LL) << " ";
    }cout << endl;
}


void solve() {
    i64 x;
    cin >> x;
    cout << 1LL << endl;
    // for (i64 x = 1;x <= 100;x++) {
        // deb(x);
        // print(x);
        // i64 prex = -1;
        // // cin >> x;
        // vector<i64>a;
        // a.pb(x);
        // while (prex != x || (a[0] != x)) {
        //     prex = x;
        //     a.pb(g(f(x)));
        //     de(x);
        // }
        // // cout <<endl;
        // deb("----------------------");
        // if (prex == x)deb(x);
        // deb("----------------------");
    // }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}