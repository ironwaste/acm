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

// 2025.07.31——12:01:37
// 2025.07.31——12:36:07
/* 发现题目 看错了，其区间加和是 有序区间
 * 而 查询是无序区间求和
 *
 *
*/
const int N = 4e5 + 10;

i64 seg[N], a[N], lazy[N];
void build(i64 s, i64 t, i64 p) {
    if (s == t) {
        seg[p] = a[s];
        return;
    }

    i64 mid = s + (t - s >> 1);
    build(s, mid, 2 * p), build(mid + 1, t, 2 * p + 1);
    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}
void upd(i64 l, i64 r, i64 s, i64 t, i64 x,i64 p) {
    if (l <= s && t <= r) {
        i64 len = t - s + 1;
        seg[p] += x * len;
        lazy[p] += x;
        return;
    }

    i64 mid = s + (t - s >> 1);
    i64 len1 = mid - s + 1, len2 = t - mid;
    if (lazy[p] != 0 && s != t) {
        seg[2 * p + 1] += lazy[p] * len2;
        seg[2 * p] += lazy[p] * len1;
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }
    if (l <= mid)upd(l, r, s, mid, x, 2 * p);
    if (r > mid)upd(l, r, mid + 1, t, x, 2 * p + 1);
    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

i64 getsum(i64 l,i64 r ,i64 s, i64 t,i64 p) {
    if (l <= s && t <= r) {
        return seg[p];
    }
    i64 res = 0;
    i64 mid = s + (t - s >> 1);
    i64 len1 = mid - s + 1, len2 = t - mid;
    if (lazy[p] != 0) {
        seg[2 * p + 1] += lazy[p] * len2;
        seg[2 * p] += lazy[p] * len1;
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }
    if (l <= mid) { res += getsum(l, r, s, mid, 2 * p); }
    if (r > mid) { res += getsum(l, r, mid + 1,t, 2 * p); }
    return res;
}


void solve() {
    i64 n,q;
    cin >> n >> q;
    vector<i64>p(n + 1);
    i64 prexor = 0;
    for (int i = 1;i <= n;i++) {cin >> p[i];}
    build(1, n, 1);
    // for (int i = 1;i <= n;i ++) {
    //     de(i)deb(a[i])
    // }
    i64 op, l, r, x;
    while (q --) {
        cin >> op;
        deb(op)
        if (op == 1) {
            cin >> l >> r >> x;
            de(l)de(r)deb(x)
            upd(l, r, 1, n, x, 1);
        } else {
            cin >> l >> r;
            i64 v = getsum(l, r, 1, n, 1);
            cout << (prexor ^ v) << endl;
            prexor = v;
            deb(v)
        }
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}