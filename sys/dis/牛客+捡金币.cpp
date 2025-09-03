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


// 补题——题目链接: https://ac.nowcoder.com/acm/contest/1838/H
// 网址：
// 2025.09.03——11:24:55
/*
 * 二维前缀和 + 曼哈顿距离 转换切比雪夫距离 
 *
 *
*/

void solve(){
    i64 n, m;
    cin >> n >> m;
    i64 num = n + m + 1;
    vector<vector<i64> >g(num + 1, vector<i64>(num + 1, 0));
    auto sum = g;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j ++) {
            i64 v;
            cin >> v;
            i64 x = i + j, y = i - j + m;
            // de(x)deb(y);
            g[x][y] = v;
        }
    }
    // auto prx =[]
    
    for (int i = 2;i <= num;i++) {
        for (int j = 1;j <= num;j++) {
            
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + g[i][j];
        }
    }

    auto diff = [&](i64 x, i64 y,i64 xx,i64 yy)->i64 {
        i64 res = sum[x][y];
        res -= (sum[x][yy - 1] + sum[xx - 1][y]);
        res += sum[xx - 1][yy - 1];
        return res;
        };
    i64 q;
    cin >> q;
    while(q--) {
        i64 i,j,x, y, k;
        cin >> i >> j >> k;
        x = i + j,y = i - j + m;
        i64 xx = max(x - k, 1LL), yy = max(y - k, 1LL);
        x = min(num, x + k), y = min(num, y + k);
        cout << diff(x, y, xx, yy) << endl;
    }
}

int main(){
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