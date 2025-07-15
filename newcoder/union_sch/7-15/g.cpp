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

// 2025.07.15——12:13:42
/*
 * x的取值范围为 [0,min(|Tsz| , n)] // 总上限也就是 1e6
 *
 *
*/

void solve() {
    i64 n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    while (q--) {
        i64 a,ans = 0;
        string t;
        cin >> t >> a;
        t = ' ' + t;
        i64 tsz = t.size() - 1LL;

        for (i64 i = 1,si = a;i <= min(n,tsz);i++) {
            while (i <= min(tsz,n) && s[si + i - 1LL] != t[i]) {
                i++;
            }
            i64 j = i;
            while (j <= min(tsz, n) && t[j] == s[si + j - 1LL]) {
                j++;
            }
            // de(i)de(j)deb(j - i)
            ans += ((1LL + (j - i)) * (j - i)) / 2LL;
            i = j - 1LL;

        }
        cout << ans << endl;
    }

}
// 2025.07.15——12:36:36

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