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

// 2025.08.11——00:05:38
/*
 *
 *
 *
*/

i64 equal(char a, char b) {
    if (a == b)return 1;
    return 0;
}

void solve() {
    i64 n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    // i64 cnt0 = 0, cnt1 = 0;
    vector<pll>x(n, { 0,0 }), y(n, { 0,0 });
    vector<i64>tmpx(n, 0), tmpy(n, 0);
    i64 ans = n * n * (n + 1);
    for (int i = 0;i < n;i++) {
        if (i) {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }
        if (a[i] == '0') { x[i].fi++; } else { x[i].se++; }

        if (b[i] == '0') { y[i].fi++; } else { y[i].se++; }

        tmpx[i] = x[i].fi - x[i].se;
        tmpy[i] = y[i].se - y[i].fi;
    }
    // ans = ans * (1 + n) * n / 2;
    // deb(ans);
    sort(all(tmpx));
    sort(all(tmpy));
    // for (auto x : tmpx) {
    //     de(x);
    // }cout << endl;
    // for (auto y : tmpy) {
    //     de(y);
    // }cout << endl;
    i64 cntans = 0;
    for (int i = 0;i < n;i++) {
        i64 v = tmpx[i];
        i64 pos = upper_bound(all(tmpy), v) - tmpy.begin();
        // lower_bound 和 upper_bound 的位置还是不确定，不熟悉
        cntans += pos * v;
        cntans -= (n-pos) * v;
        // de(v)de(pos);
        v = tmpy[i];
        pos = lower_bound(all(tmpx), v) - tmpx.begin();
        // de(v)deb(pos);
        cntans += pos * v;
        cntans -= (n - pos) * v;
    }
    // cntans /= 2;
    // de(ans)deb(cntans)
    cout << (ans - cntans) / 2 << endl;
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