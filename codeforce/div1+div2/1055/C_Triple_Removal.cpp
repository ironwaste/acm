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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.10.03——23:45:02
/*
 * 判断 是否有相邻的相同的数字
 * 统计区间0 和 1 的个数
 *
*/
const i64 N = 3e5 + 10;
i64 tree0[N],tree1[N];
i64 lowbit(i64 x) {
    return x & (-x);
}
void add0(i64 x) {    
    for (;x < N;x += lowbit(x)) {
        tree0[x]++;
    }
}
void add1(i64 x) {    
    for (;x < N;x += lowbit(x)) {
        tree1[x]++;
    }
}
i64 qry0(i64 x) {
    i64 res = 0;
    for (;x;x -= lowbit(x)) {
        res += tree0[x];
    }
    return res;
}
i64 qry1(i64 x) {
    i64 res = 0;
    for (;x;x -= lowbit(x)) {
        res += tree1[x];
    }
    return res;
}
i64 qry0(i64 l, i64 r) {
    return qry0(r) - qry0(l - 1);
}
i64 qry1(i64 l, i64 r) {
    return qry1(r) - qry1(l - 1);
}

void init(i64 x) {
    for (int i = 0;i <= x;i ++) {
        tree0[i] = 0;
        tree1[i] = 0;
    }
}


void solve() {
    i64 n,q;
    cin >> n >> q;
    init(n + 10LL);
    vector<i64>a(n + 1);
    a[0] = -1;
    vector<i64>idx;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] == 1) {
            add1(i);
        } else {
            add0(i);
        }
        if (a[i] == a[i - 1]) {
            idx.push_back(i - 1);
        }
    }

    // q (log n + log n+ log n)
    i64 sz = idx.size();
    while (q--) {
        i64 l, r;
        cin >> l >> r;
        i64 cnt0 = qry0(l, r),cnt1 = qry1(l, r);
        if ( ((cnt0 % 3) != 0) || ((cnt1 % 3 )!= 0) ) {
            cout << -1 << endl;
            continue;
        }
        cnt0 /= 3, cnt1 /= 3;
        auto id = lower_bound(all(idx), l);
        // if(idd >= sz)
        if (id == idx.end() || (*id) + 1LL > r) {
            cout << cnt0 + cnt1 + 1 << endl;
        } else {
            cout << cnt0 + cnt1 << endl;
        }
    }
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