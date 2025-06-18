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
// 高精度模板 
// https://www.cnblogs.com/PegasusWang/archive/2013/03/23/2977610.html

constexpr i64 MAXSIZE = 1e4 + 10;
constexpr i64 DLEN = 10; // 压位位数
constexpr i64 MAXN = 999999999; // 压位过后的一位中可以存储的最大的数字

struct big {
    int a[MAXSIZE], len;
    bool flag;
    big() {
        len = 1;
        memset(a, 0, sizeof a);
        flag = false;
    }
    big(const i64);
    big(const char*);
    big(string);
    big &operator=(const big&);
    big operator+(const big&)const;
    i64 operator%(const i64&)const;

    friend big operator+(big a, i64 b) {
        a.a[0] += b;
        return fix(a);
    }
    static big fix(big a){
	    // 高精度进位调整 
	    for(int i=1;i < a.len;++ i){
		    a.a[i+1] += a.a[i]/(MAXN+1LL);
		    a.a[i]%=(MAXN+1LL);
        }
        if (a.a[len]) { a.len++; }
        return a;
    }

};
big::big(const i64 b) {
    i64 c, d = b;
    len = 0;
    big();
    while (d > MAXN) {
        c = d - (d / (MAXN + 1) * (MAXN + 1));
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
big::big(const char* s) {
    i64 t, k, index, l;
    l = strlen(s);
    big();
    len = l / DLEN;

    if (l % DLEN) ++len;

    index = 0;
    for (int i = l - 1;~i;i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if (k < 0) k = 0;
        for (i64 j = i;j >= k;j--) {
            t = t * 10 + s[j] - '0';
        }
        a[index++] = t;
    }
}

big::big(string s) {
    i64 t, k, index, l;
    l = s.size();
    big();
    len = l / DLEN;

    if (l % DLEN) ++len;

    index = 0;
    for (int i = l - 1;~i;i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if (k < 0) k = 0;
        for (i64 j = i;j >= k;j--) {
            t = t * 10 + s[j] - '0';
        }
        a[index++] = t;
    }
}

big& big::operator=(const big& T) {
    big();
    len = T.len;
    for (int i = 0;i < len;i ++) {
        a[i] = T.a[i];
    }
    return *this;
}
big big::operator+(const big& T)const {
    big t(*this);
    i64 bg = len;
    if (T.len > len) bg = T.len;
    for (int i = 0;i < bg;i ++) {
        t.a[i] += T.a[i];
        if (t.a[i] > MAXN) {
            ++t.a[i + 1];
            t.a[i] -= MAXN + 1;
        }
    }
    if (t.a[bg]) {
        t.len = bg + 1;
    } else {
        t.len = bg;
    }
    return t;
}
i64 big::operator%(const i64 &mod)const {
    i64 d = 0;
    for (int i = len - 1;~i;i--) {
        d = (d * (MAXN + 1LL) + a[i]) % mod;
    }
    return d;
}

void print(const big &s) {
    i64 len = s.len;
    printf("%d", s.a[len - 1]);
    for (int i = len - 2;~i;i --) {
        printf("%04d", s.a[i]);
    }
    printf("\n");
}

void solve(){
    string n,m;
    i64 ans = 0;
    cin >> n >> ans;
    m = to_string(ans);
    big k;
    k = big(n);
    print(k);
    // case1 包含 字串情况
    // 1、 非末尾 直接+1输出
    // 2、末尾则不管 跳过
    // i64 index = n.find(m);
    // i64 szn = n.size(), szm = m.size();
    // if (index + szm != szn) {
    //     big tmp = big(1LL);
    //     k = k + tmp;
    // }
    // case2 倍数关系 ： 求余数 并且将（m - 余数）
    // 高精度 -> 
    // case3 按照位数找字串相同数最多的 ： 
    // 

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        deb(T)
        solve();
        deb('n');

    }
    return 0;
}