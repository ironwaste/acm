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
const int N = 5e5 + 10;
i64 fri[N];

void init() {
    fri[0] = 1LL;
    for (i64 i = 1;i < N;i++) {
        fri[i] = fri[i - 1] * i % mod3;
    }
}

i64 pw(i64 a, i64 b) {

    i64 res = 1LL;
    while (b) {
        if (b & 1LL) res = res * a % mod3;
        a = a * a % mod3;
        b >>= 1;
    }
    return res % mod3;
}

i64 inv(i64 a) {
    return pw(a, mod3 - 2LL) % mod3;
}


void solve() {

    i64 n = 26, sum = 0;
    vector<i64>a(26,0);
    for (auto& x : a) {
        cin >> x;
        sum += x;
    }
    // deb(sum)
    i64 odd = sum / 2;
    i64 even = sum - odd;
    i64 ones = (fri[odd] * fri[even])% mod3;;
    map<i64, i64>mp, nmp;
    mp[0] = 1;
    for (int i = 0;i < n;i++) {
        nmp = mp;
        for (auto [x, y] : mp) {
            if(a[i])nmp[x + a[i]] += y;
        }
        mp = nmp;
        nmp.clear();
    }
    i64 ans = 1LL;
    for (int i = 0;i < n;i ++) {
        ans = ans * fri[a[i]] % mod3;
    }
    // for (auto [x, y] : mp) {
    //     de(x) deb(y)
    // }
    // deb(even)
    if (sum == 0LL || mp[even] == 0) { cout <<"0" << endl;return; }

    i64 ansans = (ones * inv(ans) % mod3 * mp[even]) % mod3;
    cout << ansans<< endl;
    // deb(ansans)


    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}