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

// 2025.07.28——12:26:58
// 2025.07.28——12:43:07 accepted
/*
 * 题目意思 ： 就是算不是0的正整数的区间
 * 
 *
*/
const int N = 2e5 + 10;
i64 fra[N];
void init() {
    fra[1] = 1;
    for (int i = 2;i < N;i++) {
        fra[i] = (fra[i - 1] + i) % mod3;
    }
}
void solve() {
    i64 n,l = -1,r,mi = INT_MAX,mx = INT_MIN;
    cin >> n;
    r = - 1;
    vector<i64>a(n);
    i64 sum = 0;
    for (auto& x : a) {
        cin >> x;
        sum += x;
        if (x != 0) {
            mx = max(mx, x);
            mi = min(mi, x);
        }
    }

    for (int i = 0,j=n-1;i < n;i ++,j--) {
        if (a[i] != 0 && l== -1) {
            l = i;
        }
        if (a[j] != 0 && r == -1) {
            r = j;
        }
    }
    i64 L = mi + n + 1LL, R = n - mx + 1LL;
    if (l == -1 && r == -1) {
        l = fra[n], r = 1LL;
        L = n + 1LL, R = n + 1LL;
    } else {
        r = n - r ;
        l = l + 1LL;
    }
    de(l)de(r)de(L)deb(R);
    cout << sum << " " << L * R % mod3 * r % mod3 * l  % mod3 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}