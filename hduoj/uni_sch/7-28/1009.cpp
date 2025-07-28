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

// 2025.07.28——12:11:33
// 2025.07.28——12:26:49 accpted
/*
 * 题目含义 ： 给定一个数组，代表其中相连的两个下标点之间
 * 可以经过的最大的 路径长度
 *
 * 1、 不可能产生 0 的存在
 * 2、 回路总长度至少为 2 * (n - 1)
 * 3、 可以 通过将一条全直链的状态下 再去调配的方式
 * 将其他所有状态产生
 *
*/
const int N = 1e5 + 10;


void solve(){
    i64 n,sum = 0;
    cin >> n;
    vector<i64>p(n);
    int ok = 1;
    for (auto& x : p) {
        cin >> x;sum += x;
        if (!x)ok = 0;
    }
    if (sum < 2 *(n-1)) {
        ok = 0;
    }
    
    cout << ((ok) ? "YES" : "NO") << endl;
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