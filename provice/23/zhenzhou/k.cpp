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

// 补题——题目链接:
// 网址：
// 2025.11.18——20:52:13
/*
 *
 *
 *
*/

void solve(){
    i64 n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    for (int i = 0;i < n;i ++) {
        if (a[i] == '1' ||b[i] =='1') {
            continue;
        }
        cout << 0;
        return;
    }

    cout << 1;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}