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

// 2025.07.27——22:40:21
// 2025.07.27——23:18:31 TLE???? while 里面的ifelse判断少写一个操作。。。
// 2025.07.27——23:19:40 accpted
/*
 * 给出一个排列
 * 坏数组的条件 ：
 * 1、连续的的五个数组，严格递增
 * 2、连续的的五个数组，严格递减
 *
 * 给定 n个回合 ，在n个回合中 必须移除 p中 最左边 或者 最右边的剩余元素，
 * 产生 qi  为第i个回合时移除的元素
 *
 * 使得 q数组 时好数组
 *
 * 判断前一个元素 的值 ，以及之前的趋势 是上升还是下降
 * 选 两个数字 绝对值最大的一个。
 * 好像不对 ， 当n特别大的时候，就会产生 如 9000   140004 13003 12002  11001  10000
 * 这样的情况当pre值 为 9001 就会导致有问题
 *
 * 当前趋势 增加
 *     l 趋势 增加 r趋势也是增加，那么就先选 增加多的再选增加少的自然就形成 好数组了
 *      然后趋势就变成了 减少
 *      l 增加 ，r 减少 那么就直接 选择r 趋势也直接变成减少
 *     r增加 l减少 反之亦然
 *      l 减少 r 也减少的情况下 先选减少的多的

 *
*/

i64 tend(i64 x, i64 y) {
    if (x > y)return 1;
    return -1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    s = "LL";
    i64 pv = a[1],ppv = a[0],t = tend(a[1],a[0]);
    int l = 2, r = n - 1;
    auto ladd = [&]()->void {
        s += "LR";
        pv = a[r];
        ppv = a[l];
        t = tend(a[r], a[l]);
        l++;
        r--;
        };
    auto radd = [&]()->void {
        s += "RL";
        pv = a[l];
        ppv = a[r];
        t = tend(a[l], a[r]);
        r--;
        l++;
        };
    while (l < r) {
        if ((a[l] > pv && a[r] > pv) || (a[l] < pv && a[r] < pv)) {
            if (abs(a[l] - pv) > abs(a[r] - pv)) {
                ladd();
            } else {
                radd();
            }
        } else if(t == -1){
            if (a[l] > pv) {
                ladd();
            } else {
                radd();
            }
        } else {
            if (a[l] > pv) {
                radd();
            } else {
                ladd();
            }
        }

    }
    // de(l)deb(r)
    if (l == r) {
        s += 'L';
    }

    cout << s << endl;

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