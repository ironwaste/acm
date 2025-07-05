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

// 2 ^ 10 == 1024
// 2^18 == 2e5  左右
void solve() {
    int n;
    cin >> n;
    n = 1LL << n;
    // cout << n << endl;
    vector<pll>a;
    for (int i = 0;i < n / 2;i++) {
        i64 x, y;
        cin >> x >> y;
        if (x > y)swap(x, y);
        a.pb(make_pair(x, y));
    }
    vector<pll>ans;
    vector<i64>vis(n / 2,0);
    for (int i = 0;i < n / 2;i++) {
        i64 id = i;
        for (int j = i;j < n / 2;j += (i + 1)) {
            if (vis[j]) { continue; }
            if (a[j].fi < a[id].fi) {
                id = j;
            }
        }
        vis[id] = 1;
        ans.pb(a[id]);
    }

    for (int i = 0;i < n/2;i ++) {
        cout << a[i].fi << " " << a[i].se << " \n"[i == n / 2 - 1];
    }
    // sort(all(a));



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >>  T;
    while (T--) {
        solve();
    }
    return 0;
}