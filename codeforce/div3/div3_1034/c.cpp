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

// 2025.08.17——19:28:05
// 2025.08.17——19:33:31 accpted
/*
 * 也没有完整证明 但是对了
 *
 *
*/

void solve() {
    int n;
    cin >> n;
    vector<i64>a(n);
    set<i64>s;
    i64 mi = INT_MAX;
    for (int i = 0;i < n;i ++) {
        cin >> a[i];
        mi = min(a[i], mi);
        s.insert(mi);
    }
    i64 mx = 0;
    for (int i = n-1;i >= 0;i --) {
        // cin >> a[i];
        mx = max(a[i], mx);
        s.insert(mx);
    }
    for (int i = 0;i < n;i++) {
        if (s.count(a[i])) {
            cout << 1;
        } else {
            cout << 0;
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