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

// 2025.07.15——12:36:33
/* 俩个居民的差值为 c 的时候，国王才会建造一个梯子
 * 每个长度会建造一个梯子，不建造相同的梯子
 * 从3开始的奇数都有 相邻的两个居民
 * 从8开始的 4 的倍数都有 每间隔一个居民
 * 先算第几个奇数
 * 1 / 2 = 0，正好以及将1删去了，所所以直接从3开始
 * 再算是第几个 4的倍数 4 / 4 = 1.8 /4 = 2
 * 然后将4 删去
*/

void solve() {
    i64 a, b;
    cin >> a >> b;
    if (a < b)swap(a, b);
    i64 diff = llabs(a - b)*(a+b);

    i64 ans = diff / 2LL; // 除去1之外的所有奇数
    ans += (diff) / 4LL - 1LL;// 除4以外的所有4的倍数
    cout << ans << endl;
}
// 2025.07.15——13:06:58 wa 巨快
// 2025.07.15——13:20:17 accpted

int main() {
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