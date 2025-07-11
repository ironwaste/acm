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


// 补题——题目链接:https://ac.nowcoder.com/acm/contest/112575/B
// 网址：https://ac.nowcoder.com/discuss/1519571
// 2025.07.12——00:10:59
/*
 * 总结两个函数的用法
 * 1、求一个数二进制1的个数 __builtin_popcountll(x(i64));
 * __builtin_popcount(x(int))
 * 2、以std::__lg是二为底数的对数函数
*/

i64 f(x) {
    return __builtin_popcountll(x);
}
i64 g(x) {
    return __lg(x) - f(x) + 2LL;
}


void solve() {
    // cout << __builtin_popcountll(15LL);
    // std::__lg(x) 以2为底的log数
    

    
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