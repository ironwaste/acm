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


void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0;i < n/2 ;i++) {
        if (s[i] == s[n - i - 1]) {cnt = i;}
        if(s[i] != s[n - i - 1]){ break; }
    }
    n -= 2 * cnt;
    s = s.substr(cnt, n);

    int ans = n;

    for (int pos = 0;pos < 2;++pos) {
        int l = 0, r = n;
        while (l <= r) {
            vector<int>cnttub(30, 0);

            int m = l + (r - l >> 1);
            bool cntok = true;

            for (int i = 0;i < m;i++) {
                cnttub[s[i] - 'a']++;
            }
            for (int i = 0;i < min(n / 2, n - m);i ++) {
                char c = s[n - i - 1];
                if (i < m) {
                    cntok &= cnttub[c - 'a'] > 0;
                    cnttub[c - 'a']--;
                } else {
                    cntok &= (c == s[i]);
                }
            }

            if (cntok) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        ans = min(ans, r + 1);
        reverse(all(s));
    }
    cout << ans << endl;
    
}

int main(){
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}