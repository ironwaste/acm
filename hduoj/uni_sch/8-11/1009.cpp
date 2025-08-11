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
// 2025.08.11——13:35:42
/*
 * 压位高精 + 等差和 * 等差 公式推导
 * 最大在 1e36 所以 应该开 40 以上，
 * 因为 (1 + 1e12) * 1e12 会 进行 5e11 次 
*/
i64 pw(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = a * res;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const int MAXN = 9, N = 100;
const i64 MX = 1e9;
struct BIT {
    i64 v[N];
    i64 num = 0;
    void init() {
        for (int i = 0;i < num;i++) { this->v[i] = 0; }
        this->num = 0;
    }
};
BIT trans(i64 a){
    BIT res;
    res.init();
    while (a) {
        res.v[res.num++] = a % MX;
        a /= MX;
    }
    return res;
}
BIT add(BIT a, BIT b) {
    BIT res;
    res.init();
    i64 num = max(a.num, b.num);
    for (int i = 0;i < num;i++) {
        res.v[i] += a.v[i] + b.v[i];
        res.v[i + 1] += res.v[i] / MX;
        if (res.v[i]) res.num = i;
        if (res.v[i + 1]) res.num = i + 1;
        res.v[i] = res.v[i] % MX;
    }
    return res;
}
BIT sub(BIT a, BIT b) {
    BIT res;
    res.init();
    if (a.num < b.num) { swap(a, b); }
    for (int i = b.num-1;i >=0 ;i --) {
        a.v[i] -= b.v[i];
        if (a.v[i] < 0) {
            a.v[i + 1] -= 1;
            a.v[i] = MX - a.v[i];
        }
    }
    return a;
}
BIT mul(BIT a, BIT b) {
    BIT res;
    res.init();
    for (int i = 0;i < a.num;i++) {
        for (int j = 0;j < b.num;j ++) {
            res.v[i + j] += a.v[i] * b.v[j];
            res.num = i + j;
        }
        int j = 0;
        while (res.v[j]) {
            res.num = j;
            res.v[j + 1] += res.v[j + 1] / MX;
            res.v[j] %= MX;
            j++;
        }
    }
    return res;
}
BIT div(BIT a, i64 b) {
    BIT res;
    res.init();
    i64 rem = 0;
    for (int i = a.num - 1;i >= 0;i--) {
        rem = rem * MX + a.v[i];
        res.v[i] = rem / b;
        rem %= b;
    }
    return res;
}

void print(BIT a) {

    int num = a.num;
    int ok = 0;
    for (int i = num - 1;i >= 0;i--) {
        if (ok && a.v[i]) {
            printf("%lld", a.v[i]);
            ok = 0;
        } else {
            printf("%09lld", a.v[i]);            
        }
    }
    return;
}

void solve() {
    i64 n, w;
    cin >> n >> w;
    // BIT ans;
    ans.init();

    for (i64 i = n,n2,ssub,cnt;i >= w; i = n2) {
        ssub = i / w;
        n2 = i - ssub;
        // de(i)deb(n2);
        cnt = 1;
        if (n2 > ssub * w - 1) {
            n2 = (i - n2 + w - 1) / w;
            cnt = (i - n2) / w;
        }
        // i64 
        // 求全部求和的值
        de(n2)deb(cnt);
        BIT cntv = trans(cnt);
        BIT nn1 = mul(trans(1 + n), trans(n));
        ans = add(ans, mul(div(nn1, 2LL), cntv));
        // de(n2)deb(cnt);

        i64 an = n - n2 + 1;
        BIT tmpa, tmpb, Sub,nn2;
        nn2 = mul(trans(an),trans(an + 1LL));
        tmpa = mul(nn2, trans(2LL * an + 1LL));
        tmpa = mul(cntv, tmpa);
        tmpa = div(tmpa, 6LL);


        Sub = trans(ssub);
        tmpb = mul(div(nn2, 2LL), Sub);
        tmpb = mul(cntv, tmpb);


        ans = sub(ans, tmpa);
        ans = sub(ans, tmpb);
        deb("ans")print(ans);
    }






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