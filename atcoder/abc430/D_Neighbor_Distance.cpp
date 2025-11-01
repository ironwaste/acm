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
// 2025.11.01——20:40:33
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    set<i64>s;
    map<i64, i64>mp;
    i64 a;cin >> a;
    s.insert(0);
    s.insert(a);
    mp[0] = a;
    mp[a] = a;
    cout << 2 * a << endl;
    i64 sum = 2LL * a;
    for (int i = 1;i < n;i++) {
        cin >> a;
    
        auto lw = s.lower_bound(a);
        auto up = lw;
        lw--;
        i64 l_idx = *lw;
        i64 lv = mp[l_idx];
        i64 lcv = abs(l_idx - a);
        mp[a] = lcv;
        if (lv > lcv) {
            sum -= lv;
            sum += lcv;
            mp[l_idx] = lcv;
        }
        // de(a)de(lv)de(lcv)de(sum);

        i64 r_idx;
        if (up != s.end()) {
            r_idx = *up;
            i64 rv = mp[r_idx];
            i64 rcv = abs(r_idx - a);
            if (rv > rcv) {
                sum -= rv;
                sum += rcv;
                mp[r_idx] = rcv;
            }
            mp[a] = min(mp[a], rcv);
        }
        sum += mp[a];
        cout << sum << endl;
        s.insert(a);
    }


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