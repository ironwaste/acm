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

// 2025.08.05——14:37:28
/*
 *
*/
i64 pw(i64 a, i64 b) {  
    i64 res = 1LL;
    while (b) {
        if (b & 1) res = res * a % mod3;
        a = a * a % mod3;
        b >>= 1;
    }
    return res;
}
const int MAXN = 30;
struct big {
    i64 bit[MAXN];
    i64 num = 0;
    void clear() {
        num = 0;
        for (int i = 0;i < MAXN;i++) {
            bit[i] = 0;
        }
    }
    void read(i64 x) {
        while (x) {
            bit[this.num++] = x % 10;
            x /= 10;
        }
    }
}Big;

Big mul(Big a, Big b) {
    big c;
    c.clear();
    for (int i = 0;i < a.num;i++) {
        for (int j = 0;j < b.num;j ++) {
            c[i + j] = a[i] * b[j];
            i64 cnt = i + j;
            while (c[cnt] >= 10) {
                c[cnt + 1] = c[cnt] / 10;
                c[cnt ++] %= 10LL;
            }
        }
    }

}
// bool cmp(Big a, Big b) {




// }

// void init() {

    
// }
void solve() {
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;



    
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