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

using pii = pair<int,int>;
using pll = pair<i64, i64>;

const int N = 1e6 + 10;

void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n),cnt(N,0LL);
    for (auto& x : a) { cin >> x; cnt[x]++; }
    i64 ans = 0LL;
    for (i64 i = 1;i <= n;i ++) {
        for (i64 j = i;j+i <= N;j += i) {
            ans += cnt[j] * cnt[j + i];
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}