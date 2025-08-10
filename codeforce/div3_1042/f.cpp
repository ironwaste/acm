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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    i64 cnt0 = 0, cnt1 = 0;
    i64 ans = 0;
    for (i64 i = 0;i < n;i++) {
        if (a[i] == '0') {cnt0++;} else {cnt1++;}
        if (b[i] == '0') {cnt0++;} else {cnt1++;}
        ans += min(cnt1, cnt0);
        if (i != 0) {
            if (equal(a[i],a[i-1])) {
                ans += i * min(cnt1, cnt0);
            } else {
                ans += i * (min(cnt1, cnt0) - 1);
            }
            if (equal(b[i] ,b[i-1])) {
                ans += i * min(cnt1, cnt0);
            } else {
                ans += i * (min(cnt1, cnt0) - 1);
            }
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