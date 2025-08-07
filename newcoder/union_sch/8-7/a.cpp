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

// 2025.08.07——12:03:30
// 2025.08.07——12:07:58
/*
 *
 *
 *
*/

void solve(){
    string s;
    cin >> s;
    int ok = 0;
    if (s[0] != '-') {
        for (auto x : s) {
            if (int(x - '0') >= 1) {
                cout << x;
            } else if (!ok) {
                cout << 1;
                ok = 1;
                cout << x;
            } else {
                cout << x;
            }
        }
    } else {
        int cnt = 0;
        for (auto x : s) {
            if (cnt == 0) {
                cout << '-';
                cnt++;
                continue;
            }
            if (int(x - '0') <= 1) {
                cout << x;
            } else if (!ok) {
                cout << 1;
                ok = 1;
                cout << x;
            } else {
                cout << x;
            }
        }
    }
    if (!ok) {
        cout << 1 << endl;
    } else {
        cout << endl;
    }


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