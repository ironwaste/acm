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

// 2025.09.09——23:44:06
// 2025.09.10——00:37:02
/*
 *
 *
 *
*/

void solve() {

    i64 n;
    cin >> n;
    vector<i64>a(n + 2);
    vector<pll>ansxo, ansxe, ansyo, ansye;
    vector<i64>odd, even(1, 0);
    map<i64, pll>mp;
    i64 res = 0;
    for (i64 i = 1;i <= n;i++) {
        i64 v;
        cin >> v;
        if (i % 2 == 1) {
            res += v;
            odd.push_back(v);
            a[i] = v;

        } else {
            even.push_back(v);
            res -= v;
            // v = -v;
            a[i] = -v;
        }
        if (mp.count(v)) {
            mp[v].fi = min(mp[v].fi, i);
            mp[v].se = max(mp[v].se, i);
        } else {
            mp[v] = { i,i };;
        }
        v = v * 2LL;
        i64 x = i + v, y = v - i;
        if (i % 2 == 1) {
            ansxo.push_back({ x,i });
        } else {
            ansxe.push_back({ x,i });
        }
        if (i % 2 == 1) {
            ansyo.push_back({ y,i });
        } else {
            ansye.push_back({ y,i });
        }
    }
    if (n == 1) { cout << a[1] << endl; return; }

    i64 add = 0;
    for (auto [x,y] : mp) {
        i64 i2 = y.fi, i1 = y.se;
        add = max(i1 - i2, add);
    }

    add = max(add, n - 1 - ((n + 1) % 2));

    sort(all(ansxo));
    sort(all(ansyo));
    sort(all(ansxe));
    sort(all(ansye));

    i64 xeo = ansxe.back().fi - ansxo[0].fi;
    i64 yeo = ansye.back().fi - ansyo[0].fi;
    
    i64 mx = max(xeo, yeo);
    cout << max(res + mx,res + add) << endl;
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