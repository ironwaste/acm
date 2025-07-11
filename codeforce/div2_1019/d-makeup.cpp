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
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
using namespace std;

using pii = pair<int, int>;
using pll = pair<i64, i64>;


// 补题——题目链接:https://codeforces.com/contest/2103/problem/D
// 题解网址：https://codeforces.com/blog/entry/142149
// 2025.07.09——21:04:19
/*
 * 先删除 不是局部最小值的元素
 * 再删除 不是局部最大值的元素，
 * 所以留下的一定不是局部最小 、 也不是第二次的局部最大值元素
 * 最后只剩一个元素在序列p中，那么这个元素应该是什么呢
 * 举例 n=3 ：
 * [1 2 3] => [1]
 * [1 3 2] => [1 2] => [2]
 * [2 1 3] => [1]
 * [2 3 1] => [2 1] => [2]
 * [3 1 2] => [1]
 * [3 2 1] => [1]
 *
 * 一次都消除会留下 local minima 局部最小值
 * 两次消除，会留下除了第一次剩下的数组中的局部最大值
 * 猜想一： 是否总共最多只会产生两次被删除的上限
 *
 * [1 3 2 5 4] => [1 2 4] => [4]
 * [2 3 1 5 4] => [2 1 4] => [2 4] => [2]
 * [-1 1 2 1 2]
 *
 * array : 4 5 1 3 2
 * ans   : 3 1 2 1 -1
 * [4 5 1 3 2] => [4 1 2] => [4 2] => [4]
 * 第一次构造算法产生 -> [3 5 1 4 2] => [3 1 2] => [3 2] => [2]
 * 对的
 * 猜想二：
 * 1、如果一段区域内的被削去的次数是相同的那么说明其是递增递减的
 * 2、如果不是增加就会有两种可能
 *      i.如果是偶数的话那么说明就是局部最小值
 *      ii. 如果是奇数那么就是前一个
 */

/*
    构造方式一： 根据给出的数组中的数值进行判断，
    其一将从1开始派数字，因为当轮次为奇数的时候，保留局部最小值
    当轮次为偶数的时候，保留局部最大值
    所以在轮次为奇数的时候，我们先从最大值进行构造
    当轮次为偶数的时候，我们应该从所剩下的数字中选择最小值来构造

*特殊情况当[1 2 3] 和 [1 3 2] 最后产生的结果不同
*respectively ，[-1 1 1] and [2 1 -1]
* 当给出的数组为 2 1 -1 时我们的算法是没有问题的
* 但是当给出的数组为 -1 1 1 的时候如果我们是从左向右给出当前最大的数值
* 最后会导致给出的是[1 3 2]的数值而非[1 2 3]
* 所以我们需要判断一个被填充的区间是否是左右两端都存在更高轮次或者-1存在
*  i. 如果存在：那么我们只需要按顺序排序就好
*  ii. 如果不存在的情况下,那么我们需要将填充的数值顺序进行逆反一下
* 暂时未发现反例,先试一把
* 反例: 
* 5
* -1 1 2 1 2
* 需要对最后一轮进行特判根据-1所在的位置进行寻找，
* i.如果为奇数轮次 保留局部最小值 则将所有数值从大向小排序号
* ii.如果为 偶数轮次 则相反
    比如
    [1 , -1 , 1 , 2 , 1] =>

* 不对应该是通过 -1 的位置来判断是否反转，而非是否是边界位置
*

三个东西进行相关
1、 -1 所在位置
2、 奇偶轮次 也就是 所需要保留的是 局部最大值和局部最小值 哪一个？

i.  奇数轮次 -1 在其右侧 不变
ii. 偶数轮次 -1 在其右侧 不变



*/


void test() {
    // 用于测试 是否存在超过三的数字
    i64 n = 0;
    cin >> n;
    vector<i64>a(n);
    iota(all(a), 1); 
    i64 mx = 0;
    do {
        i64 round = 1,cnt = 0;
        vector<i64>ans = a;
        for (auto &x : ans) {x = 0;}
        // auto tmpa = a;
        vector<pll>tmp;
        // tmp = a;
        for (int i = 0;i < a.size();i ++) {
            tmp.push_back({a[i],i});
        }

        while (cnt < n - 1) {
            // de(round)deb(cnt)
            mx = max(round,mx);
            vector<pll>next_tmp;
            i64 sz = tmp.size();
            if (round % 2 == 1) { // 删除非 局部最小值
                for (i64 i = 0;i < sz;i++) {
                    i64 pos = tmp[i].se, v = tmp[i].fi;
                    if (i == 0) {
                        if (v > tmp[i+1].fi) {
                            ans[pos] = round;
                            cnt++;
                        } else {
                            next_tmp.push_back(make_pair(v,pos) );
                        }
                    } else if (i == sz - 1) {
                        if (v > tmp[i-1].fi) {
                            ans[pos] = round;
                            cnt++;
                        } else {
                            next_tmp.push_back(make_pair(v, pos));
                        }
                    } else {
                        if (v > tmp[i+1].fi || v > tmp[i-1].fi) {
                            ans[pos] = round;
                            cnt++;
                        } else {
                            next_tmp.push_back(make_pair(v,pos));
                        }
                    }
                }
            } else {
                for (i64 i = 0;i < sz;i++) {
                    i64 pos = tmp[i].se, v = tmp[i].fi;
                    if (i == 0) {
                        if (v < tmp[i+1].fi) {
                            ans[pos] = round;
                            cnt++;
                        } else {
                            next_tmp.push_back(make_pair(v,pos));
                        }
                    } else if (i == sz - 1) {
                        if (v < tmp[i-1].fi) {
                            ans[pos] = round;
                            cnt++;
                        } else {
                            next_tmp.push_back(make_pair(v,pos));
                        }
                    } else {
                        if (v < tmp[i+1].fi || v < tmp[i-1].fi) {
                            ans[pos] = round;
                            cnt++;
                        } else {
                            next_tmp.push_back(make_pair(v,pos));
                        }
                    }
                }
            }
            round++;
            tmp.clear();
            if (next_tmp.size() == 1)break;
            tmp = next_tmp;
        }
        cout << "array : ";
        for (auto x : a) {
            cout << x << " ";
        }cout << endl;
        cout << "ans   : ";
        for (auto x : ans) {
            cout << x << " ";
        }cout << endl <<"----------------------------\n";
    } while (next_permutation(all(a)));
    deb(mx)
}


void solve() {
    i64 mx=0, n;
    cin >> n;
    vector<i64>a(n), ans(n, 0);
    i64 id = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        mx = max(a[i], mx);
        if (a[i] == -1)id = i;
    }
    i64 ki = 1, kj = n,cnt = 1;
    while (mx >= cnt) {
        i64 i = 0;
        while (i < n) {
            while (i < n && a[i] != cnt) {
                i++;
            }
            // de(i);
            i64 j = i;
            do {
                j++;
            } while (j < n && (a[j] <= cnt && a[j] != -1));
            // deb(j);
            if (j - 1 >= n)continue;
            if (i > id) {
                if (cnt % 2) {
                    for (i64 tmp = j - 1;tmp >= i;tmp--) {
                        if(a[tmp] == cnt)ans[tmp] = kj--;
                    }
                } else {
                    for (i64 tmp = j - 1;tmp >= i;tmp--) {
                        if(a[tmp] == cnt)ans[tmp] = ki++;
                    }
                }
            } else {
                if (cnt % 2) {
                    for (i64 tmp = i;tmp < j;tmp++) {
                        if(a[tmp] == cnt)ans[tmp] = kj--;
                    }
                } else {
                    for (i64 tmp = i;tmp < j;tmp++) {
                        if(a[tmp] == cnt)ans[tmp] = ki++;
                    }
                }
            }
            i = j;
            // for (auto x : ans) {
            //     de(x)
            // }deb(' ');
        }
        cnt++;
    }

    for (int i = 0;i < n;i++) {
        if (a[i] == -1) {
            ans[i] = ki ++;
        }
    }
    
    for (auto x : ans) {
        cout << x << " ";
    }cout << endl;


    
}
// 2025.07.11——16:47:49 死循环 
/*
数据
1
5
1 -1 1 2 1
*/
// 2025.07.11——17:11:43 wa 2
/* 错误样例  想法错误
5
2 1 -1 1 1
*/
// 2025.07.11——17:43:03 accepted
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}








/*
2 1
1 2
1 2 3
3 1 2
1 3 2
2 3 1
3 2 1
1 2 3 4
4 1 2 3
1 3 2 4
2 3 1 4
4 3 1 2
4 3 2 1
1 3 4 2
2 3 4 1
4 1 3 2
4 2 3 1
1 2 3 4 5
5 1 2 3 4
1 3 2 4 5
2 3 1 4 5
5 4 1 2 3
5 4 3 1 2
1 3 4 2 5
2 3 4 1 5
5 1 3 2 4
5 2 3 1 4
5 4 3 2 1
1 3 4 5 2
2 3 4 5 1
5 1 3 4 2
5 2 3 4 1
3 4 2 5 1
1 4 3 5 2
3 4 1 5 2
2 4 1 5 3
1 4 2 5 3
5 4 1 3 2
// 5 4 2 3 1 [1 1 -1 1 2]
// 2 5 1 4 3 
1 2 3 4 5 6
6 1 2 3 4 5
1 3 2 4 5 6
2 3 1 4 5 6
6 5 1 2 3 4
6 5 4 1 2 3
1 3 4 2 5 6
2 3 4 1 5 6
6 1 3 2 4 5
6 2 3 1 4 5
*/