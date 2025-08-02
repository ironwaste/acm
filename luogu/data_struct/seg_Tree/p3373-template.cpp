#include<bits/stdc++.h>
#define i64 long long
#define de(x) cerr<<#x << " " <<x <<" "

using namespace std;
const int N = 1e5 + 10;
const i64 n4 = N * 4LL;
i64 mod;
i64 seg[n4], lazy_add[n4], lazy_mul[n4];
vector<i64>sg;

void build(i64 s, i64 t, i64 p) {

    lazy_mul[p] = 1, lazy_add[p] = 0;
    // 初始化懒惰标记
    if (s == t) {
        seg[p] = sg[s] % mod;
        return;
    }
    i64 mid = s + (t - s >> 1);
    i64 lp = p * 2LL,rp = p * 2 + 1;
    build(s, mid, lp), build(mid + 1, t,rp);
    seg[p] = (seg[lp] + seg[rp]) % mod;
}

void push(i64 s, i64 mid, i64 t, i64 p) {
    // 当所有的懒惰标记 都是初始值的情况下
    if (lazy_add[p] == 0 && lazy_mul[p] == 1) { return; }
    i64 len1 = (mid - s + 1) % mod, len2 = (t - mid);
    i64 lp = p * 2, rp = p * 2 + 1;
    // 更新左儿子 lp 的区间和 和 懒惰标记
    seg[lp] = (seg[lp] * lazy_mul[p] % mod + lazy_add[p] * len1 % mod )% mod;
    lazy_mul[lp] = lazy_mul[lp] * lazy_mul[p] %mod; 
    lazy_add[lp] = (lazy_add[lp] * lazy_mul[p] % mod + lazy_add[p] ) % mod;

    // 更新右儿子 rp 的区间和 和 懒惰标记
    seg[rp] = (seg[rp] * lazy_mul[p] % mod + lazy_add[p] * len2 % mod )% mod;
    lazy_mul[rp] = lazy_mul[rp] * lazy_mul[p] %mod; 
    lazy_add[rp] = (lazy_add[rp] * lazy_mul[p] % mod + lazy_add[p] ) % mod;

    // 复原该层懒惰标记 lazy 
    lazy_mul[p] = 1, lazy_add[p] = 0;
}


void add(i64 l, i64 r, i64 s, i64 t, i64 x, i64 p) {
    
    if (l <= s && t <= r) {
        //找到了相关区间之后 将该区间的seg 值进行更改，再将该区间的 lazy 值进行标记
        i64 len = t - s + 1;
        (seg[p] += x * len % mod) %= mod;
        (lazy_add[p] += x) %= mod;
        // 加和 对于乘法 懒惰标记没有 相关关系
        return;

    }
    i64 mid = s + (t - s >> 1);
    i64 lp = 2 * p, rp = 2 * p + 1;
    push(s, mid, t, p);

    if (l <= mid)add(l, r, s, mid, x, lp);
    if (r > mid)add(l, r, mid + 1,t, x, rp);
    seg[p] = (seg[lp] + seg[rp]) % mod;
}

void mul(i64 l, i64 r, i64 s, i64 t, i64 x, i64 p) {
    
    if (l <= s && t <= r) {
        //找到了相关区间之后 将该区间的seg 值进行更改，再将该区间的 lazy 值进行标记
        // i64 len = t - s + 1;
        (seg[p] *= x ) %= mod;
        (lazy_add[p] *= x) %= mod;
        (lazy_mul[p] *= x) %= mod;
        // 加和 对于乘法 懒惰标记没有 相关关系
        // 但是 乘法对于加法 的懒惰 标记 有相关关系
        return;

    }
    i64 mid = s + (t - s >> 1);
    i64 lp = 2 * p, rp = 2 * p + 1;
    push(s, mid, t, p);

    if (l <= mid)mul(l, r, s, mid, x, lp);
    if (r > mid)mul(l, r, mid + 1,t, x, rp);
    seg[p] = (seg[lp] + seg[rp]) % mod;
}
i64 gsum(i64 l,i64 r,i64 s,i64 t,i64 p) {
    if (l <= s && t <= r) {
        return seg[p] % mod;
    }
    i64 res = 0;
    i64 mid = s + (t - s >> 1);
    i64 lp = 2 * p, rp = 2 * p + 1;
    push(s, mid, t, p);

    if (l <= mid) (res += gsum(l, r, s, mid, lp)) %= mod;
    if (r > mid) (res += gsum(l, r,mid+1,t, rp)) %= mod;
    return res;
}



int main(){
    i64 n, q;
    cin >> n >> q >> mod;
    sg.resize(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        cin >> sg[i];
    }
    i64 s = 1, t = n, p = 1;
    build(s, t, p);
    while (q--) {
        i64 op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            mul(l, r, s, t, x, p);
        } else if (op == 2) {
            cin >> l >> r >> x;
            add(l, r, s, t, x, p);
        } else {            
            cin >> l >> r;
            // add(l, r, s, t, x, p);
            cout << gsum(l, r, s, t, p) << endl;
        }


        
    }


    return 0;
}