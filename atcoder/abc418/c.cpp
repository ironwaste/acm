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

// 2025.08.09——20:16:19
// 2025.08.09——20:30:51 wa6 个。。。？？？ ...
// 难道是没开 i64 吗 ？ 。。。
// 2025.08.09——20:39:33 accpted  还真是。。。。
/*
 * 题目意思： 有长度为n的数组，
 * 要求选择 大于 qq次询问中 b 的 值 个不同的数字
 * 请问是否 有解， 有解的情况下至少需要多少个茶包才能够保证最后
 * 选中的x 个茶包中有b个都是同一种 数字
 *
 * 需要 b 个相同
 * 最少需要选择多少
 * 如果 没有任何一种有b个则无解
 * 也就是说 所有的都要选择 min(b-1, cnt)
*/

void solve(){
    i64 n, q;
    cin >> n >> q;
    vector<i64>cnt(n);
    for (auto& x : cnt) { cin >> x; }
    
    sort(all(cnt));
    // int sz = cnt.size();
    vector<i64>prefix(n + 1,0);
    partial_sum(all(cnt), prefix.begin() + 1);
    while (q--) {
        i64 b;
        cin >> b;
        if (b > cnt.back()) {
            // deb(-1);
            cout << -1 << endl;
            continue;
        }
        i64 pos = lower_bound(all(cnt), b) - cnt.begin();
        // de(pos)
        i64 ans = prefix[pos] + (1LL * n - pos) * (b - 1LL) + 1;
        // deb(ans);
        cout << ans << endl;
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