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

// 2025.07.23——22:11:19
/*
 * 最近公共祖先 LCA
*/
const int N = 5e5 + 10;
i64 num[N], top[N],is_tp[N],height[N],f[N];
vector<vector<i64> >g;
void dfs(i64 fa, i64 u, i64 tp,i64 step) {
    f[u] = fa;
    height[u] = step;
    top[u] = tp;
    i64 next_top = tp;
    if (is_tp[u]) { next_top = u; }
    int cnt = 0;
    for (auto v : g[u]) {
        if (v == fa)continue;
        if (!cnt) {
            cnt++;
            dfs(u, v, next_top, step + 1LL);
        } else {
            dfs(u, v, v, step + 1LL);
        }
    }
}


void solve() {
    i64 n, m, s;
    cin >> n >> m >> s;
    g.resize(n + 10);
    for (int i = 1;i < n;i++) {
        i64 x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 1;i <= n;i ++) {
        if (g[i].size() >= 3) {is_tp[i] = 1LL;}
    }

    dfs(s, s, s, 0LL);

    // for (int i = 1;i <= n;i ++) {
    //     de(i)de(height[i])deb(top[i])
    // }
    //如何快速判断两者在同一条链上
    while (m--) {
        i64 a, b;
        cin >> a >> b;
        while (top[a] != top[b] && a != top[b] && b != top[a]) {
            if(height[a] >= height[b]) {
                if (a == top[a]) {
                    a = f[a];
                } else {
                    a = top[a];
                }
            }else {
                if (b == top[b]) {
                    b = f[b];
                } else {
                    b = top[b];
                }

                // b = top[b];
            }
        }
        
        if (height[a] > height[b]) { swap(a, b); }
        // i64 tpa = top[a];
        cout << a << endl;
    }
}

// 2025.07.23——23:07:28 TLE了嗡嗡嗡
// 2025.07.23——23:25:07 TLE 但是相较于之前少TLE了一个，现在TLE三个
// 修改部分，将一开始无法判断 是否在同一条链上，修改了一下，将第一次到达的子节点的top值
// 设置为正常的分支之前的节点，但是对于而后遍历到的节点的top值，修改为了本身
// 然后去判断是否在同一条链上，在根据其高度得出解

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