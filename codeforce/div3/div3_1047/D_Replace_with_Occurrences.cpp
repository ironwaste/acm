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

// 2025.09.11——02:33:38
// 2025.09.11——02:40:50 accpted
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>b(n);
    // vector<i64>g[n + 1];
    map<i64, vector<i64>>mp;
    i64 sum = 0;
    for (int i = 0;i < n;i ++) {
        i64 x;
        cin >> x;
        b[i] = x;
        // sum += x;
        mp[x].push_back(i);
    }
    i64 ok = 1, v = 1;
    vector<i64>a(n, 0);
    for (auto [x, vec] : mp) {
        i64 sz = vec.size();
        if (sz % x != 0) { ok = 0;break; }
        i64 cnt = 0;
        for (auto y : vec) {
            a[y] = v;
            cnt++;
            if (cnt % x == 0)v++;
        }
    }
    if (ok == 0)cout << -1 << endl;
    else {
        for (int i = 0;i < n;i ++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }

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