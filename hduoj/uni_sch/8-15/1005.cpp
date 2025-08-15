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
// 2025.08.15——15:14:33
/*
 *
 *
 *
*/
i64 n;
int sgn128(__int128 v){ return (v>0) - (v<0); }
int Cross(pll a, pll b, pll c){
    i128 abx = ( __int128)b.fi - a.fi;
    i128 aby = ( __int128)b.se - a.se;
    i128 acx = ( __int128)c.fi - a.fi;
    i128 acy = ( __int128)c.se - a.se;
    return sgn128(abx*acy - aby*acx); // 返回 -1/0/1
}
pll norm_k(i64 dx, i64 dy) {
    if (dx == 0 && dy == 0)return { 0,0 };
    if (dx == 0)return { 0,dy > 0 ? 1 : -1 };
    if (dy == 0)return { dx > 0 ? 1 : -1,0 };
    i64 g = __gcd(llabs(dx), llabs(dy));
    dx /= g, dy /= g;
    if(dx < 0) {
        dx = -dx, dy = -dy;
    }
    return { dx,dy };
}

pll calc_k(pll a, pll b) {
    i128 x1 = a.fi, x2 = b.fi, y1 = a.se, y2 = b.se;
    i128 dx = x2 - x1, dy = y2 - y1;

    return norm_k(dx, dy);
}
pll Max(pll a, pll b) {
    if (a.fi != b.fi)
        return (a.fi > b.fi) ? a : b;
    if (a.se != b.se)
        return (a.se > b.se) ? a : b;
    return b;
}

pll Min(pll a, pll b) {
    if (a.fi != b.fi)
        return (a.fi < b.fi) ? a : b;
    if (a.se != b.se)
        return (a.se < b.se) ? a : b;
    return b;
}

i64 preid(i64 id) { return (id - 1 + n) % n; }
i64 nxid(i64 id) { return (id + 1LL) % n; }
i64 jud(pll a, pll b, pll c, i64 v) {
    // v 表示顺逆时针
    // v 1  顺 , 0 逆
    // cross < 0 顺 
    // cross > 0 逆
    // v cross
    // 1 + = 0 (凹)
    // 1 - = 1 (凸)
    // 0 + = 1 (凸)
    // 0 - = 0;(凹)
    i128 vv = Cross(a, b, c);
    // de(vv);
    if (v == 1) {
        if (vv > 0) { return 0; } else { return 1; }
    } else {
        if (vv > 0) { return 1; } else { return 0; }
    }
}
i64 check(pll pregd, pll nxgd) {
    i128 prey = pregd.se, nxy = nxgd.se;
    i128 prex = pregd.fi, nxx = nxgd.fi;
    i128 gd = __gcd(prex, nxx);
    i128 lcm = prex * nxx / gd;
    i128 prek = lcm / prex, nxk = lcm / nxx;
    if (prey * prek > nxy * nxk) {
        return 0; //逆时针
    } else {
        return 1;// 顺时针
    }
}
using a3 = array<i64, 3>;
void solve() {
    cin >> n;
    vector<pll>p(n);
    for (int i = 0;i < n;i++) {
        cin >> p[i].fi >> p[i].se;
    }
    vector<pll>ansp;
    i64 cnt = 1;
    pll pregd = calc_k(p[0], p[1]);
    ansp.push_back(p[0]);
    ansp.push_back(p[1]);
    for (int i = 2;i < n;i++) {
        pll gd = calc_k(ansp[cnt], p[i]);
        if (gd == pregd) {
            ansp[cnt] = p[i];
        } else {
            ansp.push_back(p[i]);
            cnt++;
            pregd = gd;
        }
    }
    p.clear();
    p.resize(0);
    n = cnt;


    p.push_back(ansp[1]);
    p.push_back(ansp[0]);
    pregd = calc_k(ansp[1], ansp[0]);
    cnt = 1;
    for (int i = n;i > 1;i--) {
        pll gd = calc_k(p[cnt], ansp[i]);
        if (gd == pregd) {
            p[cnt] = ansp[i];
        } else {
            p.push_back(ansp[i]);
            cnt++;
            pregd = gd;
        }
    }
    n = cnt + 1;
    ansp.clear();



    i64 st = 0;
    for (int i = 1;i < n;i++) {
        pll tmp = Min(p[st], p[i]);
        if (tmp == p[i]) { st = i; }
    }
    i64 ed = preid(st), nx = nxid(st);

    pregd = calc_k(p[ed], p[st]);
    pll nxgd = calc_k(p[st], p[nx]);

    i64 v = check(pregd, nxgd);

    vector<array<i64, 3 >>ans(n);
    for (int i = 0;i < n;i++) {
        ans[i][0] = p[i].fi;
        ans[i][1] = p[i].se;
        ans[i][2] = 0;
    }

    for (int i = 0;i < n;i ++ ) {
        i64 nx = nxid(i), pre = preid(i);
        pll cntp = p[i], nxp = p[nx], prep = p[pre];
        ans[i][2] = jud(prep, cntp, nxp, v);
    }

    
    sort(all(ans), [&](a3 a, a3 b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
        });


    cout << n << endl;
    for (int i = 0;i < n;i++) {
        cout << ans[i][0] << " " << ans[i][1] << " ";
        cout << ((ans[i][2] == 1) ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}