// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
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
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 2025.07.12——20:02:23
/*
 *
 *
 *
*/

void solve(){
    int n;
    cin >> n;
    vector<pair<char, i64> >a(n);
    unsigned long long sum = 0,ok =0;
    for (auto& [x, y] : a) {
        cin >> x >> y;
        sum += y;
        if (sum > 100) { ok = 1; }
    }
    if (ok) {
        cout << "Too Long\n";
    } else {
        for (auto [x,y] : a) {
            i64 t = y;
            while (t--) {
                cout << x;
            }
        }
        cout << endl;
    }
}
// 2025.07.12——20:05:45 TLE
// 2025.07.12——20:08:02 忘记了数据范围 1e18 * 100 大于longlong 数据范围
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}