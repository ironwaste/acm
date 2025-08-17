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


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '0' + s;
    i64 ans = 0;
    // if (s[0] == '1') {
    //     ans += 2;
    // } else if(s[0] == '0'){
    //     ans += 1;
    // } 
    string tmp = "";
    for (int i = 1;i <= n;i++) {
        if (s[i - 1] != s[i]) {
            ans += 2;
            tmp += s[i];
        } else {
            ans++;
        }
    }
    tmp = '0' + tmp;
    // deb(tmp);
    // deb(ans);
    string s2 = "0101", s21 = "1010", s1 = "010";
    if (tmp.find(s2) != string::npos|| tmp.find(s21) != string::npos) {
        ans -= 2;
    } else if (tmp.find(s1)!= string::npos) {
        ans -= 1;
    }
    cout << ans << endl;
    // deb(ans)

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}