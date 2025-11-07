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
// 2025.11.06——23:47:58
/*
 * cntmx >= b[i] && c[i] > cntmx
 *
 *
*/

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64>a(n);
    vector<i64>b(m), c(m), ansc;
    vector<pll>msc, ms0;
    i64 mx = 0;
    for (auto& x : a) { cin >> x; }sort(all(a));
    mx = a.back();
    for (int i = 0;i < m;i++) { cin >> b[i]; }
    for (int i = 0;i < m;i++) { cin >> c[i]; }
    for (int i = 0;i < m;i++) {
        if (c[i] > 0)msc.push_back({ b[i],c[i] });
        else ms0.push_back({ b[i],c[i] });
    }
    sort(all(msc));
    sort(all(ms0));
    multiset<i64>s(all(a));
    i64 sum = 0;
    for (auto [hp, d] : msc) {
        auto it = s.lower_bound(hp);
        if (it == s.end())continue;
        i64 x = *it;
        s.erase(it);
        sum++;
        s.insert(max(x, d));
    }

    for (auto [hp, d] : ms0) {
        auto it = s.lower_bound(hp);
        if (it == s.end())continue;
        i64 x = *it;
        s.erase(it);
        sum++;
    }



    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}