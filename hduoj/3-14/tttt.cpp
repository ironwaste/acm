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
    int n;
    string s;
    cin >> s >> n;
    int sz = s.size();
    vector<int>num;
    map<char, int>mp;
    for (int i = 0;i < sz;i++) {
        if (mp.count(s[i])) {continue;}
        mp[s[i]]++;
        num.push_back((int) (s[i] - 'a'));
    }
    int k = mp.size(),kk = num.size();
    vector<int>ans;
    for (int i = 0;i < min(k, 27);i++) {
        for (int j = 0;j < kk;j++) {
            if (ans.size() == 0) {
                ans.pb(num[j]);
                // deb(num[j]);
            } else {
                if (num[j] > ans.back()) {
                    ans.pb(num[j]);
                    // deb(num[j]);
                }
                else {
                    int id = lower_bound(all(ans), num[j]) - ans.begin();
                    // de(id)deb(num[j])
                    ans[id] = num[j];
                }
            }
        }
    }
    cout << ans.size() << endl;
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