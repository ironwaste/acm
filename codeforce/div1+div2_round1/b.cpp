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

// 2025.07.19——22:41:38
/*
 * 如果只有0的情况下，那么改变值，只需要将每个位置上0的差值的绝对值进行相加，然后除以2即可
 * 即得到答案
 * 当时当1在下方，那么就说明，该堆上面的所有的0 都将被移走之后，在移动回来
 * 所以答案就是将，1的值改变的堆的 原本0的值加起来，然后在加上1的值  这是移走的值
 *
 * 0可以移到下面
 * 所以结果是，当 一个数字1的个数没有改变 b==d 的情况下，只计算0即可
 * 当1的个数改变 b < d 的情况，那么改变值为abs(a - c) + abs(b - d);
 * b > d
 *
 * a > c :
 * 1、 b == d : a - c;
 * 2、 b > d : a + b - d;
 * 3、 b < d : a - c
 *
 * a == c :
 * 1. b == d : 0
 * 2. b > d : a + b - d
 * 3. b < d : 不变等着送过来
 *
 * a < c :
 * 1. b == d: 等着送过来
 * 2. b > d : a + (b - d)
 * 3. b < d : 等着送
 */
// 

void solve() {
    i64 n,a,b,c,d;
    cin >> n;
    // vector<EE>t(n);
    i64 ans = 0;
    for (int i = 0;i < n;i++) {
        cin >> a >> b >> c >> d;
        if (b > d) {
            ans += a + b - d;
        } else if (a > c) {
            ans += a - c;
        }
    }
    cout << ans << endl;
}
// 2025.07.19——23:09:44 wa 2
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