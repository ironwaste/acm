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


// 最大前缀后缀 用于求两区间的 最大值k

// 核心问题在于：我们如何判断，三个区间中最左区间和中间区间
// 这两个区间，是否其中位数 <= k 存在
// 问题 ： 如果我们直接根据是否有小于等于k的值存在 ，并且贪心的去选择，那么
// 由于第一个区间可能存在空余，比如加入后一个大于k的值的时候其中位数依然是小于等于k的但是
// 可能由于这一个值的多少导致 第二个区间内由存在解变成无解
// 假设 0 为 小于k的值， 而1为大于 k 的值
// 举例 ： 0 1 1 0 1 1 
// [0] [1 1 0] 则无法判断
// [0 1] [1 0] 则第二个区间存在解 ，那么该如何去做判断？ 
// 核心问题

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>a(n),b(n);

    for (auto& x : a) {
        cin >> x;
        if (x > k) { x = 1; }
        else {x = -1;}
    }
    for (int i = 0;i < n;i ++) {
        b[i] = a[n - i - 1];
    }
    vector<i64>pre(n), suf(n);
    partial_sum(all(a), pre.begin());
    partial_sum(all(b), suf.begin());

    i64 ok = 0;
    auto check = [&](vector<i64>t) -> int{
        i64 sz = t.size(),cnt = 0,pre = 0;
        for (int i = 0;i < sz - 1;i ++) {
            if (pre >= t[i]) {
                cnt++;
                pre = t[i];
                // 判断一下奇偶 状态
                if (i % 2 == 0 && t[i + 1] == (t[i] + 1LL)) {
                    pre = t[++i];
                }
                if (cnt >= 2) { return 1; }
            }
        }
        return 0;
        };

    ok |= check(pre);
    // deb(ok)
    ok |= check(suf);
    // deb(ok)

    i64 l = -1,r = -1;
    for (int i = 0;i < n;i ++) {
        if (pre[i] <= 0) {
            l = i;break;
        }
    }
    
    for (int i = 0;i < n;i++) {
        if (suf[i] <= 0) {
            r = n - i - 1;break;
        }
    }

    if (l + 1 < r && l != -1 && r != -1) {
        ok |= 1;
    }
    // de(l)deb(r)
    // deb(ok)

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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