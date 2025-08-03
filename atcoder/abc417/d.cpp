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

// 2025.08.02——20:29:16
/*
 * 题目意思： 有n个礼物， 礼物有三个参数
 * 1、 p a,b
 * 如果当前值 x 大于等于p 则值增加 a
 * 如果 当前的值 x 小于 p 则值减少 b
 *
 * 然后 给出 q个询问 表示 起始值 x
 *
 * 可能是 前缀和 + 二分 求解？
 *
 * 先对于 a进行前缀和 ，然后根据加和
 *
 * x <= p ----> x + a
 * x > p ----> x - b 或者 0
 *
 * P < B && X <= B则 直接变 0  min(X + P - B,0); 
 * X > P > B  则 其改变值为 B  其剩余值为 P - B
 *
 * 
 * 其实可以直接看成 两部分 一部分 是增加A 的一部分是减少B 的
 *
 * X >= P 
 *
 * prev = hv - A (prev > P <==> hv >= P + A) 
 * 
 * X < P
 * prev = hv + B ? 不确定的
 *
 * 最后应该可以计算出 值在某一个区间内 其和后面的礼物 所产生的交互值
 * 是多少，然后可以将 区间求出来
 * 之后就可以 O（1） 的方式得出结果
 *
 * 也可以接受 N ^ 2 的预处理时间复杂度
 *
 */

void solve(){




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