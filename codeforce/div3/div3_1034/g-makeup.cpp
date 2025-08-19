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


// 补题——题目链接:
// 网址：https://codeforces.com/contest/2123/problem/G
// 2025.08.19——23:20:27
/*
 * 题目意思：
 * 操作1 可以改变 第i个位置的值为 x
 * 操作2 可以选择任意次数操作 判断是否最后的解 可以将数组变为不递减数组
 * 也就是非递减数组 ，可以等于或者 大于前一个位置上的数
 * 操作二 会输入一个 k 值 并且 可以把任意位置上的数子 换成 当前数字 + k 模除 m
 *
 * 其可改变为的数字 为 gcd(m,k) ? 为什么呢 ？？？？
 *
 * 维护差分数组 ，判断是否能将差分数组 所有数值变为 非负数
 *
 *
 * 这道题目 最关键的是 ，将 所有的值都改变成 统一同余类，这时候所有的值
 * 不是相等就是 同余类的下一个， 而后根据同余类的性质， 贪心使用每个位置上的最小值
 * 这样  差分数组 最后 的和的值 只要小于 m /  同余类 就是不同的种类的值，
 * 这样就可以化简问题了。
 *
 */

const int N = 5e5 + 10;
vector<i64>factor[N];
void init() {
    for (int i = 1;i < N;i ++) {
        for (int j = i;j < N;j += i) {
            factor[j].push_back(i);
        }
    }
}

void solve() {
    i64 n, m, q;
    cin >> n >> m >> q;
    map<i64, i64 >gcdm;
    vector<i64>a( 1 + n ,0);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    for (auto p : factor[m]) {
        gcdm[p] = 0;
        for (int i = 1;i <= n;i++) {
            gcdm[p] += (a[i] % p < a[i - 1] % p);
        }
    }

    while (q --) {
        i64 op,i,x,k;
        cin >> op;
        if (op == 1) {
            cin >> i >> x;
            for (auto p : factor[m]) {
                gcdm[p] += (x % p < a[i - 1] % p) - (a[i] % p < a[i - 1] % p);
                if (i != n) {
                    gcdm[p] += (a[i + 1] % p < x % p) - (a[i + 1] % p < a[i] % p);
                }
            }
            a[i] = x;
        } else if (op == 2) {
            cin >> k;
            i64 p = __gcd(k, m);
            cout << ((gcdm[p] < (m/p)) ? "YES" : "NO") << endl;
            
        }


        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}