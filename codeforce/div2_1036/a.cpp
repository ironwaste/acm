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

// 判断是否存在逆序对

void solve(){
    int n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    i64 mx = 0;
    for (int i = 0;i < n;i ++) {
        if (mx > a[i]) {
            cout << "YES\n";
            cout << 2 << endl << mx << " " << a[i] << endl;
            return;
        }
        mx = max(mx, a[i]);
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // 2025.07.06——22:57:06
    // 2025.07.06——23:03:43
    while (T--) {
        solve();
    }
    return 0;
}