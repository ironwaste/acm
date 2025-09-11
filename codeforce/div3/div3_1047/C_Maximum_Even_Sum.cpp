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

// 2025.09.11——02:24:04
// 2025.09.11——02:31:07 wa 2 ??
// 2025.09.11——02:33:27 accpted
/*
 *
 *
 *
*/

void solve(){
    i64 a, b;
    cin >> a >> b;
    if (a % 2 == 1 && b % 2 == 1) {
        // i64 gd = __gcd(a, b);
        a *= b;
        // b /= gd;
        cout << a + 1LL << endl;
    } else if (a %2 == 0 && b % 2 == 0) {
        cout << a * b / 2 + 2 << endl;
    } else if (b % 2 == 1 && a % 2 == 0) {
        cout << -1 << endl;
    } else {
        if ((a * b / 2 + 2LL) % 2 == 0) {
            cout << a * b / 2 + 2LL << endl;
        } else { cout << -1 << endl; }
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