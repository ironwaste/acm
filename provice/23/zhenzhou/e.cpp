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
// 2025.11.18——19:55:22
/*
 *
 *
 *
*/

const int N = 1e5 + 10;

int n, m;

vector<int> g[N];

void solve() {
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> d(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
        d[u] ++, d[v]++;
    }

    i64 ans = 0;
    vector<i64>ans1;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != 1)
            ans = max(ans, a[i]);
        else {
            ans1.push_back(a[i]);
        }
    }
    sort(all(ans1), greater<i64>());
    if(ans1.size() >= 2)ans = max(ans, ans1[1]);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}