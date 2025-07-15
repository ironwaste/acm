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

// 2025.07.15——12:02:13
/*
 *
 *
 *
*/
i64 pw(i64 a, i64 b,i64 mod) {
    i64 res = 1LL;
    while (b) {
        if (b & 1LL) res = a * res % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return res % mod;
}

i64 inv(i64 a,i64 mod) {
    return pw(a, mod - 2, mod);
}


void solve() {
    i64 n, p;
    cin >> n >> p;
    vector<i64>a(n);
    i64 lc = 1;
    for (auto& x : a) {
        cin >> x;
        lc = (lc * x) * inv(__gcd(lc, x),mod7);
    }

    cout << lc << endl;

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