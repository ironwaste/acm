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

// 2025.07.28——15:22:11
/*
 * 题目意思，给出一个树，然后给出相应的 两个值x 和 y 边权
 * x代表 当断开 uv 之间的边，那么u所在的 子树中 含有 0x个 或者 1x个
 * y 则代表 v 所在子树的 0 或者 1 的个数
 *
 * 那么先判断是否有解 ，
 * 因为一条边 中 x 和 y 的值，
 * 应该等于 u点其他子节点的0的值或者1的值
 * 的 所有加和数，
 * y 应该等于 其他 所有 v的子节点 的 0 或者1 的个数的和
 * 
 * 所以需要维护的值 有 每个节点 中 恰好存在的个数
 * 
 *
*/

void solve(){

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