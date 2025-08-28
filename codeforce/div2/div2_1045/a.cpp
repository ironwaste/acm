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
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;

using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 2025.08.26——22:35:56
// 2025.08.26——22:50:15 
/*
 *
 *
 *
*/

void solve() {
    i64 n, a, b;
    cin >> n >> a >> b;
    // 只有一次 。。。 
    if (b % 2 != n % 2) {
        no;
    } else if(b >= a){
        yes;
    } else if ((b - a) % 2 == 0) {
        yes;
    } else {
        no;
    }




}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}