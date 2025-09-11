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

// 2025.09.11——03:27:51
// 2025.09.11——03:56:55 accpted
// https://codeforces.com/contest/2137/problem/F
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n), b(n), mx(n);
    for (auto& x : a) { cin >> x; }
    for (auto& x : b) { cin >> x; }
    for (int i = n - 1;i >= 0;i--) { mx[i] = max(a[i], b[i]); }
    priority_queue<pll>q;
    // 小根堆 小的在上面
    i64 ans = 0;
    for (i64 i = n - 1;i >= 0;i--) {
        // de(a[i]);
        // if (!q.empty()) { deb(q.top().fi); } else {
        //     cerr << endl;
        // }
        while (!q.empty() && q.top().fi <= a[i]) {
            auto [v, idx] = q.top();
            ans += (i+1) * (n - idx);
            // de(i)de(n - idx) de(a[i])deb(v)
            q.pop();
        }
        if (a[i] == b[i]) { ans += (i + 1) * (n - i); }
        else { q.push({ mx[i],i }); }
    }
    // cerr << endl;
    cout << ans << endl;
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