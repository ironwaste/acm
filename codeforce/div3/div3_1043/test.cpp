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

// 2025.08.21——23:53:36
/*
 * 1       (0 -- 0)
 * 19      (0 -- 9)
 * 280     (0 -- 180)
 * 3700    (0 -- 3700)
 * 46000   (0 -- 46000)
 * 550000  (0 -- 450000)
 * 6400000 (0 -- 5400000)
*/

void solve() {
    map<i64, i64>cnt;
    for (int i = 100;i < 1000;i++) {
        i64 v = i;
        while (v) {
            cnt[v % 10]++;
            v /= 10;
        }
    }

    for (auto [x, y] : cnt) {
        de(x)deb(y);
    }

}

int main(){
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