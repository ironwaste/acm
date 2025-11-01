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
// 2025.10.28——22:37:36
/*
 *
 *
 *
*/

void solve() {
    i64 n;
    map<char, i64>mp;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0;i < n;i ++) {
        mp[s[i]]++;
    }
    cin >> s;
    for (int i = 0;i < n;i ++) {
        mp[s[i]]--;
        if (mp[s[i]] == 0) {
            mp.erase(s[i]);
        }
    }
    cout << ((mp.size()) ? "NO" : "YES") << endl;


    

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