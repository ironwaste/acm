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

// 2025.08.05——12:02:30
/*
 *
 *
 *
*/
i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1LL) res = res * a % mod3;
        a = a * a % mod3;
        b >>= 1LL;
    }
    return res % mod3;
}


void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    map<i64, i64>mp;
    i64 odd = 0, even = 0;
    for (auto& x : a) {
        cin >> x;mp[x]++;
        if (x % 2 == 1) {
            odd++;
        } else {
            even++;
        }
    }
    if (mp.size() == 1) {
        cout << 0 << endl;
    } else {
        cout << odd * even % mod3 <<endl;
    }

    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}