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

using pii = pair<int,int>;
using pll = pair<i64, i64>;

void solve() {
    i64 n, qq;
    map<i64, i64>cnt;
    cin >> n >> qq;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x;cnt[x]++; } // n
    while (qq--) {
        i64 p, v;
        cin >> p >> v;
        p--;
        a[p] = a[p] + v;
        auto b = a;
        sort(all(b));
        i64 mid = b[(n + 1LL) / 2];
        // deb(mid);
        i64 ans = lower_bound(all(b), mid) - b.begin();
        // i64 ans = mi_id;
        // deb(ans);
        cout << ans << endl;
        // i64 mid = b[mi_id],ans = b[mi_id - 1];
        // cout << mi_id << endl;
        
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}