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

// 补题——题目链接: https://codeforces.com/contest/1629/problem/B
// 网址：
// 2025.09.19——10:25:41
/*
 *
 *
 *
*/

void solve(){
    i64 l, r, k;
    cin >> l >> r >> k;
    if (l == r) {
        if (r > 1)cout << "YES\n";
        else cout << "NO\n";
    } else if ((r - l + 1) - (r / 2 - l / 2 + (l+1) % 2) <= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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