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

// 2025.07.25——12:32:07
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    vector<pll>a(n);
    
    for (int i = 0;i < n;i++) { cin >> a[i].fi >> a[i].se; }
    if (n == 0) { cout << 1LL << endl; }
    else if (n == 1LL) { cout << 2LL << endl; }

    sort(all(a), [&](pll a, pll b) {
        if (a.fi != b.fi) { return a.fi < b.fi; }
        return a.se > b.se;
        });
    auto pos = unique(all(a));
    a.erase(pos, a.end());
    i64 sz = a.size();
    stack<array<i64,3>>stk;
    stk.push({ a[0].fi,a[0].se, 0LL});

    i64 ans = 1LL + sz;
    for (int i = 1;i < sz;i++) {
        auto [l, r] = a[i];
        auto [stkl, stkr, cnt] = stk.top();
        // de(stkl)de(stkr)deb(cnt);de(l)deb(r);
        stk.pop();
        if (l <= stkr && r < stkr) { // 包含
            // cout << "include" << endl;
            stk.push({ stkl, r ,0LL });
        } else if (l <= stkr && r == stkr) {
            if (!stk.empty() && stkl == stk.top()[0]) {
                ans--;
                // stk.pop();
            } else {
                stk.push({stkl,r,cnt + 1LL});
            }
            // cout << "sub" << endl;

        } else if (l <= stkr && r > stkr) {
            // if (cnt == 0LL)ans++;
            stk.push({ stkl,r,cnt + 1LL });
            // cout << "cross" << endl;

        } else if (l > stkr && !stk.empty()) {

            while (!stk.empty() && l > stk.top()[0]) {
                stk.pop();
            }
            stk.push({l,r,0LL});
        }
    }
    // deb(ans)
    cout << ans << endl;


    
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