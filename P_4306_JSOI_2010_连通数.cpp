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
#define N 2005
using namespace std;


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: https://www.luogu.com.cn/problem/P4306
// 网址：
// 2025.11.11——16:40:27
/*
 * 2e3
 * 4e6
 * 8e9 /32
 * 8e8
 * 2e8
 *
*/

void solve() {
    unsigned int n;
    cin >> n;
    bitset<N>g[N];
    
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            char c;
            cin >> c;
            g[i][j] = (i64) (c - '0');
        }
        g[i][i] = 1;
    }


    i64 sum = 0;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if(g[j][i])g[j] |= g[i];
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            // sum += g[i][j];
            if (g[i][j])sum++;
        }
    }
    cout << sum << endl;

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