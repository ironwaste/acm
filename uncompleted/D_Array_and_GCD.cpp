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
// 2025.09.19——11:45:20
// 2025.09.19——11:54:28 accpted
/*
 *
 *
 *
*/
const i64 N = 1e7 + 10;
const i64 SUM = 4e14 + 100;
i64 isnotp[N];
vector<i64>pri,prx;
void init() {
    i64 sum = 0;
    for (i64 i = 2;i < N && sum < SUM;i++) {
        if (!isnotp[i]) { pri.push_back(i); }
        for (auto p : pri) {
            if (p * i >= N)break;
            isnotp[p * i] = 1;
            if (i % p == 0)break;
        }
    }
    i64 n = pri.size();
    prx.resize(n + 1);
    partial_sum(all(pri), prx.begin() + 1);
}



void solve() {
    i64 n;
    cin >> n;
    i64 sum = 0;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x;sum += x; }
    sort(all(a));
    i64 cnt = n;
    for (int i = 0;i < n - 1;i++) {
        if(sum >= prx[cnt]){break;}
        sum -= a[i];
        cnt--;
    }

    cout << n - cnt << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}