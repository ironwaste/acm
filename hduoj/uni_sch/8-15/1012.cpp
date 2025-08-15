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

// 2025.08.15——12:16:47
/*
 *
 *
 *
*/

void solve(){
    int n, m;
    cin >> n >> m;
    vector<i64>ans;
    vector<pll>now;
    map<i64, i64>mp;
    for (int i = 0;i < m;i++) {
        i64 x;
        cin >> x;
        if (!mp.count(x)) { ans.push_back(x); }
        mp[x]++;
    }
    for (auto [x, y] : mp) {
        now.push_back({ x,y });
    }
    sort(all(now), [&](pll a, pll b) {
        if (a.se != b.se) return a.se > b.se;
        return a.fi < b.fi;
        });
    i64 res = 0;
    i64 sz = now.size();
    for (int i = 0;i < sz;i ++) {
        if (now[i].fi != ans[i]) {
            res++;
        }
    }
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