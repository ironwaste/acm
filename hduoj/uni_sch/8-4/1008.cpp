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

// 2025.08.04——13:00:20
// 2025.08.04——13:29:57  wa
/*
 * 第二次wa当前情况下 ，我们所需要的 解决的问题在于
 * 当前缀和 最大值同时存在多个的时候 不同的行 存在着 不同的解
 *
 * 比如样例 :
 * 4 1 1 1 -> 7
 * 2 3 1 1 -> 7
 * 2 2 1 1 -> 6
 *
*/

void solve(){
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<pll> sum;
    vector<vector<i64> >mar(n, vector<i64>(m, 0));
    vector<vector<i64> >t_mat(m, vector<i64>(n, 0));
    for (int i = 0;i < n;i++) {
        i64 he = 0;
        for (int j = 0;j < m;j++) {
            cin >> mar[i][j];
            t_mat[j][i] = mar[i][j];
            he += mar[i][j];
        }
        sum.push_back({ he,i });
    }
    if (k >= m) {
        i64 ans = 0;
        for (int i = 0;i < m;i++) {
            sort(all(t_mat[i]));
            ans += t_mat[i].back();
        }
        cout << ans << endl;
        return;
    }
    sort(all(sum), [&](pll a, pll b) {
        return a.fi > b.fi;
        });
    // 需要根据当前 行的和 进行排序，
    // 并且排序之后， 将所有其他的下雨该列 当前前缀和的 最大值的 单列值
    // 进行替代
    for (int pk = 1;pk < k;pk++) {
        i64 id = sum[0].se;
        for (int i = 0;i < n;i++) {
            i64 pos = sum[i].se;
            for (int j = 0;j < m;j++) {
                sum[i].fi += max(0LL,mar[id][j] - mar[pos][j]);
                mar[pos][j] = max(mar[pos][j], mar[id][j]);
            }
        }
        sort(all(sum), [&](pll a, pll b) {
            return a.fi > b.fi;
            });
    }

    cout << sum[0].fi << endl;


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