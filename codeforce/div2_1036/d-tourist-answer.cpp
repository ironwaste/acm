/**
 *    author:  tourist
 *    created: 06.07.2025 07:45:13
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    --k;
    auto b = a;
    sort(b.begin(), b.end());
    vector<int> c;
    for (int i = 0; i < n; i++) {
      if (a[i] <= b[k]) {
        c.push_back(a[i]);
      }
    }
    int l = 0, r = int(c.size());
    int rm = 0;
    // 核心在于 先将所有加入进来，如果其产生回文串所需要移除的字符串
    // 在移除之后 小于了我们的所需，那么就无法产生合格的所需要的字符串
    while (l < r) {
      if (c[l] != c[r - 1]) {
        if (c[l] == b[k]) {
          l += 1;
          rm += 1;
        } else {
          if (c[r - 1] == b[k]) {
            r -= 1;
            rm += 1;
          } else {
            rm = n + 1;
            break;
          }
        }
      } else {
        l += 1;
        r -= 1;
      }
    }
    if (int(c.size()) - rm >= k) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
/*
3
7 4
1 4 1 4 1 2 2
7 5
1 4 1 4 1 2 2
8 5
1 4 1 1 4 1 2 2
7 5
1 2 4 2 1 2 2
逻辑很缜密 ，但是我脑子里面的逻辑不能将这两个联立起来
当我想要消去几个数字，那么就代表 k为
我们只能够将 第k个之后的所有数值进行消去（包含k）
但是不能消除第k-1个

我搞不明白这里的思维误区

回文串大小为 k-1
*/
/*
 * 1 -> 3
 * 2 -> 4
 * 4 -> 2
*/