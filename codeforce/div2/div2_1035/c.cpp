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


/*

此一个条件：
所有的数字大小要在于给定区间l 到 r之间

第二个条件：
按位置
1、 如果最后结果为0 ，则其中1的个数为偶数个0，2，4
2、 如果最后结果为1，则全部为1 且1的个数为奇数个

按照个数：
如果总数为奇数个 ，则全部为同一个数字且最小即可
因为最后异或出来的值为原本的值

偶数个
倒数第二个值，从最小值的最高位1前一位开始
取反
最后两个值相同即可，（其中一种解）
是否有其他解？
根据选择的最小值来判断


错误的：
倒数第二个值 变为最小值+1，
然后再看倒数第一个值
将其 变为倒数第二个值最后改变位数全部取反
也就是 倒数第二个值的 最低位1 后的零全部改为1
且最低位1改为0，前缀不变，
或者 其范围为 从最低位1开始往后


第三个条件
字典序最小

*/
/*问题：求最高位1 的位置*/

i64 lowbit(i64 x) {
    return x - (x & (-x));
}

i64 value(i64 x) {
    i64 res = x,tmp;
    while (res) {
        tmp = res;
        res = lowbit(res);
        // deb(res)
    }
    return tmp << 1;
}


void solve() {

    // cout << hight_bit(test) << endl;
    i64 n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n % 2 == 1) {
        cout << l << endl;
        return;
    }
    i64 a, b,ok = 0;
    // for (i64 i = l;i <= r;i++) {
    a = l;
    b = value(a);
    if (b >= l && b <= r) { ok = 1; }
    
    if (ok && n>=4) {
        if (k <= n - 2)cout << a << endl;
        else { cout << b<<endl; }
    } else {
        cout << -1 << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}