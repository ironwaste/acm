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

/* 思虑不够清晰
 *

*/
void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n, 0);
    for (auto& x : a) { cin >> x; }

    vector<i64>diff(n - 1, 0);
    for (int i = n - 1;i;i-- ) {
        diff[i - 1] = a[i] - a[i - 1];
    }

    // for (int i = 0;i < n - 1;i ++) {
    //     // cout << diff[i] << endl;
    //     de(i)deb(diff[i])
    // }

    int ok_0 = 0, ne_ok = -1,ok_n1 = 1,ok_n2=1;
    int pre = diff[0];
    for (int i = 0;i < n - 1;i++) {
        if ((pre > 0 && diff[i] < 2 )|| pre <= 0) {
            ok_n1 = 0;
        }
        if ((pre < 0 && diff[i] > -2 )|| pre >= 0) {
            ok_n2 = 0;
        }
        if (diff[i] <= 1 && diff[i] >= -1) {
            ok_0 = 1;
            ne_ok = 0;
        }
    }
    // de(ok_n1)deb(ok_n2)
    if (ne_ok == -1) {
        ne_ok = 0;
    } 
    if (ok_n1 || ok_n2) {
        ne_ok = 1;
    }
    if (ne_ok) {
        cout << -1 << endl;
        return;
    } else if (ok_0) {
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }
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