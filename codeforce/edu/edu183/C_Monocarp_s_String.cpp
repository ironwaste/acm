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
// 2025.10.06——22:52:31
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    i64 asz = 0, bsz = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == 'a') { asz++; }
        if (s[i] == 'b') { bsz++; }
    }
    i64 dif = asz - bsz;
    if (dif == 0) {
        cout << 0 << endl;
        return;
    }
    i64 prx = 0,ans = INT_MAX;
    map<i64, i64>pos;
    pos[0] = -1;
    for (int i = 0;i < n;i ++) {
        i64 v = (s[i] == 'a') ? 1 : -1;
        prx += v;
        if (pos.count(prx - dif)) {
            ans = min(i - pos[prx - dif], ans);
        }
        pos[prx] = i;
    }
    cout << ((ans == n) ? -1 : ans) << endl;
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