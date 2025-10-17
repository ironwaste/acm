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

// 补题——题目链接: https://codeforces.com/contest/2162/problem/A
// 网址：
// 2025.10.17——22:36:19
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    vector<i64>a(n);
    for (auto &x : a) {
        cin >> x;
    }
    i64 mi = 0;
    for (int i = 0;i < n;i++) {
        i64 sum = 0;
        for (int j = i;j < n;j ++ ) {
            sum += a[i];
            if (sum /(j-i + 1) > mi) {
                mi = sum / (j - i + 1);
            }
        }
    }
    cout << mi << endl;
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