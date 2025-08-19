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

// 2025.08.17——19:43:37
// 2025.08.17——20:04:38 中止一下
// 2025.08.17——20:37:48 开始
/*
 *
 *
*/

const i64 N = 1e5 + 10;
struct Seg {
    i64 id, v;
};
Seg seg[N << 2];
vector<i64>diff;
#define ls p<<1
#define rs p<<1|1
#define md (s + (t - s >> 1)) 
void up(int p) {
    if (seg[ls].v > seg[rs].v) {
        seg[p] = seg[ls];    
    } else {
        seg[p] = seg[rs];    
    }
}
void build(i64 s, i64 t, int p) {
    if (s == t) {
        seg[p].v = diff[s];
        seg[p].id = s;
        return;
    }
    de(s)de(t)deb(p)
    i64 mid = md;
    build(s, mid, ls), build(mid + 1, t, rs);
    up(p);
}

void modify(i64 p, i64 s, i64 t, i64 l, i64 x) {
    if (s == t) {
        seg[p].v = x;
        return;
    }
    i64 mid = md;
    if (l <= mid)modify(ls, s, mid, l, x);
    if (l >  mid)modify(ls, mid + 1, t, l, x);
    up(p);
}

#undef ls 
#undef rs 
#undef md 

void solve() {
    int n, mod, q;
    cin >> n >> mod >> q;
    multiset<i64>s;
    vector<i64>a(n + 1,0);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s.insert(mod - a[i]);
    }
    diff.resize(n + 1);
    for (int i = n;i > 0;i--) {
        diff[i] = a[i] - a[i - 1];
    }
    build(1, n, 1);

    while (q--) {
        int op,x,k,i;
        cin >> op;
        i64 v;
        if (op == 1) {
            cin >> i >> x;
            a[i] = x;
            modify(1, 1, n, i, a[i]-a[i-1]);
            if(i!=n)modify(1, 1, n, i, a[i+1]-a[i]);
            v = mod - a[i];
            s.erase(s.lower_bound(v));
            s.insert(mod - x);
        } else {
            cin >> k;
            if (*s.begin() <= k || (-seg[1].v) <= k) {
                cout << "YES" << endl;
            } else {
                cout << "NO";
            }
        }
    }



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