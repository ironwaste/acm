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

// 2025.07.12——20:08:40
/*
 * 一位 十进制下 9 10^1
 * 两位 十进制下 9（11，22，33，44，55，66，77，88，99）
 * 三位 十进制下 90（101，111，121）100 - 200 10位
 * 四位 十进制下 90
 * 五位 十进制下 900
 * 六位 十进制下 900
 * 七位 十进制下 9000
 * 八位 十进制下 9000
 *
 * 九位 十进制下 90000
 * 十位 十进制下 90000
 * 1e6 种
 * 十一位 十进制下 900000
 * 十二位 十进制下 9*10*10*10*10*10== 9e5 约等于1e6
 * 最后两位 有1e7种
 * 总数为 1300000 种
 * 2e6 + 6
 *
 * 遍历所有的10进制下的回文数子，先遍历位数
 * 然后根据当前的位数来 通过前后位数来进行计算值
 * 比如 4位则，
 * i = 0，1 {，j = n - i - 1;}
 * num ->[0,1,2,3,4,5,6,7,8,9]
 * 除了首位不存在0 ，其他位置都可以存在10个数字进行遍历
 */

vector<i64>a(9);
vector<i64>palin(9);

i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1LL) res = res * a;
        a = a * a;
        b >>= 1LL;
    }
    return res;
}

// 2 0 1
// 3 0 1 
void dfs(i64 n, i64 pos, i64 v,i64 N) { // n / 2 == 1e6 *(4)
    // 最高位数 n,pos当前位置也就是设置数字的位置
    // v 是当前的数字总值
    if (v > N)return;
    if (pos * 2 >= n) { palin.pb(v);return; }
    for (i64 num = 0;num < 10;num++) {
        if (pos == 0 && num == 0)continue;
        if (n % 2 == 1 && pos * 2 + 1LL == n) {
            dfs(n, pos + 1, v + num * pw(10LL, n - pos - 1LL),N);
        } else {
            dfs(n, pos + 1, v + num * (pw(10LL, n - pos - 1LL) + pw(10LL, pos)),N);
        }
    }

    
}
void init(i64 N) {
    iota(all(palin), 1);
    auto palin = a;
    i64 n = log10(N) + 1;
    // deb(n);
    n = min(12LL, n);
    for (int i = 2;i <= n;i++) {
        dfs(i, 0, 0,N);
    }
}

i64 check(i64 a, i64 A) {
    i64 t = a;
    vector<i64>num;
    while(a) {
        num.pb(a % A);
        a /= A;
    }
    i64 n = num.size(),ok = 1;
    for (int i = 0;i < n / 2;i ++) {
        if (num[i] != num[n - i - 1]) { ok = 0; break; }
    }
    if (ok) {
        // deb(t);
        return t;
    } else {
        return 0LL;
    }
}

void solve() {
    i64 A, n = 1e12;
    cin >> A >> n;
    init(n);
    i64 ans = 0;
    for (auto x : palin) {
        if (x > n)break;
        ans += check(x, A);
    }
    cout << ans << endl;

}
// 2025.07.12——21:02:58 dfs 用时过多但是型号没错误
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}