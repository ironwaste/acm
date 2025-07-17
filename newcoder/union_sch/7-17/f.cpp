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

// 2025.07.17——15:08:25
/* 也就是一个约瑟夫环
 *
 *
 *
*/

void solve(){
    i64 n,t0;
    cin >> n >> t0;
    string s;
    cin >> s;
    s = s + s;
    i64 sz = s.size(), id = -1, cnt0 = 0;
    vector<pll>ans;
    for (int i = 0;i < n;i++) {
        // cout << s[i] << endl;
        if (s[i] == '1') {
            id = i;
            break;
        }
    }
    if (id == -1) {
        cout << n << endl;
        return;
    }
    i64 ok = 0;
    for (int i = id + 1LL;i <= id + n;i++) {
        if (s[i] == '1' && ok == 0) {
            ans.push_back({ 0, cnt0 });
            cnt0 = 0LL;
            ans.push_back({1,1});
            ok = 1LL;
        } else if (s[i] == '0') {
            cnt0++;
            ok = 0LL;
        }
    }
    // deb(ans.size());
    // for (auto x : ans) {
    //     cout << x.se << " ";
    // }cout << endl;

    
    i64 mx0 = 0, ansz = ans.size();
    if (ans.size() != 1LL) {
        if (ans[0].fi == ans[ansz-1].fi) {
            ans[0].se += ans[ansz - 1].se;
            ans[ansz - 1].se = 0;
        }
    }

    i64 res = 0;
    for (int i = 0;i < ansz;i++) {
        if (ans[i].fi == 0) {
            i64 cnt0 = ans[i].se;
            // mx0 = max(min(t0-1LL,cnt0/2+), mx0);
            mx0 = max(min(cnt0 - t0 - 1LL, t0 - 1LL),mx0);
            res += max(0LL, cnt0 - 2 * t0);
        }
    }
    cout << res + max(0LL, mx0) << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}