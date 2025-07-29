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

// 2025.07.29——15:20:22
/*
 * 可以在脑子中构想一个 二维正方形 但是长度为31的长方体
 * 在y 坐标设置为 bitv 也就是 比特值 0 或者 1
 * 在 x轴坐标设置 其为 奇偶性，以奇偶性来判断此 如果无法给贡献的状态
 * z 轴则是 数位的状态
 * 以下的代码中，很巧妙的设置了一个异或的条件，使得再加入的时候进行与1异或
 * 这样可以得到 当其为不可的贡献时，如果 是从1获取的贡献
 *
 * 其次再在则 其将奇偶性变位
 * 但是如果在 0 位置获取的贡献的话，其在加入的时候，是根据1的值来进行交换奇偶性的
 * 所以其最终就会 使得两边如果 有贡献第二次就会交换奇偶性的位置，
 * 1 0
 * 0 1 都是1个交换 而另外一个的位置不交换，这样就可以区分开求贡献了
*/
void solve() {
    int n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }

    i64 cnt[31][2][2] = {};
    // 位数 ， 奇偶性，以及当前位置的bit值
    i64 res = 0LL;
    for (int i = 0;i < n;i++) {
        i64 v = a[i];
        i64 parity = 0;
        for (i64 j = 0;j < 31;j++) {
            i64 bitv = (v >> j) & 1;
            res += (1LL << j) * cnt[j][parity][1 ^ bitv];
            cnt[j][parity][bitv]++;
            parity ^= bitv;
        }
        // deb(v);
        // for (int parity = 0;parity < 2;parity++) {
        //     deb(parity);
        //     for (int bitv = 0;bitv < 2;bitv++) {
        //         deb(bitv);
        //         for (int j = 0;j < 31;j++) {
        //             de(j);cout << " " << cnt[j][parity][bitv] << " ";
        //         }cout << endl;
        //     }cout << endl;
        // }
    }
    cout << res << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}