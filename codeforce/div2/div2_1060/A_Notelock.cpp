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
 
// 补题——题目链接: https://codeforces.com/contest/2154/problem/A
// 网址：
// 2025.10.19——22:36:38
// 2025.10.19——22:40:25
/*
 *
 *
 *
*/

void solve() {
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    i64 prx = -k;
    i64 ans = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == '1' && prx + k - 1 < i) {
            ans++;
        }
        if (s[i] == '1') {
            prx = i;
        }
    }
    cout << ans << endl;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}