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


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.10.28——23:06:18
/*
 *
 *
 *
*/

void solve() {
    i64 n, k, x;
    cin >> n >> k >> x;
    vector<i64>a(n);
    for (auto& tt : a) { cin >> tt; }
    sort(all(a));
    if (n + k > x + 1) {
        for (int i = 0;i < k;i++) {
            cout << i << " \n"[i == k - 1];
        }
        return;
    }
    vector<pll>lr;

    auto check = [&](i64 d)->bool {
        i64 sum = 0;
        for (auto idx : a) {
            i64 ll = max(0LL, idx -d + 1);
            i64 rr = min(x, idx + d - 1);
            if (lr.empty() || ll > lr.back().se + 1) {
                lr.push_back({ ll,rr });
            } else {
                lr.back().se = max(lr.back().se, rr);
            }
        }
        for (auto [lv, rv] : lr) {
            sum += rv - lv + 1;
        }

        if (x + 1 - sum >= k) {
            return true;
        } else {
            return false;
        }
        };
    i64 l = 0, r = x + 1, ansd = 0;
    while (l <= r) {
        i64 mid = l + (r - l >> 1);
        if (check(mid)) {
            ansd = l;
            l = mid + 1;
            // r = mid;
        } else {
            r = mid - 1;
            // l = mid + 1;
        }
        lr.clear();
    }

    check(ansd);
    i64 sst = 0;
    vector<i64>ans;
    for (auto [st, ed] : lr) {
        for (int i = sst;i < st;i++) {
            ans.push_back(i);
        }
        sst = ed + 1;
    }
    for (int i = 0;i < k;i++) {
        de(i);
        cout << ans[i] << " \n"[i == k - 1];
    }
    deb(k)
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    // cout << T << endl;
    while (T--) {
        solve();
    }
    return 0;
}