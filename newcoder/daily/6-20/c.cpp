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

// 双指针 ？ 双指针的条件现在有点模糊了
// 我记得是 ： 单调递增，且最终结果只要一个区间的情况下才可以。

using pii = pair<int, int>;
using pll = pair<i64, i64>;


/*
    for(int i = 0;i < n;i ++){
        for(int j = i + 1;j < n;j ++){
            sum += s[i] > s[j]
        }
    }

    等效于
    从 0 到  n 中有多少个 大于的  

*/

// 先计算出 每一个位置 对于每一个小写字母来说，前面所有大于它的数量 
// 计算前缀和
// 再根据 每一位上的 字母是什么 而后将最后的结果数组进行求前缀和


void solve() {
    string s;
    i64 x,n;
    cin >> s >> x;
    x = s.size();
    vector<i64>ans(n, 0),cnt(26,0);
    vector<vector<i64> >a(26, vector<i64>(n, 0));


    i64 res = x,i = 0,j = 0;
    while (i < n) {
        
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}