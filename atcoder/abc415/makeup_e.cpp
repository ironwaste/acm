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


// 补题——题目链接:
// 网址：
// 2025.07.20——01:30:30
/*
 *
 *
 *
*/
// 2025.07.19——21:25:06
/*
 * 需要使用bfs遍历一遍数组，看时间复杂度是多少
 *
 * 总结:这道题目,很精准的表明了,为何要从后向前进行dp,而不能够
 * 从前往后dp,这表明了其后效性的关键,其次是其数据范围可能超过
 * INT_MAX 的限度导致我wa了一发,可以倒着使用bfs,但是不如直接使用遍历来的好
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

    vector<vector<i64> >dp(h+10,vector<i64>(w+10,LLONG_MAX));
    dp[h - 1][w - 1] = 0;
    for (int i = h - 1;~i;i --) {
        for (int j = w - 1;~j;j--) {
            if (i + 1 < h) {dp[i][j] = min(dp[i + 1][j], dp[i][j]);}
            if (j + 1 < w) {dp[i][j] = min(dp[i][j + 1], dp[i][j]);}
            dp[i][j] += p[i + j] - g[i][j];
            dp[i][j] = max(0LL, dp[i][j]);
        }
    }


    cout << dp[0][0] << endl;



}
// 2025.07.20——14:50:00 accpted
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