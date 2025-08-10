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

// 2025.08.10——22:39:40
// 2025.08.10——22:43:32 wa 2
// 2025.08.10——22:46:30 accpted
/*
 *
 *
 *
*/

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "-1 2" << endl;
        return;
    }
    for (int i = 0;i < n;i++) {
        if (i % 2 == 0) {
            cout << -1 << " ";
        } else if( i == n -1 && n % 2 == 0){
            cout << 2 << " ";
        } else {
            cout << 3 << " ";
        }
    }cout << endl;
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