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


// ai is odd 
// 
// bi is 0 or bi is 1 or ai or ai- 1  // is 4

// ai is even 
// bi = ai or bi == 0 // 2


void solve() {
    int n;
    cin >> n;
    vector<i64>a(n),L(n);
    for (auto& x : a) { cin >> x; }
    for (auto& x : L) { cin >> x; }

    i64 ans = 1;

    for (int i = 0;i < n;i ++) {
        if (a[i] % 2 == 1LL) {
            if(L[i] >= a[i])(ans *= 4LL ) %= mod3;
            else if(L[i] >= a[i] - 1LL)(ans *= 3LL ) %= mod3;
            else if (L[i] >= 1LL)(ans *= 2LL) %= mod3;
        } else {
            if (L[i] >= a[i])(ans *= 2LL) %= mod3;
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