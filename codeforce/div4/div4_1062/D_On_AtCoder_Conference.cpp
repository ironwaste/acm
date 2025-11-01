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
// 2025.10.25——20:13:02
/*
 *
 *
 *
*/

void solve() {
    i64 n, m, c;
    cin >> n >> m >> c;


    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    vector<pll> p;
    i64 cur = a[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == cur) {
            count++;
        } else {
            p.push_back({ cur, count });
            cur = a[i];
            count = 1;
        }
    }
    p.push_back({ cur, count });

    i64 k = p.size();
    vector<pll> cnt = p;
    for (auto [idx, v] : p) {
        cnt.push_back({ idx + m, v });
    }

    vector<i64> prx(2 * k + 1, 0);
    for (int i = 1; i <= 2 * k; i++) {
        prx[i] = prx[i - 1] + cnt[i - 1].se;
    }

    vector<i64> dis;
    for (int i = 0; i < k - 1; i++) {
        i64 vv = p[i + 1].fi - p[i].fi;
        // if (i == 0 && p[i].fi != 1)
        dis.push_back(vv);
    }
    dis.push_back(p[0].fi + m - p[k - 1].fi);

    vector<i64> V(k, 0);
    i64 r = 0;
    for (i64 i = 0; i < k; i++) {
        if (r < i)r = i;
        while (r < 2 * k && prx[r + 1] - prx[i] < c) {
            r++;
        }
        if (r < 2 * k) {
            V[i] = prx[r + 1] - prx[i];
        } else {
            V[i] = n;
        }
    }
    i64 sumx = 0;
    for (int i = 0; i < k; i++) {
        sumx += dis[(i + k - 1) % k] * V[i];
    }

    cout << sumx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}