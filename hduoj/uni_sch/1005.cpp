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

// 2025.07.18——14:09:10
// 2025.07.19——13:43:46
/*
 
 * 思路： 我们需要遍历的时候需要保证其最小值
 * 所以可以使用 优先队列保证其最小值，
 * 对于每一个遍历到的点，我们需要存储其入边颜色和点
 * 由于是无向图，所以，在判断的时候我们需要将经过的点，当经过两次的时候
 * 其才是最终的不需要被再次经过的点，该点代表的是，点和颜色c两种特征值合并的点
 *
 * 一开始卡住我的地方就是，如何保存一个点一以及其相链接的所有的协会一样的点，
 * 然后我想到的办法是在bfs中，当遇到一个点的时候，使用dfs将剩余的所有的点拼接到一起
 * 
 *
 * wll方法：确实很方便啊
 * 使用 指针 的方式，进行缩点，使用排序将协会颜色相同的点放在一起
 *
*/

void solve() {
    i64 n,m;
    cin >> n >> m;
    vector<pll>g[n + 10];
    for (int i = 0;i < n;i++) {
        i64 u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({ v,c });
        g[v].push_back({ u,c });        
    }
    map<pll, i64>mpc;
    priority_queue<array<i64, 3>, vector<array<i64, 3>, greater<array<i64 , 3>> > >q;
    q.push({ 0,1,-1 });
    mpc
    while (!q.empty()) {



    }





}


int main() {
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