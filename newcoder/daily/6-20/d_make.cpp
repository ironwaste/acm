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

const int SIZE = 60;
const int N = 1e6;

struct Trie {
    struct node {
        array<int, 2>son;
        node() :son{} {}
    };
    vector<node>t;

    Trie() { init(); }
    void init() { t.assign(1, node()); }
    // 初始化 vector，设置大小为1并赋值为 node()
    i64 newnode() {
        t.emplace_back();
        return t.size() - 1;
    }


    void insert(i64 x) {
        int p = 0;
        // 1 <= x <= 1e9
        for (int i = 30;~i;i--) {
            int v = x >> i & 1;
            if (t[p].son[v] == 0) {
                t[p].son[v] = newnode();
            }
            p = t[p].son[v];
        }
    }

    i64 query(i64 x) {
        i64 p = 0, ans = 0;
        for (int i = 30;~i;i--) {
            i64 v = x >> i & 1;
            if (t[p].son[v ^ 1]) {
                ans |= 1 << i;
                p = t[p].son[v ^ 1];
            } else {
                p = t[p].son[v];
            }
        }
        return ans;
    }
};


void solve(){
    int n;
    cin >> n;
    vector<i64>a(n),ans(n,0);
    for (int i = 0;i < n;i++) { cin >> a[i]; }

    vector<vector<i64> >g(n);
    for (int i = 0;i < n - 1;i ++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // printf(n);
    // deb(n);
    Trie trie;
    auto dfs = [&](auto self,int fa, int u)->void {
        ans[u] = max(ans[u], trie.query(a[u]));// 关键在这里，没想清楚 
        for (auto v : g[u]) {
            if (fa == v)continue;
            self(self, u, v);
        }
        trie.insert(a[u]);
        };
    dfs(dfs, 0, 0);
    // deb(n);
    for (int i = 0;i < n;i ++) {
        reverse(all(g[i]));
    }
    trie.init();
    dfs(dfs, 0, 0);
    for (int i = 0;i < n;i ++) {
        cout << ans[i] << " ";
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