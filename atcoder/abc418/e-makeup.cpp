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
using pll = pair<i64, i64>;

// 补题——题目链接:https://atcoder.jp/contests/abc418/tasks/abc418_e
// 网址：https://atcoder.jp/contests/abc418/editorial/13627
// 2025.08.10——00:55:33
// 2025.08.10——01:09:09 accpted
/*
 *
 *
 *
*/

vector<pll>p, slope, centrep;
i64 count(const vector<pll> &vec) {
    int sz = vec.size();
    i64 ans = 0, i = 0;
    while (i < sz) {
        i64 j = i;
        while (j < sz && vec[j] == vec[i]) { j++; }
        i64 len = j - i;
        ans += len * (len - 1) / 2;
        i = j;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0;i < n;i++) {
        cin >> p[i].fi >> p[i].se;
    }

    for (int i = 0;i < n;i++) {
        i64 x1 = p[i].fi, y1 = p[i].se;
        for (int j = i + 1;j < n;j++) {
            i64 x2 = p[j].fi, y2 = p[j].se;
            i64 dx = x1 - x2,dy = y1 - y2;
            if (dx == 0) {
                slope.push_back({ INT_MAX ,INT_MIN});
                centrep.push_back({ x1 + x2,y1 + y2 });
            } else {
                i64 gd = __gcd(dx, dy);
                dx /= gd, dy /= gd;
                slope.push_back({ dx,dy });
                centrep.push_back({ x1 + x2,y1 + y2 });
            }
        }
    }
    sort(all(slope));
    sort(all(centrep));
    i64 ans = 0;
    ans += count(slope);
    ans -= count(centrep);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}