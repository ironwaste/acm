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
// 2025.10.25——20:04:42
/*
 *
 *
 *
*/
i64 CC(i64 b) {
    return (b * (b - 1LL)) / 2;
}
void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    map<i64, i64>mp;
    for (int i = 0;i < n;i ++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    i64 ans = 0;
    for (auto [x, y] : mp) {
        if (y >= 2) {
            ans += CC(y) * (n - y);

        }
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