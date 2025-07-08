#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<numeric>

#define endl '\n'
#define i64 long long
#define fi first
#define se second
#define Endl endl
#define END endl
#define de(x) cerr << #x << " " << x << " ";
#define deb(x) cerr << #x << " " << x << "\n";
#define all(x) x.begin(),x.end()
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;


// 补题——题目链接:https://atcoder.jp/contests/abc412/tasks/abc412_d
// 网址：https://atcoder.jp/contests/abc412/editorial/13394
// 2025.07.08——17:40:30

/*
 * 因为数据量很小所以可以直接使用暴力的方法，n<= 8
 * 直接全排列然后成环就好，但是其实大于等于6的时候可以成两个环
 * 所以需要对此进行稍加判断
 * 3 3
 *
 * 3 4
//  * 4 3
 *
 * 4 4
 * 3 5
//  * 5 3
 */

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64> >g(n,vector<i64>(n,0));
    for (int i = 0;i < m;i ++) {
        i64 a, b;
        cin >> a >> b;
        a--, b--;
        // if (g[a][b]) 
        g[a][b] = 1;
        g[b][a] = 1;
    }
    vector<i64>a(n);
    iota(all(a), 0);
    i64 ans = INT_MAX,need = n;
    // vector<i64>ko = { 0,3,4,5,1,2 };
    int ko = 1;
    do {
        i64 tmp = 0;
        // 原本给出的边 和 我们所需要的边重合的不变，但是两者不重合的要加上操作数
        // 为一个环的情况
        for (int i = 0;i < n;i++) {
            if (g[a[i]][a[(i+1) % n]]) { tmp++; }
        }
        ans = min(ans, m - tmp + need - tmp);
       
        if (n <= 5)continue;
        // 两个环的情况
        for (i64 i = 3;i <= 4;i++) {
            tmp = 0;
            if (n - i < 3)continue;
            for (int j = 0;j < i;j++) {
                if (g[a[j]][a[(j + 1) % i]]) {tmp++;}
            }
            for (int j = i;j < n;j++) {
                if (j == n - 1) {
                    if (g[a[j]][a[i]])tmp++;
                    continue;
                }
                if (g[a[j]][a[(j + 1)]]) { tmp++; }
            }

            ans = min(ans, m - tmp + need - tmp);
        }
    } while (next_permutation(all(a) ));
    cout << ans << endl;
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