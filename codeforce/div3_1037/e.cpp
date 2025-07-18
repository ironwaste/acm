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
/**
 * 先判断两个序列本身的整除性是否满足
 * 最终gcd写作未gd =p[n] = s[0]
 * 再首先,得p[i] 和 s[i] 两者同一位上的gcd要等与最后的gcd
 * __gcd(p[i-1],s[i]) == gd;
 */

void solve() {
    i64 n;
    cin >> n;
    vector<i64>p(n + 2,0), s(n + 2,0);
    for (int i = 1;i <= n;i ++) {cin >> p[i];}
    for (int i = 1;i <= n;i ++) {cin >> s[i];}
    i64 ok = 1,gd = p[n];
    for (int i = 1;i <= n - 1;i ++) {
        if (p[i] % p[i + 1] != 0) { ok = 0; }
    }
    for (int i = 1;i <= n - 1;i ++) {
        if (s[i + 1] % s[i] != 0) { ok = 0; }
    }
    for (int i = 1;i <= n;i++) {
        if (__gcd(p[i-1],s[i]) != gd) {
            ok = 0;
        }
    }
    cout << ((ok) ? "YES\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // 2025.07.17——23:14:46
/*
 *
 *
 *
*/
    while(T--){
        solve();
    }
    return 0;
}