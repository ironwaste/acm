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

// 2025.08.17——19:16:26
// 2025.08.17——19:20:23accpted
/*
 * 为什么 ？？？ 
 *
 *
*/

void solve() {
    int n;
    cin >> n;
    // vector<i64>cnt(3, 0);
    // for (int i = 0;i < n;i ++) {
    //     cnt[i % 3]++;
    // }
    // i64 ans = 0;
    // ans += cnt[0] / 2;
    // ans += min(cnt[1], cnt[2]);
    // if (ans >= n) {
    //     c
    // }
    if (n % 4 == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}