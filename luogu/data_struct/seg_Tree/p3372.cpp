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

// 2025.07.28——20:02:41
// 2025.07.28——21:00:31 accepted
/* https://www.luogu.com.cn/problem/P3372
 *
 *
 *
*/
const int N = 2e5 + 10;
i64 seg[4LL * N], lazy[4LL * N];
// 线段树为 一个完全二叉树 
// 所以 其 线段树应该开的数组长度为 应有的长度的
// 2 ^ (logn上取整 + 1LL) - 1LL个 
// 其数组长度的最大值 在 n = 2 ^ x + 1时取到， 其值最大为4 * n - 5;
vector<i64>a;
void build(i64 s, i64 t, i64 p) {
    // 对 [s,t] 区间建立线段树，当前根节点为p
    // p 也就是代表的是 对于线段树数组的 下标
    if (s == t) {
        seg[p] = a[s];
        return;
    }
    i64 mid = s + ((t - s) >> 1LL);
    // 递归建树 -> [s,(s + t) / 2] 和 [(s + t) / 2 + 1, t]两个区间
    // 其中 2 * p 为该节点的左儿子 ，也就是 第一个区间
    // 其中 p * 2LL +1LL  为右儿子

    build(s, mid, p * 2), build(mid + 1, t, p * 2 + 1LL);
    // 当前根节点的值为 左右儿子的和
    seg[p] = seg[p * 2] + seg[p * 2 + 1LL];
}
// 线段树的区间查询
// 
i64 getsum(i64 l,i64 r,i64 s,i64 t,i64 p) {
    i64 sum = 0LL;
    if (l <= s && t <= r) {
        return seg[p];
    }
    i64 mid = s + ((t - s) >> 1LL);
    if (l <= mid) {sum += getsum(l, r, s, mid, p * 2LL);}
    if (r > mid) {sum += getsum(l, r, mid + 1, t, p * 2LL + 1LL);}
    return sum;
}

// 区间修改 和 懒惰标记 
// l r 为需要修改的区间
// c 为 需要增加的值，而 s t为当前区间
// p为根节点
void upd(i64 l, i64 r, i64 c, i64 s, i64 t, i64 p) {
    // 如果当前区间被完全包含那么该区间的值增加
    // 增加 区间长度 * 修改值 以及将该部分的懒惰标记设置为该值
    i64 len = t - s + 1LL;
    if (l <= s && t <= r) {
        seg[p] += (len) * c, lazy[p] += c;
        return ;
    }
    i64 mid = s + ((t - s) >> 1LL);
    i64 len1 = mid - s + 1LL, len2 = t - mid;
    if (lazy[p] != 0 && s != t) {
        seg[p * 2] += lazy[p] * (len1), seg[p * 2 + 1] += lazy[p] * (len2);
        lazy[p * 2] += lazy[p], lazy[p * 2 + 1] += lazy[p];
        lazy[p] = 0;
    }
    if(l <= mid)upd(l, r, c, s, mid, 2 * p);
    if (r > mid) upd(l, r, c, mid + 1LL, t, 2 * p + 1LL);
    seg[p] = seg[2 * p] + seg[2 * p + 1];
    // 这个代码 不能够放在两个递归循环之前
    // 因为放在 之前的话，最后一位在l r 区间内的加和就没有被计算到这一次p之中了
    
}
// 带有懒惰标记的 求和
i64 gsum(i64 l,i64 r,i64 s,i64 t,i64 p) {

    if (l <= s && t <= r) { return seg[p]; }
    i64 mid = s + ((t - s) >> 1);
    i64 len1 = mid - s + 1LL, len2 = t - mid;
    if (lazy[p]) {
        lazy[2 * p] += lazy[p], lazy[2 * p + 1] += lazy[p];
        seg[2 * p] += lazy[p] * len1, seg[2 * p + 1] += lazy[p] * len2;
        lazy[p] = 0;
    }
    i64 sum = 0;
    if (l <= mid)sum += gsum(l, r, s, mid, p * 2);
    if (r > mid)sum += gsum(l, r, mid + 1,t, p * 2 + 1LL);
    return sum;
}



void solve() {
    i64 n, m;
    cin >> n >> m;
    a.resize(n + 1LL);
    for (int i = 1;i <= n;i++) { cin >> a[i]; }
    i64 root = 1 , l =1,r = n;
    build(l, r,root);
    while ( m--) {
        i64 op, x, y, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            upd(x, y, k, l, r, root);
        } else {
            cin >> x >> y;
            cout << gsum(x, y, l, r, root) << endl;
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