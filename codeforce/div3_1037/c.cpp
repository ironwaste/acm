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
    i64 n, k;
    cin >> n >> k;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    i64 cnt_h = a[k - 1],w_h = 1;
    vector<i64>h;
    for (int i = 0;i < n;i ++) {
        if (a[i] > cnt_h) { h.pb(a[i]); }
    }
    sort(all(h));
    // for (auto x : h) {
    //     de(x);
    // }cout << endl;
    i64 sz = h.size(), ok = 1;
    for (int i = 0;i < sz;i++) {
        if (cnt_h < w_h) { ok = 0;break; }
        // de(cnt_h)deb(w_h)
        i64 need_time = h[i] - cnt_h, w_time = cnt_h - w_h + 1LL;
        // de(need_time)deb(w_time)
        if (need_time > w_time) { ok = 0;break; }
        cnt_h = h[i], w_h += need_time;
        // de(cnt_h)deb(w_h)
        //     cout << endl;
    }
    cout << ((ok) ? "YES" : "NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // 2025.07.17——22:44:24
/*
 *
 *
 *
*/
    while(T--){
        solve();
    }
    return 0;
}