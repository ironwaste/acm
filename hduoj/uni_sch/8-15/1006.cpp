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

// 2025.08.15——13:29:44
// 2025.08.15——14:57:19 accpted
/*
 *
 *
 *
*/

void solve(){
    string s;
    cin >> s;
    i64 n = s.size();
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    vector<i64>ll;
    for (int i = 0;i < n - 1;i++) {
        if (s[i] == '(' && s[i + 1] == ')') {
            ll.push_back(i);
        }
    }
    vector<pll>d1(n + 10, { 0,0 }), d2(n + 10, { 0,0 });

    // 所以需要存三个值  一个是 回文串内，的字串中 
    // vector< i64 >dp2(n + 1, 0), dp1(n + 10, 0), d1(n + 10, 0),d2(n + 10, 0);
    // 用于存 以i为中心的时候 是回文串平且包含 括号串的个数
    // d 用于fi存半径 se 存答案数
    // 奇数情况下 ：

    for (int i = 0, l = 0, r = -1;i < n; i++) {

        i64 k;
        if (i > r) { k = 1; }
        else {
            int j = l + r - i;
            if (d1[j].fi > r - i + 1) {
                d1[i].fi = 1, d1[i].se = 0;
                k = 1;
            } else {
                d1[i] = d1[j];
                k = d1[j].fi;
            }
        }
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            i64 nowl = i - k, nowr = i + k;
            i64 pos = lower_bound(all(ll), nowl) - ll.begin();
            i64 lr = ll[pos] + 1;
            if (lr <= nowr && ll[pos] >= nowl) {
                d1[i].se++;
            }
            k++;
        }
        d1[i].fi = k--;
        if (i + k > r) {
            l = i - k ;
            r = i + k;
        }
    }
    
    for (int i = 0, l = 0, r = -1;i < n; i++) {
        i64 k;
        if (i > r) { k = 0; }
        else {
            int j = l + r - i + 1;
            if (d2[j].fi > r - i + 1) {
                d2[i].fi = 0, d2[i].se = 0;
                k = 0;
            } else {
                d2[i] = d2[j];
                k = d2[j].fi;
            }
        }
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            i64 nowl = i - k - 1, nowr = i + k;
            i64 pos = lower_bound(all(ll), nowl) - ll.begin();
            i64 lr = ll[pos] + 1;
            if (lr <= nowr && ll[pos] >= nowl) {
                d2[i].se++;
            }
            k++;
        }
        d2[i].fi = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    i64 ans = 0;
    for (int i = 0;i < n;i++) {
        // de(i)de(d1[i].se)deb(d2[i].se);
        ans += d1[i].se;
        ans += d2[i].se;
    }
    cout << ans << endl;
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