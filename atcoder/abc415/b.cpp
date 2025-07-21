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

// 2025.07.19——20:11:29
/*
 *
 *
 *
*/

void solve(){
    string s;
    cin >> s;
    i64 n = s.size();
    i64 cnt = 0;
    for (int i = 0;i < n;i++) {
        if (cnt == 0 && s[i] == '#') {
            cnt = i + 1;
        } else if (s[i] == '#') {
            cout << cnt << "," << i + 1LL << endl;
            cnt = 0;
        }
        
    }



}
// 2025.07.19——20:15:08 accpted
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