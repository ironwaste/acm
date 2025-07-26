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

// 2025.07.26——20:58:02
// 2025.07.26——21:07:01  wa了。。。
// 2025.07.26——21:25:38
// 2025.07.26——21:33:56 accept
/*
 *
 *
 *
*/

void solve(){
    i64 n, m;
    cin >> n >> m;
    vector<i64>a(n), b(n);
    i64 ans = 0LL;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        a[i] %= m;
        ans += a[i];
    }
    for (int i = 0;i < n;i++) {
        cin >> b[i];
        b[i] %= m;
        ans += b[i];
    }
    // deb(ans);
    sort(all(a));
    sort(all(b));
    // deb("a --------------- ");
    // for (auto x : a) {
    //     cout << x << " ";
    // }cout << endl;

    // deb("b --------------- ");
    // for (auto x : b) {
    //     cout << x << " ";
    // }cout << endl;


    i64 mxid = -1, num = 0;
    // 定义mxid为 没有被 使用的
    for (i64 i = n - 1;~i;i--) {
        i64 v = m - a[i];
        auto pos = lower_bound(all(b), v) - b.begin();
        // mx = max(min(pos,i), mx);
        if (pos < n  && mxid < n) {
            mxid = max(mxid + 1LL, pos + 1LL);
            num++;
        }
        // de(v)de(pos)de(mxid)deb(num)
    }
    cout << ans - num * m << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}