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

// 2025.07.28——21:00:25
// 2025.08.02——14:38:36 wa 没理解清楚
// 2025.08.02——15:08:31 accpted
/* https://www.luogu.com.cn/problem/P3373
 *
 * 题目意思：进行两种操作 并且还有模数的存在
 * 1、 进行区间 乘 x
 * 2、 进行区间 加 x
 * 3、求出区间和
 *
 * 需要判断 乘和 加之间的时间顺序
 *
 * 总结 我们通过 在pushdown 的过程中，当 因为 加之间是没有 先后顺序的差别的
 * 且 乘之间也是没有先后顺序的差别的，
 * 但是 加和 乘 之间是有先后顺序的差别的
 *
 * 首先线段树的操作原理是 ， 当没有lazy_tag 的情况下
 * 通过找到最大的符合的区间， 对于该区间 进行 加和 加x和长度相乘进行加和
 * 而区间乘 ，则是将该区间内 原本的区间和 直接乘上 x即可
 *
 * 当存在lazy_tag 的情况下，
 * 第一次 进行 区间操作 在找到最底层 且 极大的区间的情况下 对于区间和的值进行加和
 * 然后将该层的 lazy_tag 加上x值 用于之后的push down
 *
 * 而后第二次 进行区间操作的情况下 当在pushdown 的过程中 遇到了lazy_tag 的标记
 * 那么将该 lazy_tag 的标记进行计算 ，而在计算过程中，这一次的区间操作值并不进行操作
 * 而是到了最低极大 区间的时候才进行操作，
 * 而真正进行操作的是 这一层 的两个lazy tag 标记 应该分开来 算，对于 下一层seg[] 中原本的区间和
 * 乘以 lazy_mul[] 中的值 而后在使得 下一层的lazy_add[] 乘以 这层的lazy_mul
 * 而下一层的 lazy_add[] 值 则再加上该层的 lazy_add[]
 *
 * 这样是保证正确的，因为 其在线询问，所有，当每一次的查询，或者再pushdown 的过程中
 * 无论其先后顺序 ， 之前所有的lazy_tag 只会存在于该次的 最低极大区间 之后或者同一层
 * 这样就 保证了 其乘法 和 加法的值 在于顺序关系上的 正确性
 *
 * 在这里我的问题是 ，当我 第一次进行了一个小区间的加或者 乘， 但是再而后的一次大区间的加或者乘运算后
 * 导致了某一次 或者说 某一区间的 值被进行了多次 加和或者被乘
 *
 * 因为我们在求和 、 区间加 、 区间乘操作的 pushdonw的过程中
 * 同一层上的lazy tag是不会 相互作用的 根据这个性质 我们在有序的操作中
 *
 * 还有就是当时想到了 当乘被模除为 0 情况下 是否会导致 之后的乘法都没有办法进行乘的问题，
 * 比如说 其中 加的lazy 是有值的 但是 乘是没有值的 那么之后的 ，因为 加 和 和的运算
 * 是分开和 乘的值进行运算的， 当我们前一次 乘的lazy 变成了0
 * 而后一次 我们再进行加的时候， add函数 会将 lazy 先乘到底
 * 而后再将 底部极大区间的 值进行加和 加和结束之后 将其向上递归保证该值被加上。
 *
 * 所以当时的思维误区在于 ，我认为 线段树内的区间值 是根据每一层pushdown 来进行更新的
 * 但是其实不是，而是找到相应的区间之后 加和 然后留下lazy tag  并且向上进行回溯更新
 *
*/
const int N = 1e5 + 10;
i64 seg[4 * N], lazy_add[4 * N], lazy_mul[4 * N];
i64 mod;
vector<i64>a;
// 建树都是一样的

void build(i64 s, i64 t, i64 p) {
    lazy_add[p] = 0;
    lazy_mul[p] = 1;
    if (s == t) {
        seg[p] = a[s];
        return;
    }
    i64 mid = s + (t - s >> 1);
    build(s, mid, p * 2), build(mid + 1, t, p * 2 + 1);
    seg[p] = (seg[2 * p] + seg[2 * p + 1]) % mod;
}

void add(i64 l,i64 r,i64 s,i64 t,i64 x,i64 p) {
    if (l <= s && t <= r) {
        // de(s)deb(t);
        i64 len = (t - s + 1LL) % mod;
        // de(seg[p]);
        (seg[p] += x * len % mod) %= mod;
        (lazy_add[p] += x) %= mod;
        // de(p)de(len)de(seg[p])deb(lazy_add[p]);
        return;
    }
    i64 mid = s + (t - s >> 1);
    i64 len1 = mid - s + 1LL, len2 = t - mid;
    if (lazy_add[p] || lazy_mul[p] != 1) {
        seg[2 * p] = (seg[2 * p] * lazy_mul[p] %mod+ lazy_add[p] * len1 % mod) % mod;
        seg[2 * p + 1] = (seg[2 * p + 1] * lazy_mul[p] % mod + lazy_add[p] * len2 % mod) % mod;
        
        (lazy_add[2 * p] = lazy_add[2 * p] * lazy_mul[p] % mod + lazy_add[p]) %= mod;
        (lazy_add[2 * p + 1] = lazy_add[2 * p + 1] * lazy_mul[p] % mod + lazy_add[p]) %= mod;
        

        (lazy_mul[p * 2] *= lazy_mul[p]) %= mod;
        (lazy_mul[p * 2 + 1] *= lazy_mul[p]) %= mod;

        lazy_add[p] = 0;
        lazy_mul[p] = 1;
    }
    if (l <= mid)add(l, r, s, mid, x, 2 * p);
    if (r > mid)add(l, r, mid + 1, t, x, 2 * p + 1LL);
    seg[p] = (seg[2 * p] + seg[2 * p + 1]) % mod;
}

void mul(i64 l,i64 r,i64 s,i64 t,i64 x,i64 p) {
    if (l <= s && t <= r) {
        (seg[p] *= x) %= mod;
        (lazy_mul[p] *= x) %= mod;
        (lazy_add[p] *= x) %= mod;
        return;
    }
    i64 mid = s + (t - s >> 1);
    i64 len1 = mid - s + 1LL, len2 = t - mid;

    if (lazy_add[p] || lazy_mul[p] != 1) {
        seg[2 * p] = (seg[2 * p] * lazy_mul[p] %mod+ lazy_add[p] * len1 % mod) % mod;
        seg[2 * p + 1] = (seg[2 * p + 1] * lazy_mul[p] % mod + lazy_add[p] * len2 % mod) % mod;
        
        (lazy_add[2 * p] = lazy_add[2 * p] * lazy_mul[p] % mod + lazy_add[p]) %= mod;
        (lazy_add[2 * p + 1] = lazy_add[2 * p + 1] * lazy_mul[p] % mod + lazy_add[p]) %= mod;
        

        (lazy_mul[p * 2] *= lazy_mul[p]) %= mod;
        (lazy_mul[p * 2 + 1] *= lazy_mul[p]) %= mod;

        lazy_add[p] = 0;
        lazy_mul[p] = 1;
    }
    if (l <= mid)mul(l, r, s, mid, x, 2 * p);
    if (r > mid)mul(l, r, mid + 1, t, x, 2 * p + 1LL);
    seg[p] = (seg[2 * p] + seg[2 * p + 1] )% mod;
}

i64 gsum(i64 l, i64 r, i64 s, i64 t, i64 p) {
    i64 res = 0;
    if (l <= s && t <= r) {
        return seg[p] % mod;
    }
    i64 mid = s + (t - s >> 1);
    i64 len1 = (mid - s + 1) % mod, len2 = (t - mid) % mod;

    if (lazy_add[p] || lazy_mul[p] != 1) {
        seg[2 * p] = (seg[2 * p] * lazy_mul[p] %mod+ lazy_add[p] * len1 % mod) % mod;
        seg[2 * p + 1] = (seg[2 * p + 1] * lazy_mul[p] % mod + lazy_add[p] * len2 % mod) % mod;
        
        (lazy_add[2 * p] = lazy_add[2 * p] * lazy_mul[p] % mod + lazy_add[p]) %= mod;
        (lazy_add[2 * p + 1] = lazy_add[2 * p + 1] * lazy_mul[p] % mod + lazy_add[p]) %= mod;
        

        (lazy_mul[p * 2] *= lazy_mul[p]) %= mod;
        (lazy_mul[p * 2 + 1] *= lazy_mul[p]) %= mod;

        lazy_add[p] = 0;
        lazy_mul[p] = 1;
    }

    if (l <= mid)res += gsum(l, r, s, mid, p * 2);
    res %= mod;
    if (r > mid)res += gsum(l, r, mid + 1, t, p * 2 + 1);
    return res % mod;
}



void solve() {
    i64 n, q;
    cin >> n >> q >> mod;
    a.resize(n + 1);
    for (int i = 1;i <= n;i++) { cin >> a[i];a[i] %= mod; }
    i64 p = 1, s = 1, t = n;
    while (q--) {
        i64 op;
        i64 x, y, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            mul(x, y, s, t, k, p);
        } else if (op == 2) {
            cin >> x >> y >> k;
            add(x, y, s, t, k, p);
        } else {
            cin >> x >> y;
            cout << gsum(x, y, s, t, p) <<endl;
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