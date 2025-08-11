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

// 2025.08.11——12:19:53
// 2025.08.11——12:29:16 accpted
// 没有完全证明 还需要证明一下
/*
 *
 *
 *
*/

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    i64 fi_1 = -1;
    for (int i = 0;i < m;i++) {
        if (t[i] == '1') {
            fi_1 = i;
            break;
        }
    }

    
    int i = -1, cnt = 0;;
    for (int i = fi_1;i < n - (m - fi_1) + 1;i ++) {
        if (s[i] == '1') {
            cnt++;
            for (int j = fi_1;j < m;j++) {
                if (t[j] == '1') {
                    if (s[i + j] == '1') {
                        s[i + j] = '0';
                    } else {
                        s[i + j] = '1';
                    }
                }
            }
        }
    }
    for (auto x : s) {
        if (x == '1') {
            cout << "-1" << endl;
            return;
        }

    }
    cout << cnt << endl;

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