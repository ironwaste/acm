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

// 补题——题目链接: https://codeforces.com/contest/2169/problem/D1
// 网址：
// 2025.11.14——23:27:30
/*
 * 好像 约瑟夫环 但是 是 同余位循环 的 约瑟夫环
 *
 *
*/

const i64 MX = 1e12;
void solve() {
    i64 x, y, k;
    cin >> x >> y >> k;
    if (y > k) {
        cout << k << endl;
        return;
    } else if (y == 1 && x >= 1) {
        cout << -1 << endl;
        return;
    }
    // i64 res = 1e12, tx = x;
    // i64 sub = res / y;
    // i64 pos = k;
    // while (res >= k && tx >= 0 && pos <= MX) {
    //     // de(tx);
    //     tx--;
    //     res -= sub;
    //     sub = res / y;
    //     pos = pos * y / (y - 1) + (pos % (y - 1));
    // }
    i64 pos = k;
    for (int i = 0; i < x; i++) {
        if (pos >  MX) break;
        i64 a = (pos-1) / (y - 1);
        pos = pos + a;
    }
    if (pos > MX) {
        cout << -1 << endl;
    } else {
        cout << pos << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
1 2 3 4 5 6 7 8 9 10 11 12
y = 3 x = 3;

5 次
0 0 1 0 0 1 0 0 1 0
1 2 x 4 5 x 7 8 x 10 11

3 6 9  -> y  2y  3y

1 2 4 5 7 8 10 11
1 2 x 5 7 x 10 11

4 8  ->  y + 1  2y + 2

1 2 5 7 10 11
1 2 x 7 10 x

5 11  ->  y + 2   2y + 5

1 2 7 10
1 2 x 10

7  y + 4;

1 2 10
1 2 x



y 2y 3 y 4y 5y

y+1 2y + 2 3y + 3 4y + 4

y + 2    3 * (y + 3)

*/