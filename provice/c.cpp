// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#include<bits/stdc++.h>
#include<climits>


#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll long long
#define fi first
#define se second

#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

// using pii = pair<int,int>;
// using pll = pair<i64, i64>;


void solve(){

    ll k, n, m = 0;
    cin >> k;
    ll color_true[1050] = {0};
    ll color_greedy[1050] = {0};
    vector<ll> edge[1050];
    color_true[1] = 2; color_greedy[1] = 1;
    color_true[2] = 1; color_greedy[2] = 2;
    color_true[3] = 1; color_greedy[3] = 1;
    color_true[4] = 2; color_greedy[4] = 3;
    color_true[5] = 2; color_greedy[5] = 2;
    color_true[6] = 1; color_greedy[6] = 3;
    color_true[7] = 1; color_greedy[7] = 4;
    color_true[8] = 2; color_greedy[8] = 5;
    edge[2].push_back(1);
    edge[4].push_back(2);
    edge[4].push_back(3);
    edge[5].push_back(3);
    edge[6].push_back(1);
    edge[6].push_back(5);
    edge[7].push_back(1);
    edge[7].push_back(4);
    edge[7].push_back(5);
    edge[8].push_back(2);
    edge[8].push_back(3);
    edge[8].push_back(6);
    edge[8].push_back(7);
    m += 13;
    ll i = 0;
    while (1) {
        i++;
        ll x = (i + 1) * 4;
        if (x == 1024) break;
        ll flag = color_greedy[x];
        color_true[x + 1] = 2;  color_greedy[x + 1] = flag - 1;
        color_true[x + 2] = 1;  color_greedy[x + 2] = flag;
        color_true[x + 3] = 1;  color_greedy[x + 3] = flag + 1;
        color_true[x + 4] = 2;  color_greedy[x + 4] = flag + 2;
        for (int j = 1; j <= x - 2; j++) {
            if (color_true[j] == 1) {
                edge[x + 1].push_back(j);
                m++;
            }
        }
        for (int j = 1; j <= x - 1; j++) {
            if (color_true[j] == 2) {
                edge[x + 2].push_back(j);
                m++;
            }
        }
        edge[x + 2].push_back(x + 1);
        m++;
        for (int j = 1; j <= x + 1; j++) {
            if (color_true[j] == 2) {
                edge[x + 3].push_back(j);
                m++;
            }
        }
        for (int j = 1; j <= x + 4; j++) {
            if (color_true[j] == 1) {
                edge[x + 4].push_back(j);
                m++;
            }
        }
    }
    cout << 1024 << " " << m << " " << 2 << endl;
    for (int i = 1; i <= 1024; i++) {
        cout << color_true[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 1024; i++) {
        for (int v : edge[i]) {
            cout << i << " " << v << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}