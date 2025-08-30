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
using psi = pair<char, i64>;
// 2025.08.30——20:16:12
// 2025.08.30——20:25:47 end
// 2025.08.30——21:17:33 
/*
 *
 *
 *
*/

pll dir(char c) {
    if (c == 'U') return { -1, 0 };
    if (c == 'D') return { 1, 0 };
    if (c == 'L') return { 0, -1 };
    if (c == 'R') return { 0, 1 };
}

pll pos(psi a) {
    char c = a.first;
    i64 v = a.second;
    pll k = dir(c);
    k.fi *= v;
    k.se *= v;
    return k;
}
bool check(i64 a, i64 b) {
    if (a > 0 && b < 0) {
        return true;
    } else if (a < 0 && b > 0) {
        return true;
    }
    return false;

}

void solve() {
    i64 r1, c1, r2, c2;
    // string s, t;
    i64 n, sz1, sz2;
    i64 ans = 0;
    vector<pair<char, i64> >ss, tt;
    cin >> r1 >> c1 >> r2 >> c2;
    cin >> n >> sz1 >> sz2;
    for (i64 i = 0;i < sz1;i++) {
        psi tmp;
        cin >> tmp.fi >> tmp.se;
        ss.push_back(tmp);
    }
    for (i64 i = 0;i < sz2;i++) {
        psi tmp;
        cin >> tmp.fi >> tmp.se;
        tt.push_back(tmp);
    }


    i64 ids = 0, idt = 0;
    while (ids < sz1 && idt < sz2) {
        i64 len = min(ss[ids].se, tt[idt].se);
        char s = ss[ids].fi, t = tt[idt].fi;
        auto [dr1, dc1] = dir(s);
        auto [dr2, dc2] = dir(t);

        i64 dr = dr2 - dr1, dc = dc2 - dc1;
        i64 diffr = r1 - r2, diffc = c1 - c2;
        if (dr == 0 && dc == 0) {
            if (diffr == diffc && diffr == 0) {
                ans += len;
            }
        } else if (diffr != 0 && diffc != 0 && dr != 0 && dc != 0) {
            i64 k1 = diffr / dr;
            i64 k2 = diffc / dc;
            if (k1 == k2 && k1 >= 1 && k1 <= len) {
                ans++;
            }
        } else if (diffr == 0 && dr == 0) {
            if (diffc % dc == 0) {
                i64 i0 = diffc / dc;
                // i0 = abs(i0);
                if (i0 >= 1 && i0 <= len) {
                    ans++;
                }
            }
        } else if (diffc == 0 && dc == 0 ) {
            // de(diffr)deb(dr);
            if (diffr % dr == 0) {
                i64 i0 = diffr / dr;
                if (i0 >= 1 && i0 <= len) {
                    ans++;
                }
            }

        }
        r1 += len * dr1;
        c1 += len * dc1;
        r2 += len * dr2;
        c2 += len * dc2;

        ss[ids].se -= len;
        if (ss[ids].se == 0) { ids++; }

        tt[idt].se -= len;
        if (tt[idt].se == 0) { idt++; }

    }
    cout << ans << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}




