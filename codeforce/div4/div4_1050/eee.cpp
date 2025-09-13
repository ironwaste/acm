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

// 2025.09.13——23:25:40
/*
 *
 *
 *
*/

void solve() {
    i64 n, mxk = 0;;
    cin >> n;
    vector<vector<i64> >a(n);
    for (int i = 0;i < n;i++) {
        i64 k;
        cin >> k;
        mxk = max(k, mxk);
        a[i].push_back(k);
        for (int j = 0;j < k;j++) {
            i64 x;cin >> x;
            a[i].push_back(x);
        }
    }
    // vector<priority_queue<pll>>q[mxk];



    i64 idx1 = 1;

    for (;idx1 <= mxk;) {
        sort(a.begin(), a.end(),
            [&](const vector<i64>& vec1, const vector<i64>& vec2) {
                i64 k1 = vec1[0], k2 = vec2[0];
                if (k1 < idx1)return false;
                if (k2 < idx1)return true;
                i64 mi = min(k1, k2);
                for (int i = idx1;i <= mi;i++) {
                    if (vec1[i] < vec2[i])return true;
                    else if (vec1[i] > vec2[i])return false;
                }
                // 所有值都相同的情况 短的在前
                if (k1 <= k2)return true;
                else return false;
            });
        i64 k = a[0][0];
        for (;idx1 <= k;idx1++) {
            cout << a[0][idx1] << " ";
        }
        if (idx1 > mxk)break;
    }cout << endl;
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