#pragma GCC optimize(2)
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
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;


using pii = pair<int, int>;
using pll = pair<i64, i64>;

// 补题——题目链接: http://qoj.ac/contest/1885/problem/9921
// 网址：
// 2025.11.12——17:36:01
/*
 * 好像是字典树
 * 26 * n;
 * 需要存储一下 什么呢？ 存选一个人 的最长串
 * 且只需要 重新异或被修改的值 然后再异或上 新的值就行
 * 这样修改差不多也就是 常数级的
*/
const i64 SZ = 30;
const i64 MXN = 1e6 + 10;
const i64 MXM = 5e5 + 100;

i64 ans[MXM];
i64 cnt = 1, root = 0;
i64 ANS = 0;
vector<i64>fac[MXM];

struct TireN {
    i64 num;
    i64 son[SZ];
    TireN() { num = 0; };
    TireN(int a) :num(a) {};
}t[MXN];

i64 cton(char c) {
    return c - 'a';
}
void frac() {
    for (int i = 1;i < MXM;i++) {
        for (int j = i;j < MXM;j += i) {
            fac[j].push_back(i);
        }
    }
}

void init() {
    for (int i = 0;i <= cnt;i++) {
        t[i].num = 0;
        for (int j = 0;j < SZ;j++) {
            t[i].son[j] = 0;
        }
    }
    cnt = 1;
    ANS = 0;
    memset(ans, 0, sizeof ans);
}

void insert(string& s) {
    i64 sz = s.size();
    i64 now = 0;
    for (int i = 0;i < sz;i++) {
        i64 ch = cton(s[i]);

        if (t[now].son[ch] == 0) {
            t[now].son[ch] = cnt++;
        }
        now = t[now].son[ch];

        i64 j = ++t[now].num;
        // 多少个字符 有共同前缀
        // 长度为 i
        // 相同的有 j个
        // deb(j)
        for (auto p : fac[j]) {
            ANS ^= ans[p] * p;
            // de(p)
            ans[p]++;
            ANS ^= ans[p] * p;
        }
        // de(i)deb(j);
        // // j 是 个数
        // if (mp.count(j)) {
        //     i64 w = mp[j]; // w 和 i 是 长度
        //     if (i > w) {
        //         ans ^= j * w;
        //         // de("jw")de(ans);
        //         mp[j] = i;
        //         ans ^= j * i;
        //         // deb(ans);
        //     }
        // } else {
        //     ans ^= j * i;
        //     // de("ji")deb(ans);
        //     mp[j] = i;
        // }
    }
}
void solve() {

    i64 n;
    cin >> n;
    string s;
    for (i64 k = 1;k <= n;k++) {
        cin >> s;
        // s = " " + s;
        insert(s);
        cout << ANS << " \n"[k == n];
    }
    init();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    frac();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}