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

// 2025.08.14——12:52:51
// 2025.08.14——12:58:17 wa
/*
 *
 *
 *
*/
i64 c_to_num(char c) {
    return c - '0';
}

void solve() {
    string s;
    cin >> s;
    i64 a1 = c_to_num(s[0]), a2 = c_to_num(s[2]);
    if (s[1] == '+' || s[1] == '*') {
        if (a1 == a2) cout << "No" << endl;
        else cout << "Yes" << endl;
    } else {
        if (a1 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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