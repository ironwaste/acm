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

// 2025.07.18——12:12:18
/*
 * 性质为一个n的排列，所以每一个数字就只会出现一次
 * 且子序列 ，子序列的话，不需要连续，一个维护小于的，找其中的最小值
 *
 */

void solve(){
    i64 n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x;x--; }
    vector<i64>p(n);
    for (int i = 0;i < n;i ++) {
        p[a[i]] = i;
    }
    i64 ans = 0, mi = 0, mx = 0, cnt = 1;
    if (n <= 2) {
        cout << n << endl;
        return;
    }
    mi = min(p[n - 1], p[n - 2]);
    mx = max(p[n - 1], p[n - 2]);
    ans = max(ans, mx - mi + 1LL);
    for (int i = n - 3;i>=0;i--, cnt++) {
        mi = min(mi, p[i]);
        mx = max(mx, p[i]);
        ans = max(mx - mi + 1LL - cnt, ans);
    }
    cout << ans << endl;
}
// 2025.07.18——12:43:48 accept
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