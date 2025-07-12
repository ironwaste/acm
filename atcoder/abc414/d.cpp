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

// 2025.07.12——21:03:19
/*
 * 5 8 10 14 15 15 20   
 * 本需要 20 - 5； 15
 * 3 2 4 1 0 5
 * 5 4 3 2 1 0
 * 6
*/

void solve(){
    i64 m,n;
    cin >> n >> m;
    vector<i64>a(n);
    for (auto &x : a) {cin >> x;}
    sort(all(a));
    i64 ans = a.back() - a[0];
    vector<i64>diff(n);
    for (int i = n - 1;i;i--) {
        diff[i] = a[i] - a[i - 1];
    }
    sort(all(diff));
    for (int j = 0, i = n - 1;j < m - 1;j ++,i--) {
        ans -= diff[i];
    }
    cout << ans << endl;
}
// 2025.07.12——21:18:17 accpted
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