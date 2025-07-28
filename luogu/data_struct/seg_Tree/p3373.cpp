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
/* https://www.luogu.com.cn/problem/P3373
 *
 * 题目意思：进行两种操作 并且还有模数的存在
 * 1、 进行区间 乘 x
 * 2、 进行区间 加 x
 * 3、求出区间和
 *
 * 需要判断 乘和 加之间的时间顺序
*/
const int N = 1e5 + 10;
i64 seg[4 * N], lazy_add[4 * N], lazy_mul[4 * N] = {1};
i64 mod;
vector<i64>a;
// 建树都是一样的
void build(i64  s, i64 t, i64 p) {
    lazy_mul[p] = 1LL;
    if (s == t) {
        seg[p] = a[s];
        return;
    }
    i64 mid = s + ((t - s) >> 1);
    build(s, mid, 2 * p), build(mid + 1, t, 2 * p + 1);
    seg[p] = (seg[2 * p + 1] + seg[2 * p]) % mod;
}

void upd_add(i64 l,i64 r,i64 s,i64 t,i64 x,i64 p) {
    if (l <= s && t <= r) {
        i64 len = t - s + 1LL;
        (seg[p] += x * len % mod) %= mod;
    }
    i64 mid = s + ((t - s) >> 1);
    i64 len1 = mid - s + 1LL, len2 = t - mid;

    if (lazy_add[p] && s!= t ) {
        (lazy_add[p * 2] += lazy_add[p]) %= mod;
        (lazy_add[p * 2 + 1] += lazy_add[p]) %= mod;
        (seg[p * 2] += len1 * lazy_add[p] % mod) % mod;
        (seg[p * 2 + 1] += len2 * lazy_add[p] % mod) % mod;
        lazy_add[p] = 0;
    }
    if (l <= mid) { upd_add(l, r, s, mid, x, 2 * p); }
    if (r > mid) { upd_add(l, r,mid+1,t, x, 2 * p + 1); }
    seg[p] = (seg[p * 2] + seg[p * 2 + 1]) % mod;
}
void upd_mul(i64 l,i64 r,i64 s,i64 t,i64 x,i64 p) {
    if (l <= s && t <= r) {
        (seg[p] *= x) %= mod;
        (lazy_add[p] *= x) %= mod;
        return;
    }
    i64 mid = s + ((t - s) >> 1);
    // 当乘法的时候 其更改 加的值该怎么更改呢？？
    if ((lazy_add[p] || lazy_mul[p] != 1)s != t) {
        (seg[p * 2] = (seg[p * 2]  + lazy_add[p])%mod * x %mod) %= mod;
        (seg[p * 2 + 1] = (seg[p * 2 + 1]  + lazy_add[p])%mod * x %mod) %= mod;
        lazy_add[p * 2] += lazy[p]

    }
    if (l <= mid) { upd_add(l, r, s, mid, x, 2 * p); }
    if (r > mid) { upd_add(l, r,mid+1,t, x, 2 * p + 1); }
    seg[p] = (seg[p * 2] + seg[p * 2 + 1]) % mod;
    
}



void solve(){

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