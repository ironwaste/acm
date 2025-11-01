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

// 补题——题目链接:
// 网址：
// 2025.10.24——23:33:23
/*
 * O（ 32 * n * log (n)）
 * 1 和 所有进行操作 可以确定 所有奇数的位置
 * 可以由此 判断 其奇偶性 和 1 的所在
 * 剩下 的需要我去判断其是那个奇数 或者 偶数
 *
 *
 * 可以 根据 每一位 1 出现的 次数进行计算
 *
 * 1 ~ 7
 * 001 010 011 100 101 110 111
 * 0 位 1 出现 4 次
 * 1 位 1 出现 4 次
 * 2 位 1 出现 4 次
 *
 * 如果最后一位是 5 的话
 * 先判断奇偶性
 * 先测试 n - 1 次
 * 得出 1，2，3 是奇数
 * 001 111 011
 * 搜索第二位 上是否是1，如果不是，
 *
 * 先算出 每一位 应该有多少个1 ，然后看 哪一个位置少1
 * 如果最后一位 少1  ，则之后只需要检查一半 （最后一位是 1 的了）
 * 把其他的 最后一位不是1  的数字 ，其他位置上的数字 减去
 *
*/
void ask(i64 i, i64 x) {
    cout << "? " << i << " " << x << endl;
    cout.flush();
    return;
}

void answer(i64 x) {
    cout << "! " << x << endl;
    cout.flush();

    return;
}

void solve() {
    int n;
    cin >> n;
    vector<i64>a(n);
    iota(all(a), 1);
    i64 sz = 32 - __builtin_clz(n);
    vector<i64>num1(sz, 0);
    vector<vector<i64> >num(n + 1, vector<i64>(sz, 0));
    set<i64>s;

    for (int j = 1;j <= n;j++) {
        if (j != n)s.insert(j);
        for (int i = 0;i < sz;i++) {
            i64 v = (j >> i) & 1;
            num1[i] += v;
            num[j][i] += v;
        }
    }
    set<i64>resv = s;
    resv.insert(n);
    for (int i = 0;i < sz;i++) {
        i64 need1 = num1[i];
        i64 v = 1 << i;
        i64 cnt1 = 0, cnt0 = 0;
        vector<i64>nex1, nex0;
        for (auto idx : s) {
            ask(idx, v);
            i64 cv;
            cin >> cv;
            if (cv == 1) {
                cnt1++;
                nex1.push_back(idx);
            } else {
                cnt0++;
                nex0.push_back(idx);
            }
        }

        s.clear();
        vector<i64>ecc;
        if (cnt1 == need1) {
            for (auto idx : nex0) {
                s.insert(idx);
            }
            for (auto vv : resv) {
                if (((vv >> i) & 1)) {
                    for (int i = 0;i < sz;i++) {
                        num1[i] -= num[vv][i];
                    }
                    ecc.push_back(vv);
                }
            }

        } else {

            for (auto idx : nex1) {
                s.insert(idx);
            }

            for (auto vv : resv) {
                if (!((vv >> i) & 1)) {
                    for (int i = 0;i < sz;i++) {
                        num1[i] -= num[vv][i];
                    }
                    ecc.push_back(vv);

                }
            }
        }
        for (auto vv : ecc) {
            resv.erase(vv);
        }
    }

    i64 ans = *resv.begin();
    // for (int i = 0;i < sz;i++) {
    //     if (num1[i])ans |= (1LL << i);
    // }
    answer(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}