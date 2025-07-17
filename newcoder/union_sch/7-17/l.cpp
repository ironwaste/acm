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

// 2025.07.17——16:21:24
/*
 * 会成为很多个环
 * 
 * 如果总数为偶数的话,则最后 剩余两位 是未婚的.且奇数环最多只有两个
 *
 * 其次是环,如果环是奇数的,那么最后会剩余一个 无法结婚的
 * 奇数环最后会产生 1,2,3,4,5
 * 产生 1,2;3,4
 * 2,3;4,5;
 * 5,1;2,3;
 * 三种情况
 *
 * 1,2,3,4,5,6,7
 * 1,2;3,4;,5,6; -> 7未结婚
 * 2,3;4,5;6,7;  -> 1未结婚
 * 3,4;5,6;7,1;  -> 2 未结婚
 * 4,5;6,7;1,2;  -> 3未结婚
 * n种情况
 * 
 * 偶数环存在 1,2,3,4,5,6
 * 1,2;3,4;5,6;
 * 2,3;4,5;6,1;
 * 只存在俩种情况
 *
 * 奇数链 有两种情况
 * 偶数链 有一种情况
 * 
 * 被拆一个
 * 偶数 -> 一个奇数链 
 *
 * 奇数 -> 一个偶数链
 * 
 * 被拆两个
 * 偶数 -> 两个奇数链
 *
 * 偶数 -> 两个偶数链
 *
 * 奇数 -> 一个偶数链 + 一个奇数链
 *
 */

void solve(){
    i64 n;
    cin >> n;
    vector<i64>a(n);
    vector<i64>fa(n, 0);
    // iota(all(fa), 0);
    for (int i = 0;i < n;i++) { fa[i] = -1; }
    for (auto& x : a) { cin >> x;x--; }
    auto fd = [&](auto self, i64 u)->i64 {
        if (fa[u] == -1)return u;
        return fa[u] = self(self, fa[u]);
        };
    void uni = [&](i64 x, i64 y)->void {
        i64 nx = fd(fd, x), ny = fd(fd, y);
        if (ny < nx) { swap(nx, ny); }
        if (nx == ny)return;
        fa[nx] += fa[ny];
        fa[ny] = nx;
        };

    for (int i = 0;i < n;i++) {
        uni(a[i], i);
    }
    vector<i64>cir_odd, cir_even;
    for (int i = 0;i < n;i ++) {
        if (fa[i] < 0) {
            i64 v = -fa[i];
            if (v % 2 == 1) {
                cir_odd.push_back(v);
            } else {
                cir_even.push_back(v);
            }
        }
    }
    i64 odd = cir_odd.size();
    // if (odd -= )




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