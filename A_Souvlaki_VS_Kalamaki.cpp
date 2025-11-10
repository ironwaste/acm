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

// 补题——题目链接:
// 网址：
// 2025.11.10——23:05:19
/*
 *
 *
 *
*/

void solve(){
    int n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    sort(all(a));
    i64 ok = 0;
    for (int i = 1;i < n;i += 2) {
        if (i + 1 < n) {
            if (a[i] != a[i + 1]) {
                ok = 1;
            }
        }
    }
    cout << ((ok) ? "NO" : "YES") << endl;
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