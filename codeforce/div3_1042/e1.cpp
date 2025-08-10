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
#define de(x) cerr << #x <<" "<< x <<" ";
#define deb(x) cerr << #x <<" "<< x <<endl;
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 2025.08.10——23:10:41
/*
 *
 * 除了最后一位其他 所有位置可以异或其后一位
 * 然后将所有的
 *
 * 前缀异或和 ，然后正序判断 存当前位置 所需要到的下标位置
 *
*/

void solve() {
    int n;
    cin >> n;
    vector<i64>a(n), b(n);
    for (int i = 0;i < n;i++) { cin >> a[i]; }
    for (int i = 0;i < n;i++) { cin >> b[i]; }
    int ok = 1;
    if (a[n - 1] != b[n - 1]) {
        cout << "NO" << endl;
        return;
    }
    for (int i = n - 2;i >= 0;i--) {
        // deb(i) de((a[i] ^ b[i + 1]));
        // deb((a[i] ^ a[i + 1]));
            
        if (((a[i] ^ b[i + 1]) == b[i]) || ((a[i] ^ a[i + 1]) == b[i]) || (a[i] == b[i])) {
            continue;
        } else {
            // deb(i)
            ok = 0;
            break;
        }

    }

    cout << ((ok) ? "YES" : "NO") << endl;
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