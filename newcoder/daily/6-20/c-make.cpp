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

i64 ston(char c) {
    return (i64) (c - 'a');
}

void solve(){
    string s;
    i64 x,n;
    cin >> s >> x;
    n = s.size();
    i64 cntx = 0,res = x;
    vector<i64>cnt(26, 0);
    for (int i = 0,j = 0;i < n;i++) {
        while (j < i && cntx >= x) {
            
            int v = ston(s[j]);
            cnt[v] --;
            for (int k = 0;k < v;k++) {
                cntx -= cnt[k];
            }
            res = min(res, abs(x-cntx) );
            j++;
        }
        
        int v = ston(s[i]);
        cnt[v]++;
        for (int k = v + 1;k < 26;k++) {
            cntx += cnt[k];
        }
        res = min(res, abs(x-cntx));
        
    }

    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}