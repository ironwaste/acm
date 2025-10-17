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

// 补题——题目链接: https://codeforces.com/contest/2162/problem/D
// 网址：
// 2025.10.17——23:02:58
/*
 * 先知道 长度
 *
 *
*/

i64 ask(i64 p, i64 l, i64 r) {
    cout << p << " " << l << " " << r << endl;
    cout.flush();

    i64 k;
    cin >> k;
    return k;
}

void answer(i64 l, i64 r) {
    cout << "! " << l << " " << r << endl;
    cout.flush();
    return;
}


void solve() {
    i64 n;
    cin >> n;
    i64 len = 0, l = 1, r = n;
    len = ask(2, 1, n) - ((1 + n) * n / 2);
    // deb(len);
    i64 ansl = 1, ansr = n;
    while (l <= r) {
        i64 mid = (l + r) >> 1;
        i64 ori = ask(1, l, mid);
        i64 nxt = ask(2, l, mid);
        i64 v = nxt - ori;
        // de(ori)de(nxt)deb(v);
        // de(r - l + 1)deb(len);

        if (v == 0) {
            l = mid + 1;
        } else if (v == len) {
            r = mid - 1;
        } else if (v > 0 && v < len) {
            ansl = mid - v + 1;
            ansr = mid + len - v;
            answer(ansl, ansr);
            // break;
            return;
        }
    }
    answer(l, l + len - 1);
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