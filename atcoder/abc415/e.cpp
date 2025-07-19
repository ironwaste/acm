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

// 2025.07.19——21:25:06
/*
 * 需要使用bfs遍历一遍数组，看时间复杂度是多少
 *
 *
*/

i64 dir[2][2] = { {0,1} ,{1,0} };

void solve() {
    i64 h, w;
    cin >> h >> w;
    vector<vector<i64> >g(h, vector<i64>(w, 0));
    for (int i = 0;i < h;i ++) {
        for (int j = 0;j < w;j ++) {
            cin >> g[i][j];
        }
    }
    vector<i64>p(h + w - 1);
    for (auto& x : p) { cin >> x; }
    // i,j钱数、天数、
    // 天数 == i + j
    // map一个vis为 {i,j} = 钱数；
    // map一个{i,j}
    // map<array<i64, 3>, array<i64, 2> >mp;
    queue <array<i64, 4> > q;
    // 最后一位代表路径中的最小值
    vector<vector<array<i64, 2> > >dp(h, vector<array<i64,2> >(w, { INT_MIN,INT_MIN }));
    q.push({ -1,0,0 ,INT_MAX});
    while (!q.empty()) {
        auto [x, y, v,miv] = q.front();
        i64 k = x + y + 1;
        q.pop();
        for (int i = 0;i < 2;i++) {
            i64 nx = x + dir[i][1], ny = y + dir[i][0];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                auto [dpv, pre_v] = dp[nx][ny];
                // dpv 是 该点历史序列最大值，pre_v当前剩余的钱
                i64 cnt_v = v + g[nx][ny] - p[k];
                // cnt_v = 当前剩余的钱，根据路径来的
                i64 mv = min(miv, cnt_v);
                // de(nx)de(ny)de(dpv)de(mv)de(cnt_v)deb(pre_v)
                if (mv > dpv || (mv == dpv && cnt_v > pre_v)) {
                    q.push({ nx,ny,cnt_v,mv });
                    dp[nx][ny] = { mv,cnt_v };
                }
            }
        }        
    }

    cout << max(0LL, -dp[h-1][ w-1][0]) << endl;



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