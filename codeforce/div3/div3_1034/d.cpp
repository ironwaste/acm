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

// 2025.08.17——19:33:47
// 2025.08.17——19:43:28 accpted
/*
 * 8 4
 * 10101010
 * 11111010
 * 00011000
 * 可是为什么呢？
*/

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // 判断0的区间数 
    i64 cnt1 = 0, cnt0 = 0;
    for (int i = 0;i < n;i ++) {
        if (s[i] == '1') {
            cnt1++;
        }
    }
    if (cnt1 <= k || k * 2 > n) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
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