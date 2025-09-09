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


// 补题——题目链接:
// 网址：
// 2025.09.09——22:36:17
// 2025.09.09——22:44:44
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    i64 cnt1 = 0,ans = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == '1') { cnt1++; }
    }
    for (int i = n - 1;i >= n - cnt1;i -- ) {
        if (s[i] != '1') {
            ans++;
        }
    }


    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}