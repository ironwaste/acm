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

// 2025.07.17——13:32:02
/* 
 * 可以进行一次操作将两个值进行异或得到新的值
 * 然后将原本随机选中的两个数值也就是一个数对（i，j）i != j 将会消失
 * 最后即求得是否所有的 2^ai 的加和
 * 和改变后的值进行比较 ,那么改变后的值将会比之前的要大即可,如果有一对数对
 * 导致最后的值比之前的小,那么就输出no,否则yes
 * 2 ^ ai + 2 ^ aj  和 2 ^ (ai xor aj) 进行比较
 * 前者其产生的与后面比则 异或后的值一定要大于 a_new = max(ai,aj) +1LL
 *
 * 找是否有 字典树相同值最多的,这样就可以找出是否存在一个值使得两者xor值小于等于原本的值,由于不存在0
 * 只需要求是否存在两个值 异或xor过后
 *
 * 从高位向下数,当遇到 一个数字 大的数字中的 1 和 小的1 ,那么则有使得最终为no的情况
 * 大的数字中的 0 和 小的数字为 1 则直接产生了 最终解为yes的情况
 * 0 0
 * 1 0 的情况
 * 
 * 0 1 yes
 * 1 1 no
 *
 * 直接找所有的最高位1的位置,然后和当前的位置比较如果 当前值为 1 则输出no否则yes
*/

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    for (auto &x : a) {cin >> x;}
    sort(all(a));
    int ok = 1;
    vector<i64>xora(64, 0);
    for (int i = 0;i < n;i ++) {
        i64 x = a[i];
        // 查找是否存在
        for (i64 j = 63LL;j>=0ll;j--) {
            if (xora[j] == 1LL && ((x >> j) & 1LL) == 1LL) {
                ok = 0;
                break;
            } 
        }
        // if(okk)break;
        i64 j = 0;
        // de(x)
        for (;x;j++) {
            x /= 2;
        }
        xora[j - 1] = 1LL; //取最高位
        // de(x)deb(j)
    }
    cout << ((ok) ? "YES" : "NO") << endl;
}
// 2025.07.17——14:40:23 wa
// 2025.07.17——15:08:16 wa
// 2025.07.17——15:16:46 accpted
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