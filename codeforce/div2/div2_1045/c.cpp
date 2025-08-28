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

// 2025.08.26——23:06:43
// 2025.08.26——23:24:14 accpted
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }

    i64 ans = 0;
    for (int i = 1;i < n;i += 2) {
        // b >= a, b>= c b>= a+c;
        // 尽量让 c更小，且a是固定的
        i64 prea = a[i - 1], b = a[i];
        if (i + 1 < n) {
            i64 c = a[i + 1];
            if (prea + c > b) {
                i64 v = prea + c - b;
                ans += v;
                a[i + 1] = max(0LL, a[i + 1LL] - v);
            }
        } else {
            if (prea > b) {
                ans += prea - b;
            }
        }
    }



    cout << ans << endl;
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