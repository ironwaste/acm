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

// 2025.08.16——20:20:22
// 2025.08.16——20:25:10 accpted
/*
 *
 *
 *
*/

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    vector<pll>trans(m);
    vector<i64>diff(n + 10, 0);
    for (int i = 0;i < m;i++) {
        i64 l, r;
        cin >> l >> r;
        trans[i].fi = l, trans[i].se = r;
        diff[l]++;
        diff[r + 1]--;
    }
    vector<i64>prx(n + 12, 0);
    partial_sum(all(diff), prx.begin());
    for (int i = 1;i <= n;i ++) {
        if (prx[i] % 2 == 1) {
            cout << t[i];
        }else{
            cout << s[i];
        }
    }
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