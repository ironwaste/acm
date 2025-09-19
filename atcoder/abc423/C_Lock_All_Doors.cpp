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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


using pii = pair<int,int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://atcoder.jp/contests/abc423/tasks/abc423_c
// 网址：
// 2025.09.18——15:13:14
// 2025.09.18——15:21:15 wa 7个
// 2025.09.18——15:26:46
// 2025.09.18——15:31:13 accpted
/*
 *
 *
 *
*/

void solve(){
    i64 n, R;
    cin >> n >> R;
    // R--;
    // R = max(0LL, R);
    vector<i64>L(n + 1, 0);
    i64 l = LLONG_MAX, r = LLONG_MIN;
    for (i64 i = 0;i < n;i++) {
        cin >> L[i];
        if (L[i] == 0) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    // de(l)de(r)
    i64 ans = 0,cnt1 = 0, cnt0 = 0;
    if (l <= r) {
        if (R >= r) {R--;}
        l = min(R, l);
        r = max(R, r);
        for (i64 i = l; i <= r;i++) {
            if (L[i])cnt1++;
            else cnt0++;
        }
    }
    cout << cnt1 * 2 + cnt0 << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}