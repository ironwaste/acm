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


// 补题——题目链接:
// 网址：
// 2025.09.09——22:44:33
// 2025.09.09——23:16:59
/*
 *
 *
 *
*/
const i64 lim = 1e9;
void solve(){
    i64 x;
    cin >> x;
    i64 k = x + 1LL;
    i64 v = 10;
    for (;v <= k;v *=10LL) {
    }
    v = min(v * 10LL, lim);
    cout << v - k << endl;

    // de(v)deb(v - k);
    // i64 ans = v - k;
    // i64 vv = v / 10;
    // i64 vk = x / vv;
    // if (vk == 9) {
    //     v *= 10LL;
    // }
    // cout << v << endl;
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
// 987654390123456