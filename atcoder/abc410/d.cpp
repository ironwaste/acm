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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii> >g(n);
    vector<vector<i64> >gg(n, vector<i64>(1LL<<10, 0));
    gg[0][0] = 1;
    for (int i = 0;i < m;i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({ v,w });
    }
    queue<pii>q;
    q.push({ 0,0 });

    while (!q.empty()) {
        auto [u, x] = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            i64 nx = w ^ x;
            if (!gg[v][nx]) {
                q.push({ v,nx });
                gg[v][nx] = 1;
            }
        }
    }
    for (int i = 0;i < 1024;i ++) {
        if (gg[n - 1][i] == 1) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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



/*  这是最初版本，一开始没有意识到是 2^10 = 1024 版本
    所以这个我也是有点对于题目数据有些许不敏感了，
    1 << 10 == 1024 不是 2 ^ 30 == 2147483648
    int_max is 2147483647 刚刚好等于 2LL^30-1LL
    将4位数当作10位数，所以确实会觉得这个时间复杂度
    会有点问题

    然后其次的核心代码如下，终止条件在于
    1、当有向图无路可走的时候（无环情况）
    2、（有环情况） 将取n和m的最大值，但是最后结果会T7个数据

    更迭：取 n 和 m 的最小值 会T 6 个数据点
    说明： 没办法对于这种限制条件较为宽泛的算法
    精确的算出其时间复杂度

    对于终止条件的 不确定，该算法一开始的终止条件
    在我看来，应该是成环条件下，要把环走一遍就可得到全部解
    也就是从1到n的最长环的长度的两倍即可
    

    没仔细想这个限制条件所导致的复杂度
    从而没去想最后的终止条件问题

    因为是最长环的两倍所以，我后面将条件更改为min(n,m)
    最后的结果也是对的，最长的环不是 n 就是 m，但是不是
    两倍的情况下也是对的，为什么呢
    应该是 数据出的地方没有着重在这里的问题
    上述算法的时间复杂度
    O(min(n,m) * (max(一个点所链接的边)的指数次) * log(1024))

    优化：
        我们可以知道的是，每一个点最后只可能产生
    0~1023 共1024个值 ，所以总共有1024 * n钟情况
    我们可以根据此来写相应的得到的情况，
    再根据此可以用于优化 BFS或者DFS，以实现降低复杂度
    O( (n + m ) * max(w_{i}))


    for (int i = 0;i < m;i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({ v,w });
    }
    set<i64>value[n];
    value[0].insert(0LL);
    queue<pii>q;
    q.push( {0LL, 0LL} );
    i64 cnt = 0;
    while (!q.empty() && cnt <= 2LL * min(n, m)) {
        auto k = q.front();
        cnt = k.se;
        i64 u = k.fi;
        q.pop();
        for (auto pirs : g[u]) {
            i64 v = pirs.fi, w = pirs.se;
            q.push({ v,cnt + 1LL });
            auto tmpv = value[u];
            for (auto x : tmpv) {
                value[v].insert((x ^ w));
            }
        }
    }


*/