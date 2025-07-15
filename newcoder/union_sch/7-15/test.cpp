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

// 2025.07.15——16:01:30
/*
 *
 *
 *
*/
/*
10 6
927 554 516 488 88 187 986 792 252 484
10 942
9 284
4 495
2 95
3 603
4 443
1 787
*/
void solve() {
    int n, q;
    cin >> n >> q;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    auto b = a;
    sort(all(b));
    cout << "sorted \n" << endl;
    for (auto x : b) {
        cout << x << " ";
    }
    cout <<endl<< " ------------------------- " << endl;

    while (q--) {
        i64 p, v;
        cin >> p >> v;
        // de(p)deb(v);
        cout << "P : " << p << "  " << "v : " << v << endl;
        p--;
        a[p] = a[p] + v;
        b = a;
        sort(all(b));
        for (auto x : b) {
            cout << x << " ";
        }cout << endl << endl;
        // i64 mid = b[(n + 1LL) / 2];
        // i64 ans = lower_bound(all(b), mid) - b.begin();
        // cout << ans << endl;
    }



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