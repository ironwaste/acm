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

inline int read() {
    i64 s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch >'9') { if (ch == '-')w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { s = s * 10 + ch - '0', ch = getchar(); }
    return s * w;
}


// i64 trans(char c) {
//     return (i64)(c - '0');
// }


// 通过读入的处理 将运算方式和代码进行 优化

void solve() {
    int m;
    m = read();
    // getchar();
    while (m--) {
        i64 a = read(), b = read(), c = read();
        // cin >> a >> b >> c;
        // deb(a)deb(b)deb(c);
        (a += c + 24) %= 24;
        printf("%02lld:%02lld\n", a, b);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = read();
    // cin >> T;
    
    while (T--) {
        solve();
    }
    return 0;
}