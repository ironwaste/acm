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
    int n, q;
    cin >> n >> q;
    int id = 1,server = 0;
    vector<string>s(1,"");
    vector<int>pc(n + 2, 0);
    while (q--) {
        int op,p;
        cin >> op >> p;
        if (op == 1) {
            pc[p] = server;
        } else if (op == 2) {
            string tmp;
            cin >> tmp;
            if (pc[p] == 0) {
                pc[p] = id++;
                s.push_back(tmp);
            } else {
                s.push_back(s[pc[p]] + tmp);
                pc[p] = id++;
            }
        } else if (op == 3) {
            server = pc[p];
        }
    }
    
    de(server)deb(pc[server]);
    cout << s[server] << endl;
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