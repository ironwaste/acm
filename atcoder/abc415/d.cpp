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

// 2025.07.19——21:11:08
/*
 *
 *
 *
*/
struct node {
    i64 a, b;
    friend bool operator<(const node&a,const node&b) {
        return a.a - a.b > b.a - b.b;
    }
    node(i64 x, i64 y) :a(x), b(y) {};
};


void solve() {
    i64 n, m;
    cin >> n >> m;
    priority_queue<node>q;
    for (i64 i = 0;i < m;i ++) {
        i64 a, b;
        cin >> a >> b;
        q.push({ a,b });
    }
    i64 ans = 0;
    while (n > 1 && !q.empty()) {
        auto [a, b] = q.top();
        // de(a)deb(b)
        q.pop();
        if (a > n) { continue; }
        i64 cnt = ((n - a) / (a - b)) + 1LL;
        ans += cnt;
        n -= cnt * (a - b);
        // de(cnt)de(ans)deb(n);
    }
    cout << ans << endl;
}
// 2025.07.19——21:24:56 accepted
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