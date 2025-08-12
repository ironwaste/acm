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

// 2025.08.12——15:16:08
/*
 *
 *
 *
*/

void solve(){
    i64 x, y, z;
    cin >> x >> y >> z;
    vector<i64>insect(110, 0);

    for (int i = 1;i < x + 2;i++)
        insect[i] = 1;
    for (int i = x + 2;i <= z+1;i ++) {
        insect[i] = insect[i - 1] + insect[i - x - 2] * y;
    }

    cout << insect[z + 1] << endl;

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