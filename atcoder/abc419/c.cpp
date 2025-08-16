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

// 2025.08.16——20:07:26
// 2025.08.16——20:20:04 accpted
/*
 *
 * 可以横着走竖着走以及斜着走
 * 所以判断的是 ，其到中点的 x 或者 y差值的最大值即可
*/

i64 mxi(i64 l,i64 mid,i64 r) {
    i64 m1 = mid, m2 = mid + 1;
    i64 ans1 = max(r - m1, m1 - l), ans2 = max(r - m2, m2 - l);
    return min(ans1, ans2);
}
i64 dis(pll a, pll b) {
    i64 x = abs(a.fi - b.fi), y = abs(a.se-b.se);
    return max(x, y);
}

void solve() {
    int n;
    cin >> n;
    vector<pll>p(n);
    i64 mxx = INT_MIN, mix = INT_MAX, mxy = INT_MIN, miy = INT_MAX;
    for (int i = 0;i < n;i++) {
        cin >> p[i].fi >> p[i].se;
        mxx = max(mxx, p[i].fi);
        mix = min(mix, p[i].fi);
        mxy = max(mxy, p[i].se);
        miy = min(miy, p[i].se);
    }


    i64 midx = (mxx + mix) / 2;
    i64 midy = (mxy + miy) / 2;
    vector<pll>mid;
    vector<i64>ans(4, 0);
    mid.push_back({ midx, midy });
    mid.push_back({ midx + 1, midy + 1});
    mid.push_back({ midx, midy + 1});
    mid.push_back({ midx + 1, midy});
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < 4;j ++) {
            ans[j] = max(ans[j], dis(mid[j], p[i]));
        }
    }
    i64 res = ans[0];
    for (int i = 0;i < 4;i ++) {
        res = min(res, ans[i]);
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}