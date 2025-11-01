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


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接:
// 网址：
// 2025.11.01——20:03:23
/*
 *
 *
 *
*/



void solve() {
    i64 n, m;
    cin >> n >> m;
    // # is  1, . is 0 bit
    vector<string>s(n);
    for (int i = 0;i < n;i++) { cin >> s[i]; }


    set<vector<i64>>ans;

    i64 yn = n - m;
    for (int i = 0;i <= yn;i ++) {
        for (int j = 0;j <= yn;j++) {
            vector<i64>test;
            for (int x = i;x < i + m;x ++) {
                
                for (int y = j;y < j + m;y++) {
                    test.push_back(s[x][y] == '#');
                }
            }
            ans.insert(test);

        }
    }
    cout << ans.size();


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}