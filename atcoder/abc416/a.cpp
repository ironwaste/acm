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

// 2025.07.26——20:00:52
// 2025.07.26——20:02:58 wa???!!!
// 2025.07.26——20:03:31 wa!! YES 是小写
// 2025.07.26——20:05:58 accpted
/*
 *
 *
 *
*/

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--;
    string s;
    cin >> s;
    for (int i = l;i <= r;i++) {
        if (s[i] != 'o') {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
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