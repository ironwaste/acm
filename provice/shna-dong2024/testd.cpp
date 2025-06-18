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


void solve() {
    i64 p, a, b, q, c, d, m, t;
    cin >> p >> a >> b >> q >> c >> d >> m >> t;
    i64 k = a + c, B = b + d, e = q - p;
    if (p > m) {
        cout << m << endl;
        return;
    }
    while (t >= b + d + a + c) {
        i64 x = m / p;
        // deb((x + 1) * p - m);
        // i64 ci = ((x + 1) * p - m) / e + ((((x + 1) * p - m )% e) ? 1 : 0);
        i64 ci = (((x + 1) * p - m) + e * x - 1) / (e * x);
        // 向上取整的问题
        i64 Tt = ci * (x * k + B);
        // de(m)de(x)de(ci)deb(Tt);
        if (Tt <= t) {
            m += ci * x * e;
            t -= Tt;
        } else {
            while (t >= k * x + B) {
                m += e * x;
                t = t - (x * k + B);
            }
            while (t >= k + B) {
                i64 xx = (t - B) / k;
                m += e * xx;
                t = t - (xx * k + B);
            }
            break;
        }
    }
    cout << m << endl;
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
