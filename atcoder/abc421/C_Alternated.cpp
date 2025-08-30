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

// 2025.08.30——20:09:37
// 2025.08.30——20:15:58 没思路
// 2025.08.30——21:15:55 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    string s;
    // vector<i64>a, b;
    // vector<pll>ab(2 * n + 1, { 0,0 }), num;
    cin >> s;
    i64 sz = s.size(), ans = 0;
    vector<i64>odd(n), even(n);
    for (int i = 0,v = 1;i < n;i ++,v+=2) {
        odd[i] = v;
    }
    for (int i = 0,v = 0;i < n;i ++,v+=2) {
        even[i] = v;
    }
    vector<i64>a;
    for (int i = 0;i < sz;i++) {
        if (s[i] == 'A') {a.push_back(i);}
    }
    i64 cost1 = 0, cost2 = 0;
    for (int i = 0;i < n;i++) {
        cost1 += abs(a[i] - odd[i]);
        cost2 += abs(a[i] - even[i]);
    }
    

    cout << min(cost1,cost2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}