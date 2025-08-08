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

// 2025.08.07——22:45:55
// 2025.08.07——23:01:55 wa 2 ???
// 2025.08.07——23:04:16 wa2 本以为是下标问题
// 2025.08.07——23:06:16 accpted 确实是下表问题。。。
/*
 * 如果左右的值不同的情况下， 可以将 小的值变道其身边
 * 也就是 x - 1 或者 x + 1的情况
 *
*/

void solve(){
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    s = ' ' + s;
    int ansl = 0, ansr = 0, l = x - 1, r = n - x;
    for (int i = 1;i < x;i++) {
        if (s[i] == '#') {
            ansl = max(ansl, i);
        }
    }
    for (int i = x + 1;i <= n;i++) {
        if (s[i] == '#') {
            ansr = max(ansr, n - i + 1);
        }
    }

    // de(ansl)deb(ansr);
    if (ansl == ansr) cout << ansl + 1 << endl;
    else {
        if (ansl < ansr) {
            ansl = l;
        } else {
            ansr = r;
        }
        cout << min(ansl, ansr) + 1LL << endl;
    }
    // cout << max(res1, res2) + 1 << endl;


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