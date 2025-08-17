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


i64 dis(i64 x1, i64 y1, i64 x2, i64 y2) {
    return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}
i64 disx(i64 d) {
    return sqrt(d - 1);
}

void solve() {
    i64 n, m, d;
    cin >> n >> m >> d;
    // d = d * d;
    vector<vector<i64> >mp(n,vector<i64>(m,0LL));
    vector< vector< i64 > >num(n + 2LL, vector< i64 >(m,0LL) );
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            char c;
            cin >> c;
            mp[i][j] = (c == 'X');
            if (i == n - 1) {
                num[i][j] = mp[i][j];
            }
        }
    }
    // auto num = mp;
    for (i64 i = n - 1;~i;i--) {
        vector<i64>pre(m + 1, 0);
        for (int j = 0;j < m;j ++) {
            (pre[j + 1] += num[i + 1][j] %mod3)%=mod3;
        }
        
        for (int j = 0;j < m;j++) {
            (pre[j + 1] += pre[j] % mod3) %= mod3;
        }
        // 下层传递
        for (i64 j = 0;j < m;j++) {
            if (mp[i][j]) {

                // 下标判断很有东西
                // 因为 sqrt( d ** 2 - 1 ** 2) = sqrt((d + 1) * (d - 1)) 下取整所以就是 d - 1
                // 5 * 5 = 25 but 4 * 6 = 24 当两数和等于 2d 的时候 其两者相等则是最大的时候
                // 但是当 所以当d+1 d-1 放在一起的时候 则就会
                // 横边长度为 d - 1
                // 
                // cnt =  j + 1LL  、  
                // left = cnt - d + 1LL;
                // right = cnt + d - 1 
                (num[i][j] += (pre[min(j + d, m)] + mod3 - pre[max(j - d + 1LL, 0LL) ]% mod3)) %= mod3;
            }
        }

        pre[0] = 0;
        for (i64 j = 0;j < m;j++) { pre[j + 1] = (pre[j] + num[i][j]) % mod3; }
        // 同层传递 
        for (i64 j = 0;j < m;j ++) {
            if(mp[i][j]) num[i][j] = (pre[min(j + 1LL + d,m)]%mod3 + mod3 - pre[max(j - d,0LL)]) % mod3;
        }
    }

    i64 asn = 0;
    for (int i = 0;i < m;i ++) {
        (asn += num[0][i]) %= mod3;
    }
    cout << asn << endl;

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

/*
3
3 4 1
XX#X
#XX#
#X#X
3 4 2
XX#X
#XX#
#X#X
3 1 3
X
X
#


output : 
2
60
0
*/