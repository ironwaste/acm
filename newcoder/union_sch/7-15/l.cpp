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

// 2025.07.15——13:21:45
/* 牛客L题：https://ac.nowcoder.com/acm/contest/108298/L
 * 其实就是找一个 数据结构，使得每改变一个数字
 * 需要的是，保持原数组，然后可以删除元素，再重新插入
 * 或者说是修改元素的时间复杂度在O(nlogn)
 * 其次需要能够查找 第 [(n-1)/2]上取整的数字是多少
 * 并且找出第一个小于该数字的值，以及其排序
 * 
 * 使用map来模拟的话
 * sort 有一个 nlog得出最初的三堆
 * 其次使用map进行查找和删除，n(log(n)查找+log(n)删除) 修改(2*log(n))
 * 性质所有的值只会增加，且每次查询只能够增加一个点
 * 可以用队列模拟，因为只会增加，所以只需要向队列中增加大于等于[(n-1)/2]上取整数值
 * 最顶上使用最小值，然后判断现在是否有小于当前最小值的数字，变得大于该最小值，
 * ，如果有则插入，当小根堆增加一个值，则将小根堆中的值删去
 * 保持原来的数组，进行修改，可是如果是大于小根堆的最小值，的话则需要将
 * 小根堆中的值提取出来，
 *
 *
 * 3,需要输 1把 
 * 4,5 都需要输两把
 * 所以奇数情况下,中间值算是输掉,而偶数情况需要算到中间值之上一位
 */

void solve() {
    i64 n, qq;
    map<i64, i64>cnt;
    cin >> n >> qq;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x;cnt[x]++; } // n
    auto b = a;
    sort(all(b)); // nlogn
    priority_queue<i64>q;
    map<i64, i64>bgbg;// 从比中间值大的值，在更改的比中间值大
    // mp 用于存储每个值有多少个
    i64 mid = b[(n + 1)/ 2];// (n - 1 + 除数 -1 )/除数就是上取整
    i64 mi_id = lower_bound(all(b), mid) - b.begin();
    i64 mx_id = upper_bound(all(b), mid) - b.begin() + 1LL;
    // de(mi_id)de(mx_id)deb(mid);
    i64 mi_num = mi_id, mid_num = cnt[mid];//小于中间值的个数(也就是答案)， 中间值的个数 中间值代表的是 ,第一个不心里崩溃的数值

    for (int i = mx_id;i < n;i++) { q.push(b[i]); }

    auto erase_mp = [&](i64 v)->void {
        if (cnt.count(v)) {
            if (cnt[v] > 0) { cnt[v]--; }
            if (cnt[v] == 0) { cnt.erase(v); }
        }
        };
    auto erase_bg = [&](i64 v)->void {
        if (bgbg.count(v)) {
            if (bgbg[v] > 0) { bgbg[v]--; }
            if (bgbg[v] == 0) { bgbg.erase(v); }
        }
        };
    // de(mi_num)deb(mid_num);
    while (qq--) {
        i64 p, v;
        cin >> p >> v;
        p--;
        i64 pv = a[p];
        // 删除
        if (pv < mid) {
            mi_num--;
            erase_mp(pv);
        } else if (pv == mid) {
            erase_mp(pv);
            mid_num--;
        } else {
            erase_mp(pv);
        }

        // 增加 两个何在一起就是更改
        if (pv + v < mid) {
            mi_num++;
            cnt[pv + v]++;
            a[p] = pv + v;
        } else if ((pv + v) == mid) {
            mid_num++;
            cnt[pv + v]++;
            a[p] = pv + v;
        } else {
            // mid_num++;
            cnt[pv + v]++;
            q.push(pv + v);
            a[p] = pv + v;
            if (pv > mid) {
                bgbg[pv]++;
            }
        }
        // de(mi_num)deb(mid_num);
        // 判断中间值是多少,并且维护mid_num,mid,mi_num
        // 并更新优先队列q和bgbg
        while (mi_num + mid_num - 1LL < (n + 1LL) / 2) {
            mi_num = mi_num + mid_num;
            mid = q.top();
            mid_num = cnt[mid];
            q.pop();
            while (!q.empty() && (bgbg.count(q.top()) || mid >= q.top())) {
                erase_bg(q.top());
                q.pop();
            }
        }
        i64 ans = mi_num;
        cout << ans << endl;
        // deb(ans);
    }
}
// 2025.07.15——15:19:20 wa
// 2025.07.15——15:26:07 wa
/* 错误样例
10 6
927 554 516 488 88 187 986 792 252 484
10 942
9 284
4 495
2 95
3 603
4 443



*/

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