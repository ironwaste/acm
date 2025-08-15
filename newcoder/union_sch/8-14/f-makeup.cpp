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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


// 补题——题目链接: https://ac.nowcoder.com/acm/contest/108307/F
// 网址：
// 2025.08.14——22:28:52 start
// 2025.08.14——22:50:23 end
// 2025.08.15——21:20:32 start
// 2025.08.15——21:48:19 wa 
// 2025.08.15——22:06:16 当 答案为0的情况下没进行特判

/*
 *
 *
 *
*/
struct Seg {
    i64 num, id;
};
const i64 N = 2e5 + 10;
const i64 M = 1e6 + 10;
Seg seg[N << 2];
i64 tag[N << 2];
#define ls (p<<1)
#define rs (p<<1|1)

void up(i64 p) {
    if (seg[ls].num < seg[rs].num)
        seg[p] = seg[rs];
    else
        seg[p] = seg[ls];
}
void pd(i64 p) {
    if (tag[p] != 0) {
        // ls
        seg[ls].num += tag[p];
        tag[ls] += tag[p];
        //rs
        seg[rs].num += tag[p];
        tag[rs] += tag[p];

        tag[p] = 0;
    }
}
void build(i64 p, i64 s, i64 t) {
    tag[p] = 0;
    if (s == t) {
        seg[p].num = 0;
        seg[p].id  = s;
        tag[p] = 0;
        return;
    }

    i64 mid = s + ((t - s)>> 1);
    build(ls, s, mid), build(rs, mid + 1, t);
    up(p);
}
void add(i64 p, i64 s, i64 t, i64 l, i64 r,i64 x) {
    if (l <= s && t <= r) {
        seg[p].num += x;
        tag[p] += x;
        return;
    }
    i64 mid = s + ((t - s)>> 1);
    pd(p);
    
    if (l <= mid) add(ls, s, mid, l, r, x);
    if (r >  mid) add(rs, mid + 1,t, l, r, x);
    up(p);
}

Seg Max(Seg a, Seg b) { return (a.num < b.num) ? b : a; }
Seg qry(i64 p, i64 s, i64 t, i64 l, i64 r) {
    if (l <= s && t <= r) {
        return seg[p];
    }
    i64 mid = s + ((t - s) >> 1);
    pd(p);
    Seg res,tmp;
    res.num = -1, res.id = -1;
    tmp.num = -1, tmp.id = -1;
    if (l <= mid) res = qry(ls, s, mid, l, r);
    if (r > mid) {tmp = qry(rs, mid + 1, t, l, r);}
    return Max(res,tmp);
}
#undef ls
#undef rs

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n+1,0);
    vector<i64>nxt(n+1, 0),lst(M,0);
    map<i64, i64>mpid;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (mpid.count(a[i])) {
            i64 id = mpid[a[i]];
            // 前一个
            lst[a[i]] = max(lst[a[i]], (i64) (i));
            nxt[id] = i;
            
        }
        mpid[a[i]] = i;
        // de(i);
    }
    build(1, 1, n );
    i64 ansl = 0;
    Seg ans;
    ans.num = 0, ans.id = 0;
    set<i64>st;
    for (int i = 1;i < n - 1;i++) {
        i64 v = a[i];
//         de(i)de(v)
        if (st.count(v) && nxt[i]) {
            i64 ed = nxt[i];
            // if (ed == 0)ed = n;
//             de(ed);
            if (i + 2 <= ed)
                add(1, 1, n, i + 2, ed, -1);
        } else if (nxt[i] && lst[v]) {
//             de(nxt[i])de(lst[v]);
            if (nxt[i] + 1 <= lst[v])
                add(1, 1, n, nxt[i] + 1, lst[v], 1);
        }
        Seg res = qry(1, 1, n, i + 2, n);
        if (res.num > ans.num) {
            ansl = i + 1;
            ans = Max(ans, res);
        }
//         de(res.id)de(res.num);
//         de(ans.id)deb(ans.num);
        st.insert(v);
    }
    if (ans.num == 0) {
        ansl = 2, ans.id = 3;
    }
    cout << ans.num << endl << ansl << " " << ans.id << endl;
}

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