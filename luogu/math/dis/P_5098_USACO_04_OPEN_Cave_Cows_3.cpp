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


// 补题——题目链接: https://www.luogu.com.cn/problem/P5098
// 网址：
// 2025.09.01——00:33:38
/*
 *
 *
 * 主要是利用了 切比雪夫距离  其 任意两点之间的最大值
 * 是根据 x 和 y 分别进行计算的，然后再判断两个中最大的距离
 * 即为存在的距离  虽然两点的切比雪夫距离
 * 可能 只存在一个x轴上的 或者 一个y轴上的
 * 但是由于该题 所求解的 是 任意两点之间最大的距离
 * 所以没有影响
*/

void solve(){
    i64 n;
    cin >> n;
    vector<i64>x(n), y(n);
    for (int i = 0;i < n;i ++) {
        i64 a, b;
        cin >> a >> b;
        x[i] = a + b;
        y[i] = a - b;
    }
    sort(all(x));
    sort(all(y));
    i64 ans = x[n - 1] - x[0];
    ans = max(ans, y[n - 1] - y[0]);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}