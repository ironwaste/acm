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

// 2025.07.25——12:02:01
/*
 * 每种牌只会产生0，1，2三种余数
 * 所以每张牌，在没有 拆牌的情况下，只能够对应两个三带一
 * 
*/

void solve() {
    i64 sum = 0;
    vector<i64>a(13, 0);
    auto s1 = a, s3 = a;
    for (auto& x : a) { cin >> x; sum += x; }

    
    cout << min(sum3, sum) << endl;

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