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

// 补题——题目链接: https://codeforces.com/contest/2170/problem/D
// 网址：
// 2025.11.28——23:20:24
/*
 * 1. I?  -> sum -= 2
 * 2. ?X / ? V -> -1
 * 3. ?? -> iV 4 iX 9
 * 4. ，没有了
 * 我和答案的思维差别在于， 我对于后续的代码实现 我先根据？ 个数来判断
 * I V X 分别的个数 而后再贪心的排列组合
 *
 * 答案的思路不同 ， 其假设？ 全部为I 的情况下最小（我也是这样想的）
 * 但是不同的是其将其 所有的 I 直接预设到 其中
 * 而后再更换  V 其中 最关键的部分在于 替换 I 成为 V 的顺序
 *
 * 1、 增加 IV 对的数量 因为 这样     2 -> 4  + 2
 * 2、 不改变IV的数量  如 IIV -> IVV   5->9  + 4
 * 3、 减少 IV 数量                         + 6
 *
 * 等待 更改完成 V 之后 再更改 X 的话 就无需考虑了，
 * 换句话说 更改完 X + V 的情况后 就无所谓了 直接对于最后所需的X 值进行
 * 相加即可
 * V 更改成为 X 只在数值上更改了 +5
*/

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    i64 ans = 0;
    for (auto& c : s) {
        if (c == 'X') {
            c = 'V';
            ans += 10;
        } else if (c == 'V') {
            ans += 5;
        } else {
            ans += 1;
        }
    }
    i64 inc = 0, same = 0, num = 0;
    for (int i = 0, r = 0;i < n;i++) {
        if (s[i] != '?') { continue; }
        r = i;
        int len = 0;
        while (r < n && s[r] == '?') { r++; }
        len = r - i;
        if (i - 1 >= 0 && s[i - 1] == 'I') { len++; }
        if (r < n && s[r] == 'V') { inc--;len++; }
        same += len % 2;
        inc += len / 2;
        num += r - i;
        i = r - 1;
    }


    for (int i = 0;i < n;i++) {
        if (s[i] == '?') { s[i] = 'I'; }
        if (s[i] == 'I' && i + 1 < n && s[i + 1] == 'V') { ans -= 2; }
    }

    while (q--) {
        i64 cx, cv, ci;
        cin >> cx >> cv >> ci;
        if (ci >= num) { cout << ans << endl; continue; }

        i64 need = num - ci;
        i64 nv = min(need, cv);
        i64 nx = max(0LL, need - nv);

        i64 tmpans = ans;
        tmpans += min(need, inc) * 2LL;
        need = max(need - inc, 0LL);
        tmpans += min(same, need) * 4LL;
        need = max(need - same, 0LL);
        tmpans += need * 6LL;
        tmpans += 5LL * nx;
        cout << tmpans << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        // deb(T)
        solve();
    }
    return 0;
}