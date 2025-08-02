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

// 2025.08.02——17:22:54
// 2025.08.02——17:34:33 accpted
/* https://www.luogu.com.cn/problem/P1816
 * 题目意思： 求区间最小值
 * 没有值的修改 ， 所以 其只需要建树 或者转化为 RMQ 问题进行求解即可
 * RMQ 问题 区间最大最小值
 * 
 */
const int  N = 1e5 + 10;
const int n4 = N * 4 + 10;
i64 seg[n4];
vector<i64>sg;
void build(i64 s,i64 t,i64 p) {
    if (s == t) {
        seg[p] = sg[s];
        return;
    }
    i64 mid = s + (t - s >> 1);
    i64 lp = p * 2, rp = p * 2 + 1LL;

    build(s, mid, lp), build(mid + 1, t, rp);
    seg[p] = min(seg[lp] , seg[rp]);
}

i64 qry(i64 l,i64 r,i64 s,i64 t,i64 p) {
    if (l <= s && t <= r) {
        return seg[p];
    }
    i64 res = LLONG_MAX;
    i64 mid = s + (t - s >> 1);
    i64 lp = p * 2, rp = p * 2 + 1LL;
    if (l <= mid) res = min(res, qry(l, r, s, mid, lp));
    if (r > mid) res = min(res, qry(l, r, mid + 1,t , rp));
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    sg.resize(n + 1);
    for (int i = 1;i <= n;i++) { cin >> sg[i]; }
    i64 s = 1, t = n, p = 1;
    build(s, t, p);
    while (m--) {
        i64 l, r;
        cin >> l >> r;
        cout << qry(l, r, s, t, p) << " ";
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