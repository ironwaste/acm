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

// 补题——题目链接: https://codeforces.com/contest/2162/problem/C
// 网址：
// 2025.10.17——22:56:02
/*
 *
 *
 *
*/

void solve(){
    int a, b;
    cin >> a >> b;
    i64 a0 = __builtin_clz(a), b0 = __builtin_clz(b);

    if (a0 > b0) {
        cout << -1 << endl;
        return;
    }

    vector<int>ans;
    for (int i = 0;i < 32;i ++) {
        i64 va = ((a >> i) & 1), vb = ((b >> i) & 1);
        if (va != vb) {
            ans.push_back(1<<i);
        }
    }
    i64 sz = ans.size();
    cout << sz << endl;
    if (sz == 0) { return; }
    for (auto x : ans) {
        cout << x << " ";
    }cout << endl;


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