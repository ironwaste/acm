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
 
// 补题——题目链接: https://codeforces.com/problemset/problem/1033/B
// 网址：
// 2025.09.19——14:36:37
// 2025.09.19——14:42:34
/*
 * 这题我觉的挺好的 可以当作是埃氏筛对于区间筛关键点的引入
 * 为了知道可以只用筛到 sqrt(n)的地步就可以
 *
*/
const i64 N = 1e6 + 10;
i64 isnp[N];
vector<i64>pri;
void init() {
    for (int i = 2;i < N;i ++) {
        if (!isnp[i]) { pri.push_back(i); }
        for (auto p : pri) {
            if (i * p >= N)break;
            isnp[i * p] = 1;
            if (i % p == 0)break;
        }
    }
}


void solve() {
    i64 a, b;
    cin >> a >> b;
    if (a - b != 1) {
        cout << "NO\n";return;
    }
    i64 v = a + b;
    i64 ok = 1;
    for (auto p : pri) {
        if (v <= p)break;
        if (v % p == 0)ok = 0;
    }
    cout << ((ok) ? "YES" : "NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}