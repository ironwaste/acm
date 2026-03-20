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

// 2026.03.20——19:54:41
// 2026.03.20——20:01:19 ac
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    if (k > 32) {
        cout << 1 << endl;
        return;
    }
    for (i64 i = 2;;i ++) {
        i64 sumn = i;
        for (i64 j = 1;j < k;j++) {
            sumn *= i;
        }
        if (sumn > n) {
            cout << i - 1LL << endl;
            break;
        }
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