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

// 2025.08.09——20:08:01
// 2025.08.09——20:14:09 accpted
/*
 *
 *
 *
*/

void solve() {
    string s;
    cin >> s;
    int sz = s.size();
    i64 a = 0, b = 1;
    for (int i = 0;i < sz;i++) {
        int cnt = (s[i] == 't');
        for (int j = i + 1;j < sz;j++) {
            if (s[j] == 't') {
                cnt++;
                i64 t = j - i + 1;
                if (t >= 3) {
                    if (a * (t - 2) < (cnt - 2) * b) {
                        a = cnt - 2;
                        b = t - 2;
                    }
                }
            }
        }
    }
    double ans = 1.0 * a / b;
    printf("%.09lf",ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}