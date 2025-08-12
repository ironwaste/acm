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

using pii = pair<int, int>;
using pll = pair<i64, i64>;

template <const i64 MOD>
struct ModInt {
    i64 x;
    ModInt(i64 n = 0) {
        x = n % MOD;
        if (x < 0) x += MOD;
    }
    ModInt<MOD> pw(i64 k) {
        ModInt<MOD> res = 1;
        ModInt a = *this;
        while (k) {
            if (k & 1) res *= a;
            a *= a;
            k /= 2;
        }
        return res;
    }
    ModInt<MOD> inv() { return pw(MOD - 2); }
    friend ModInt<MOD> operator+(ModInt<MOD> a, ModInt<MOD> b) { return (a.x + b.x) % MOD; }
    friend ModInt<MOD> operator-(ModInt<MOD> a, ModInt<MOD> b) { return (a.x + MOD - b.x) % MOD; }
    friend ModInt<MOD> operator*(ModInt<MOD> a, ModInt<MOD> b) { return (a.x * b.x) % MOD; }
    friend ModInt<MOD> operator/(ModInt<MOD> a, ModInt<MOD> b) { return a * b.inv(); }
    friend bool operator<=(ModInt<MOD> a, ModInt<MOD> b) { return a.x <= b.x; }
    friend bool operator<(ModInt<MOD> a, ModInt<MOD> b) { return a.x < b.x; }
    friend bool operator>=(ModInt<MOD> a, ModInt<MOD> b) { return a.x >= b.x; }
    friend bool operator>(ModInt<MOD> a, ModInt<MOD> b) { return a.x > b.x; }
    friend bool operator==(ModInt<MOD> a, ModInt<MOD> b) { return a.x == b.x; }
    friend ostream& operator<<(ostream& out, const ModInt<MOD>& a) { return out << a.x; }
    friend istream& operator>>(istream& in, ModInt<MOD>& a) { i64 n;in >> n;a = ModInt<MOD>(n); return in; }
    ModInt<MOD>& operator+=(const ModInt<MOD>& a) { *this = *this + a;return *this; }
    ModInt<MOD>& operator-=(const ModInt<MOD>& a) { *this = *this - a;return *this; }
    ModInt<MOD>& operator*=(const ModInt<MOD>& a) { *this = *this * a;return *this; }
    ModInt<MOD>& operator/=(const ModInt<MOD>& a) { *this = *this / a;return *this; }
};
using mint = ModInt<998244353>;
// 2025.08.12——16:23:07
/*
 *
 *
 *
*/

i64 c_to_num(char c) {
    return c - '0';
}
const i64 mon[7] = { 1,3,5,7,8,10,12 };
i64 jud_m(int month, i64 v) {

    if (month == 2) {
        if (v == 1)return 1LL;
        else return 0LL;
    }
    for (int i = 0;i < 7;i++) {
        if (month == mon[i]) {
            return 3LL;
        }
    }
    return 2LL;
}



// 年份判断闰年 只需要 前两位 如果是4的倍数则出 1
// 如果不是则出零
// 当我们 查询 后两位 年份的时候
// 当我们 后两为 为 0的时候，则其遵循之前的闰年值
// 而为 4的倍数的时候 则直接变为闰年
// 
// 当检查月份， 直接返回 
// 数组最后一位代表的是 最多容纳最后两位数字为多少

// i64 jud_y(i64 prey ,i64 year) {
// }



void solve() {
    int n;string s;
    cin >> n;
    cin >> s;
    vector<vector< vector<mint > > >dp(10, vector<vector<mint> >(110, vector<mint>(4, 0)));
    // 字符长度 ， 最后两位数字， 是否是闰月
    // 1 是  是闰月
    for (int i = 0;i < n;i++) {
        i64 v = c_to_num(s[i]);
        vector<vector< vector<mint > > >ndp(10, vector<vector<mint> >(110, vector<mint>(4, 0)));
        auto dd = [&](i64 len, i64 vv, i64 bo)->void {
            de(len)de(vv)de(bo)deb(ndp[len][vv][bo]);
            };
        // 0 , 1 , 2, 3, ,4 , 5 ,6 , 7, 8;
        for (int len = 0;len < min(i+1,8);len++) {

            if (len == 0) {
                ndp[len + 1][v][0] = dp[len][0][0] + 1LL;
            } else if (len == 1) {
                // 10
                for (int vv = 0;vv < 10;vv++) {
                    i64 nxv = vv * 10 + v;
                    if (nxv % 4 == 0 && nxv != 0) {
                        ndp[len + 1][nxv][1] = dp[len][vv][0] + dp[len][vv][1];
                    } else {
                        ndp[len + 1][nxv][1] = dp[len][vv][1];
                        ndp[len + 1][nxv][0] = dp[len][vv][0];
                        dd(len + 1, nxv, 1);
                        dd(len + 1, nxv, 0);
                    }
                }
            } else if (len == 2) {
                // 200
                for (int bo = 0;bo < 2;bo++) {
                    for (int vv = 0;vv < 100;vv++) {
                        ndp[len + 1][v][bo] += dp[len][vv][bo];
                    }
                }
            } else if (len == 3) {
                // 100 
                for (int vv = 0;vv < 10;vv++) {
                    i64 nxv = vv * 10 + v;
                    if (nxv % 4 == 0 && nxv != 0) {
                        ndp[len + 1][nxv][1] += dp[len][vv][1] + dp[len][vv][0];
                    } else if (nxv == 0) {
                        ndp[len + 1][nxv][1] += dp[len][vv][1];
                        ndp[len + 1][nxv][0] += dp[len][vv][0];
                    } else {
                        ndp[len + 1][nxv][0] += dp[len][vv][1];
                        ndp[len + 1][nxv][0] += dp[len][vv][0];
                    }
                }
            } else if (len == 4) {
                if (v > 2)continue;
                for (int vv = 0;vv < 100;vv++) {
                    ndp[len + 1][v][0] += dp[len][vv][0];
                    ndp[len + 1][v][1] += dp[len][vv][1];
                }
            } else if (len == 5) {

                for (int vv = 0;vv < 10;vv++) {
                    i64 nxv = vv * 10 + v;
                    if (nxv > 12)break;
                    for (int bo = 0;bo < 2;bo++) {
                        i64 nxbo = jud_m(nxv, bo);
                        ndp[len + 1][nxv][nxbo] += dp[len][vv][bo];
                    }

                }


            } else if (len == 6) {

                for (int vv = 0;vv < 13;vv++) {
                    ndp[len + 1][v][0] += dp[len][vv][0];
                    ndp[len + 1][v][1] += dp[len][vv][1];
                    ndp[len + 1][v][2] += dp[len][vv][2];
                    ndp[len + 1][v][3] += dp[len][vv][3];
                }
            } else if (len == 7) {
                for (int vv = 0;vv < 4;vv++) {
                    i64 nxv = vv * 10 + v;
                    ndp[len + 1][nxv][0] += dp[len][vv][0];
                    ndp[len + 1][nxv][1] += dp[len][vv][1];
                    ndp[len + 1][nxv][2] += dp[len][vv][2];
                    ndp[len + 1][nxv][3] += dp[len][vv][3];
                }
            }
        }
        dp = ndp;
    }
    mint ans = 0;
    vector<i64>a(4,0);
    a = { 28,29,30,31 };
    for (int i = 0;i < 4;i++) {
        for (int vv = 1;vv <= a[i];vv++) {
            ans += dp[8][vv][i];
        }
    }
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}