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

// 2025.09.15——23:21:21
/*
 *
 *
 *
*/

void solve() {
    i64 n, y;
    cin >> n >> y;
    vector<int> c(n);
    int mx = 0;
    for (auto &x : c) {
        cin >> x;
        if (x > mx) mx = x;
    }

    vector<int> cnt(mx + 2, 0);
    for (auto v : c) cnt[v]++;

    vector<int> pref(mx + 2, 0);
    for (int i = 1; i <= mx; i++) pref[i] = pref[i-1] + cnt[i];

    i64 res = LLONG_MIN;

    for (int x = 2; x <= mx + 1; x++) {
        i64 sum = 0;        
        i64 np = 0;  

        for (int p = 1;; p++) {
            long long L = 1LL*(p-1)*x + 1;
            if (L > mx) break;
            long long R = min(1LL*p*x, 1LL*mx);

            int l = (int)L, r = (int)R;
            int freq = pref[r] - pref[l-1];
            if (!freq) continue;

            sum += 1LL * p * freq;

            int re = 0;
            if (p <= mx) re = min(freq, cnt[p]);
            else re = 0;

            np += (freq - re);
        }

        sum -= y * np;
        res = max(res, sum);
    }

    cout << res << endl;
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