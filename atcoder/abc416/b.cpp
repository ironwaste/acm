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

// 2025.07.26——20:06:07
// 2025.07.26——20:12:07 wa
// 2025.07.26——20:23:02 wa
// 2025.07.26——20:23:04 accpted
/*
 *
 *
 *
*/

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    stack<pair<char,int> >stk;
    // string t = "";
    for (int i = 0;i < n;i++) {
        if (stk.empty() && s[i] == '.') {
            stk.push({ s[i], i });
            s[i] = 'o';
        } else if (!stk.empty()) {
            if (stk.top().fi == s[i]) {
                continue;
            } else if (stk.top().fi == '.' && s[i] == '#') {
                stk.push({ s[i],i });
            } else if (stk.top().fi == '#' && s[i] == '.') {
                stk.pop();
                i64 pos = stk.top().se;
                stk.pop();
                s[pos] = 'o';
                stk.push({ s[i],i });
                s[i] = 'o';
            }
        }
    }


    cout << s << endl;


    

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