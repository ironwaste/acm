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

// 补题——题目链接: https://ac.nowcoder.com/acm/contest/108300/E
// 网址：
// 2025.09.17——18:34:51
/*
 *
*/
const i64 N = 5e6 + 10;
i64 minp[N];
void init() {
    minp[1] = 1;
    for (i64 i = 2;i < N;i++) {
        if (!minp[i]) {
            minp[i] = i;
            for (i64 j = i * i;j < N;j += i) {
                if (!minp[j])minp[j] = i;
            }
        }
    }
}

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    i64 gd = 0;
    for (auto& x : a) {
        cin >> x;
        gd = __gcd(gd, x);
    }
    if (n % 2 == 1) { cout << "YES\n";return; }
    if (n == 2) { cout << ((a[0] == a[1]) ? "YES" : "NO") << endl;return; }
    for (auto& x : a) { x /= gd; }
    unordered_map<i64, i64>mp;
    for (auto x : a) {
        i64 w = x, v = minp[x];
        while (w > 1) {
            if (mp.count(v))
                mp[v] ^= 1LL;
            else mp[v] = 1;
            w /= v;
            v = minp[w];
        }
    }
    for (auto [x, y] : mp) {
        if (mp[x] % 2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}