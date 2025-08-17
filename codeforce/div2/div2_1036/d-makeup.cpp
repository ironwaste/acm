#include<bits/stdc++.h>
// #include<climit>

#define endl '\n'
#define i64 long long
#define fi first
#define se second
#define Endl endl
#define END endl
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;


// 补题——题目链接:https://codeforces.com/contest/2124/problem/D
// 网址：https://codeforces.com/blog/entry/144382
// 2025.07.07——02:20:26
void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    auto b = a;
    sort(all(b));
    k--;
    vector<i64>c;
    for (auto x : a) {if (x <= b[k]) { c.pb(x); }}

    i64 l = 0, r = c.size() - 1;
    i64 rm = 0;
    // 就是这个循环内部的逻辑没有搞懂
    // 也就是什么时候，这个双指针进行移动没搞清楚
    // 当两者不同的时候
    while (l < r) {
        if (c[l] == c[r]) {
            l++, r--;
            continue;
        } else if (c[l] == b[k]) {
            l++;rm++;
        } else if (c[r] == b[k]) { // 还是这里有点问题
            // 但是不知道思路上的问题出在哪里，但是就是有点奇怪
            r--, rm++;
        } else {
            cout << "NO\n";
            return;
        }
    }
    if ((i64)(c.size() - rm) >= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

//声称：只要 k−1 最小的元素还留在数组中，我们就能以任何方式擦除其他元素。 就是我所想错了的条件
// 我想的就是，只要排位于k-1 位的元素的上一个不同素，留在数组中，其他元素都可以被擦除

// 之前的思路误区在于：
// 我所认为的是，当我选中了必须选择的数字后，其中还有一个数字是部分选择的
// 我认为可以通过一些方式将我想要的数字进行删除，但是我没有意识到
// 最后所剩余的部分还是存在这个数字的，并非全部删除，
// 所以无论如何一定会存在前k-1个数字，而后这k-1个数字存在则
// 其一定要能够生成回文串，否则加再多也没有用
// 2025.07.07——02:44:20

// 可以提交了 所以3个小时的cf 大概在赛后1个半小时出排名并且可以提交
// 2025.07.07——03:00:29
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