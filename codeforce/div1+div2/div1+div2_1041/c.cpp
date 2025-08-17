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

// 2025.08.07——23:06:38

// 2025.08.07——23:34:49 
// 2025.08.08——00:08:17 wa 2 .... 服了应该是g了
// 2025.08.08——00:36:49 wa 2 ???? 
// 2025.08.08——00:38:23 wa 2 不用写了 。。。。 
// 2025.08.08——00:47:37 wa 3
// 2025.08.08——01:04:52 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n,k;
    cin >> n >> k;
    vector<pll>ab(n);
    for (int i = 0;i < n;i++) { cin >> ab[i].fi; }
    for (int i = 0;i < n;i++) {
        cin >> ab[i].se;
        if (ab[i].fi > ab[i].se) {
            swap(ab[i].fi, ab[i].se);
        }
    }
    // 如果存在包含或者交叉的情况 则可以 使得值为 最初的解

    sort(all(ab));
    // for (int i = 0;i < n;i++) {
    //     cout << ab[i].fi << " ";
    // }cout << endl;

    // for (int i = 0;i < n;i++) {
    //     cout << ab[i].se << " ";
    // }cout << endl;

    // 都是 小的放在前面的情况 ，判断是否 有交叉或者包含的情况，如果有则直接输出初始值
    // 如果没有 的情况下 ，我们去查找 并且去取得最终的 没交叉的情况下 x1 - y2 + y1 - x1 的最大值
    i64 ok = 1;
    i64 ans = LLONG_MAX;
    for (int i = 0;i < n - 1; i++) {
        i64 x1 = ab[i].fi, x2 = ab[i + 1].fi;
        i64 y1 = ab[i].se, y2 = ab[i + 1].se;
        if (x1 <= y1 && y1 < x2 && x2 <= y2) {
            i64 v = (x2 - y1) * 2;
            if (v < ans) {
                ans = min(v,ans);
            }
        } else {
            ok = 0;
            break;
        }
    }
    i64 res = 0;
    // de(ok)deb(ans);
    if (ok)res += ans;
    for (i64 i = 0;i < n;i ++) {
        // if (ok) { continue; }
        i64 x1 = ab[i].fi, y1 = ab[i].se;
        res += abs(x1 - y1);
    }
    // deb(res);
    cout << res << endl;
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