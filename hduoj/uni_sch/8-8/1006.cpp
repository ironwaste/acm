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

using pii = pair<int, int>;
using pll = pair<i64, i64>;
using i128 = __int128;
// 2025.08.08——14:47:00
/*
 *
 *
 *
*/
void print(i64 p, i64 q) {
    // de(p)deb(q);
    cout << p << "/" << q << endl;
    return;
}

void solve() {
    i64 k, n, a, b, c, d, x, y, l, r;
    cin >> k >> n >> a >> b >> c >> d;

    a = a * d;
    c = c * b;
    y = b = d = d * b;
    // de*()
    // i64 cd = __gcd(c, d),ab = __gcd(a,b);
    l = a, r = c;
    // de(k)de(n)de(b)de(y) de(l)deb(r)
    // l 为分子的小 r 为分子大
    // 这个时候 b 和 d 的大小相同
    i64 p = 0, q = 0, ansp = 0, ansq = 0;
    i64 sumx = y * k;
    // deb(sumx);
    i64 div = sumx / n;
    // deb(div);
    // vector<i64>xi(2);
    // xi = { l, min(r, div) };
    i64 xr = 0;
    for (i64 i = r;i <= r;i++) {
        i64 v = sumx / (i * n);
        p = i * (sumx / (n * i)) + i;
        q = y;
        i64 pq = __gcd(p, q);
        p /= pq, q /= pq;
        // print(p, q);
        if (i == r) {
            ansp = p;
            ansq = q;
        }
        if ((i128) (ansp * q) < (i128) (ansq * p)) {
            ansp = p;
            ansq = q;
        }
    }

    x = y * k / n;
    i64 v = sumx / (x * n);
    p = x * v + x;
    q = y;
    i64 pq = __gcd(p, q);
    p /= pq, q /= pq;
    if ((i128) (ansp * q) < (i128) (ansq * p)) {
        ansp = p;
        ansq = q;
    }




    print(ansp, ansq);
    // cout << ansp << "/" << ansq << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // de(__gcd(-1, -1));
    while (T--) {
        solve();
    }
    return 0;
}