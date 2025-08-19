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


// 补题——题目链接:
// 网址：https://codeforces.com/contest/2123/problem/E
// 2025.08.19——19:50:53
// 2025.08.19——23:19:34 accpted
/*
 *
 * 从其实开始设想问题的解法都是反的，我没有想到
 * 其根据mex的最大值确定来判断，减少多少元素可以实现 mex = i 的情况
 *
 * 此处的mex 是mex的最大值
 * 而我的想法是在找到了当选择1 到 mex 个元素 其个数就是 1 到 mex + 1
 * 但是会有特例就是只有同一种数字的时候，也就是 当存在 0 0 0 0 的时候其值就只有1 而不会增加
 *
 * 而后其自然的想到，如果删除k个元素 mex 能为 i 的情况下  那么 i的个数不能够超过k
 * 且 i <= n - k 只有这两个条件
 * 
 * 我们可以写一个集合，然后集合里面存的是 mex 的种类以及值，
 * 当我们删除k个 元素的 时候 ，所有的 个数 大于 n - k 的 值都不应该存在
 * 而且所有小于 mex 并且其出现个数 少于等于 k 个的时候 才能够算作于解集中的一个
 *
 * 从 k = 1 到 2 的情况下 ， 所有 
*/
void solve() {
    int n;
    cin >> n;
    vector<i64>a(n),cnt(n+1,0);
    for (auto& x : a) { cin >> x;cnt[x]++; }
    map<i64,vector<i64> > f;
    i64 mex = 0;
    for (int i = 0;i <= n;i++) {
        
        i64 v = cnt[i];
        if (v) {
            f[v].push_back(i);
            if (mex == i) {mex++;}
        }
    }
    set<i64>s;
    s.insert(mex);

    for (int i = 0;i <= n;i++) {
        s.erase(n - i + 1);
        for (auto x : f[i]) {
            if (x > mex) { continue; }
            s.insert(x);
        }
        cout << s.size() << " ";
    }cout << endl;
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