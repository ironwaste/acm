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
using i128 = __int128;

// 2025.08.21——23:40:34
/*
 *  1 2 3 4 5 6 7 8 9 // 9 位
 *  10 11 12 13 14 15 16 17 18 19 // 20位
 *
 *  1 0 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9
 *
 * // 20 20 20 20 20 
 * 100 101 102 103 104 105 106 107 108 109  30位
*/
/*
 * 1       (0 -- 0)
 * 19      (0 -- 9) 2 * 9 = 18 + 1
 * 280     (0 -- 180)       3 * 9 = 27 + 1 = 28
 * 3700    (0 -- 3700)      4 * 9 = 36 + 1 = 37
 * 46000   (0 -- 46000)
 * 550000  (0 -- 450000)
 * 6400000 (0 -- 5400000)
 * 73000000(0 -- 63000000)
*/
const i128 cnt[] = {1,19,280,3700,4600,55000,640000,7300000,82000000,910000000,}
vector<i128>v, dig;
void init() {
    v.push_back(0);
    dig.push_back(0);
    i128 bv = 45, cnt = 1,dv = 9;
    for (i128 i = 1;i <= 15;i++) {
        v.push_back(bv * cnt);
        dig.push_back(dv*i);
        dv = dv * 10;
        cnt = 
    }
}



void solve() {


    

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