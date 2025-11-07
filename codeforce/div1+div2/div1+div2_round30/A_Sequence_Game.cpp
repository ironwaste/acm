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

// 补题——题目链接:
// 网址：
// 2025.11.06——22:35:37
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    i64 mi, mx;
    cin >> mi;
    mx = mi;
    for (int i = 1;i < n;i++) {
        i64 v;
        cin >> v;
        mi = min(mi, v);
        mx = max(mx, v);
    }
    i64 x;
    cin >> x;
    cout << ((x >= mi && x <= mx) ? "YES" : "NO") << endl;

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