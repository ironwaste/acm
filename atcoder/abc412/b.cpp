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
    string s, t;
    cin >> s >> t;

    set<char>st;
    i64 szt = t.size(), szs = s.size();
    for (int i = 0;i < szt;i++) { st.insert(t[i]); }
    int ok = 1;
    for (int i = 1;i < szs;i ++) {
        char ch = s[i],c = s[i-1];
        if (ch >= 'A' && ch <= 'Z' && !st.count(c)) {
            ok = 0;
            break;
        }
    }
    cout << ((ok) ? "Yes" : "No" )<< endl;



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