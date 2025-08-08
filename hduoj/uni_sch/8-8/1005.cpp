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

// 2025.08.08——12:54:29
// 2025.08.08——13:13:02 accpted
/*
 *
 *
**/

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int a[30][30];
    for (int i = 0;i < 30;i++) {
        for (int j = 0;j < 30;j++) {
            a[i][j] = 0;
        }
    }
    int tap = 1;
    while(k--){
        int x,y;
        cin >> x >> y;
        x += 9;
        y += 9;
        a[x][y] = tap;
        a[x-1][y] = tap;
        for(int i=y-2;i<=y+2;i++)
            a[x-2][i] = tap;
        for(int i=y-1;i<=y+1;i++)
            a[x-3][i] = tap;
        a[x-4][y] = tap;
        tap++;
    }

    for(int i=10;i<n+10;i++){
        for(int j=10;j<m+10;j++){
            if(a[i][j] == 0) cout << '.';
            else cout << a[i][j];
        }
        cout << endl;
    }
    return;
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