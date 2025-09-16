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

using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 2025.09.15——22:36:15
/*
 *
 *
 *
*/
// 1 1 1
// 1 0 2
// 3 3 1 2
void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    vector<i64>prx(n);
    partial_sum(all(a),prx.begin());
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            i64 v1 = prx[i], v2 = prx[j] - prx[i];
            i64 v3 = prx[n - 1] - prx[j];
            v1 %= 3;
            v2 %= 3;
            v3 %= 3;
            if ((v1 == v2 && v2 == v3)
                || (v1 != v2 && v1 != v3 && v2 != v3)) {
                cout << i + 1<<" " << j + 1 << endl;
                return;

            }
        }
    }
    cout << "0 0" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}