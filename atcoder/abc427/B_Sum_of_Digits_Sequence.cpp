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


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://atcoder.jp/contests/abc427/tasks/abc427_b
// 网址：
// 2025.10.11——20:04:18
/*
 *
 *
 *
*/
i64 f(i64 x) {
    i64 res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n + 1, 0);
    a[0] = 1;
    i64 prx = 1;
    for (i64 i = 1;i <= n; i++) {
        a[i] = prx;
        prx += f(a[i]);
    }
    cout << a[n] << endl;

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