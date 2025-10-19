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


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://codeforces.com/contest/2154/problem/C2
// 网址：
// 2025.10.19——23:12:29
/*
 *
 * 0 和 1 的情况都很好解决，
 * 就是成本为2 的情况如何取最小值
 *
 * 求所有的因子 ， sqrt(n);
 * 那么就是 500 左右 刚好 1e8
 *
*/
const i64 N = 2e5 + 10;
i64 minp[N];
void init() {
    minp[1] = 1;
    for (int i = 2;i < N;i++) {
        for (int j = i;j < N;j += i) {
            if (!minp[j])minp[j] = i;
        }
    }
}


void solve() {
    
    





}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}