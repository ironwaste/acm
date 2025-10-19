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

// 补题——题目链接: https://atcoder.jp/contests/abc428/tasks/abc428_a
// 网址：
// 2025.10.19——11:35:39
/*
 *
 *
 *
*/

void solve(){
    i64 s, a, b, x;
    cin >> s >> a >> b >> x;
    i64 sum = 0;
    while (x > 0) {
        i64 mi = min(x, a);
        x -= mi;
        sum += mi * s;
        x -= b;
    }
    
    cout << sum << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}