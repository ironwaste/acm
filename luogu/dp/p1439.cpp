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
    cin >> n;
    vector<int>a(n), b(n);
    map<int, int>mp;
    for (auto& x : a) { cin >> x; }
    for (int i = 0;i < n;i ++) {
        cin >> b[i];
        mp[b[i]] = i;
    }

    // int ;
    vector<int>id;
    for (int i = 0;i < n;i++) {
        int k = mp[a[i]];
        if (id.size() == 0) {
            id.pb(k);
        } else if (id.back() < k) {
            id.pb(k);
        } else {
            // log n find
            int l = 0, r = id.size() - 1;
            while (l < r) {
                int mid = l + (r - l >> 1);
                if (id[mid] < k) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            id[l] = min(id[l],k);
        }
    }

    cout << id.size() << endl;
}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}