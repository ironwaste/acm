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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


// 补题——题目链接: https://acm.hdu.edu.cn/contest/problem?cid=1178&pid=1006
// 网址：
// 2025.08.09——16:02:06
/*
 *
 *
**/

void solve(){
    i64 k, n, a, b, c, d;
    cin >> k >> n>> a >> b >> c >> d;

    i64 gd = __gcd(b, d);
    i64 lcm = b * d / gd;
    i64 ad = lcm / b, cd = lcm / d;

    a *= ad;
    b *= ad;
    c *= cd;
    d *= cd;
    // de(a)de(b)de(c)deb(d)
    i64 y = (k * d / (n * c)) + 1LL;
    i64 ansp = y * c, ansq = d;
    // de(ansp)deb(ansq);
    // i64 y1 = y - 1;
    i64 d1 = y * n, c1 = k;
    // de(c1)deb(d1);
    if ( c1*d*((k * d1/(n*c1)) + 1) > c*d1*((k * d/(n*c) + 1)) && c1 * b >= a * d1) {
        ansp = c1 * ((k * d1 / (n * c1) + 1LL));
        ansq = d1;
    }
    gd = __gcd(ansp, ansq);

    cout << ansp/gd << "/" << ansq/gd << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}