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

// 2025.07.22——22:36:02
/*
 *
 *
 *
*/

void solve(){
    string s;
    cin >> s;
    map<char, i64>mp;
    for (auto c : s) {mp[c]++;}
    // string ans = "";
    for (auto [x,cnt] : mp) {
        if (x == 'F' || x =='N') {continue;}
        while (cnt) {
            cnt--;
            cout << x;
        }
    }

    i64 cnt = mp['F'];
    for (int i = 0;i < cnt;i ++) {
        cout << 'F';
    }

    cnt = mp['N'];
    for (int i = 0;i < cnt;i ++) {
        cout << 'N';
    }
    cout << endl;
}
// 2025.07.22——22:40:30 accpted

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