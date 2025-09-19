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

// 补题——题目链接:https://atcoder.jp/contests/abc423/tasks/abc423_a
// 网址：
// 2025.09.18——15:02:52
// 2025.09.18——15:07:44 
/*
 *
 *
 *
*/

void solve(){
    i64 x, c;
    cin >> x >> c;
    i64 ans = 0;
    for (i64 i = 1000;i <= x;i +=1000) {
        i64 v = (i / 1000) * c;
        if(i + v <= x)ans = max(ans, i);
    }

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