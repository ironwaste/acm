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

// 2025.09.10——02:31:06
/*
 *
 *
 *
*/

void solve() {
    int n;
    cin >> n;
    vector<pll>p, add;
    i64 ans = 0;
    for (int i = 0;i < n;i++) {
        i64 l, r;
        cin >> l >> r;
        p.push_back({ l,r });
        add.push_back({ l + r,i });
        ans += 2LL * r - l;
    }
    sort(all(add));
    vector<i64>kk;
    if (n % 2 == 0) {
        for (int i = 0;i <= (n-1) / 2;i++) {
            ans -= add[i].fi;
        }
        cout << ans << endl;
    } else {
        i64 mi = LLONG_MAX, mx = 0;
        for (int i = 0;i <= n / 2;i++) {
            ans -= add[i].fi;
            i64 idx = add[i].se;
            i64 l = p[idx].fi, r = p[idx].fi;
            // de(l);
            mx = max(mx, l);
            // deb(mx);
        }
        i64 tmp = ans + mx;
        ans += add[n / 2].fi;
        // de(tmp);
        for (int i = n / 2;i < n;i++) {
            i64 idx = add[i].se;
            mi = min(mi, p[idx].se);
            // ans -= p[idx].fi;
        }
        tmp = max(tmp, ans - mi);
        // deb(tmp);
        cout << tmp<< endl;
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