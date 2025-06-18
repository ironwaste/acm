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

const i64 ck = 1e9;
i64 Rand(i64 mod) {

    i64 ans = LLONG_MAX/40000;
    // rand() -> [0, 2 ^ 16 - 1 ( 32767 )];
    return ans = (ans * rand()) % mod + 1;
}
i64 Rand0(i64 mod) {

    i64 ans = LLONG_MAX/40000;
    // rand() -> [0, 2 ^ 16 - 1 ( 32767 )];
    return ans = (ans * rand()) % (mod + 1);
}

int main(){

    struct _timeb T;

    _ftime(&T);
    srand(T.millitm);
    // cout << ck << endl;
    i64 p, a, b, c, d, q, m, t;
    auto gen = [&]() -> void {
        p = Rand(ck), a = Rand(ck), b = Rand0(ck);
        q = Rand(ck), c = Rand(ck), d = Rand0(ck);
        m = Rand(ck), t = Rand(ck);
        };
    gen();
    while(p >= q) {
        gen();
    }
    printf("%lld %lld %lld %lld %lld %lld %lld %lld \n", p, a, b, q, c, d, m, t);

    return 0;
}