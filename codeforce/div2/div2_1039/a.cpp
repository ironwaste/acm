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

// 2025.07.27——22:35:42
// 2025.07.27——22:40:14 accpted
/*
 * 一个长度为n数组，当大于 c的值时销毁需要 1个硬币
 * 所以不是 1个 硬币就是 0个，当销毁一个之后，其他的 数组的值*2
 *
 */

void solve() {
    i64 n,c;
    cin >> n >> c;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    sort(all(a));
    i64 ans = n;
    i64 cnt = 1LL;
    for (int i = n-1;~i;i--) {
        i64 v = a[i] * cnt;
        if (v <= c) {
            ans--;
            cnt *= 2LL;
        }
    }
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