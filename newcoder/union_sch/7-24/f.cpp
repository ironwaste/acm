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

// 2025.07.24——12:49:00
/*
 *
 *
 *
*/

void solve() {
    i64 n, k, c;
    cin >> n >> k >> c;
    // vector<i64>a(n);
    vector<pll>a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i].fi;
        a[i].fi -= (i+1LL) * c;
        a[i].se = i;
    }

    sort(a.begin(), a.end(), [&](pll a,pll b) {
        if (a.fi != b.fi) {
            return a.fi > b.fi;
        } else {
            return a.se < b.se;
        }
        });

    i64 sum = 0;
    for (int i = 0;i < k;i++) {
        sum += a[i].fi + ((i + 1LL) * c);
        // if (vk < a[i][0]) {id = i;break;}
    }
    // sort(a.begin(), a.end() + vk, [&](i, j) {
    //     return a[i][1] < a[j][1];
    //     });
    cout << sum << endl;
    








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