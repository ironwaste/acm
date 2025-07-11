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

const i64 ck = 5;
i64 Rand(i64 mod) {

    i64 ans = LLONG_MAX/40000LL;
    // rand() -> [0, 2 ^ 16 - 1 ( 32767 )];
    return ans = (ans * rand()) % mod + 1;
}
i64 Rand0(i64 mod) {

    i64 ans = LLONG_MAX/40000LL;
    // rand() -> [0, 2 ^ 16 - 1 ( 32767 )];
    return ans = (ans * rand()) % (mod + 1);
}

// auto gen = [&](i64 i) -> void {
    // for (int i = 0;i < n;i ++) {
    // p = Rand(ck), a = Rand(ck), b = Rand0(ck);
    // q = Rand(ck), c = Rand(ck), d = Rand0(ck);
    // m = Rand(ck), t = Rand(ck);
    // };
// printf("%lld %lld %lld %lld %lld %lld %lld %lld \n", p, a, b, q, c, d, m, t);
// struct _timeb T;
// _ftime(&T);
// srand(T.millitm);


/*
random_shuffle()
std::default_random_engine(seed)
用于打乱数组顺序
*/
int main() {

    struct _timeb T;

    _ftime(&T);
    /* 更改随机种子 */
    srand(T.millitm);

    // shuffle 专属种子生成器
    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // std::default_random_engine generator(seed);


    // cout << ck << endl;
    i64 p, b, c, d, q, m, t;
    i64 n = 10;
    vector<i64>a(n,0);
    // vector<i64>choose();
    auto gen = [&]() -> bool {
        m = Rand0(n);
        vector<i64>choose(m,0);
        iota(all(choose), 0);
        for (i64 i = 0;i < m;i++) {
            a[i] = choose[i];
        }
        for (int i = m;i < n;i++) {
            a[i] = Rand0(m-1LL);
        }
        shuffle(a.begin(), a.end(), std::default_random_engine(seed));
        return true;
        };
    while (!gen()) {
    }

    printf("%lld %lld\n", n, m);
    for (i64 i = 0;i < n;i ++) {
        printf("%lld ",a[i]);
    }printf("\n");


    return 0;
}