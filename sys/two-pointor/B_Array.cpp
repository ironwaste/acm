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

// 补题——题目链接: https://codeforces.com/problemset/problem/224/B
// 网址：
// 2025.11.06——17:12:12
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    map<i64, i64>mp;
    i64 al = -1, ar = -1, sz = 0;
    for (int l = 0, r = 0;l < n;l ++) {
        while (r < n && sz < k) {
            if (!mp.count(a[r])) { sz++; }
            mp[a[r++]] ++;
        }
        if (sz == k) {
            al = l + 1, ar = r;
        }
        i64 v = a[l];
        mp[v]--;
        if (mp[v] == 0) { mp.erase(v); sz--; }
        if (sz == k) {
            al = l + 1, ar = r;
        }
    }
    cout << al << " " << ar << endl;

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