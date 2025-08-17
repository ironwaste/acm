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

// 2025.07.19——23:10:46
/* 
 * (abs(x1-x2) + abs (y1-y2))  ==
 * max(abs(x1 + y1 - x2 - y2) , abs(x1 - y1 - x2 + y2) ) ) )
 * x1 >= x2 == abs(x1 - x2) <==> x1 - x2
 * 反之 x2 - x1;
 * y1 >= y2 ==> abs(y1 - y2) <==>y1 - y2;
 * 反之 y2 - y1;
 *
 * 所以就是 两个加号 + 两个减号
 * 所以可以进行两次排序,?
 *
 * 1.  (x1 + y1)  - (x2 + y2)  (x1 >= x2 && y1 >= y2)
 * 2.  (x1 - y1)  - (x2 - y2)  (x1 >= x2 && y1 < y2)
 * 3. -(x1 + y1)  + (x2 + y2)  (x1 < x2 && y1 >= y2)
 * 4. -(x1 - y1)  + (x2 - y2)  (x1 < x2 && y1 < y2)
 *
*/

struct node {
    i64 x, y,id;
    // friend bool operator<(const node& a, const node& b) {
    //     if ((a.x >= b.x && a.y >= b.y) || (a.x < b.x && a.y < b.y)){
    //         // abs(a.x + a.y - (b.x + b.y) );
    //         return a.x + a.y < b.x + b.y;
    //     } else {
    //         // abs(a.x - a.y - (b.x - b.y) );
    //         return a.x - a.y < b.x - b.y;
    //     }
    // };
};


void solve() {
    i64 n;
    cin >> n;
    vector<node>a(n);
    for (i64 i = 0;i < n;i++) {
        i64 x, y;
        cin >> x >> y;
        a[i].x = x, a[i].y = y;
    }
    vector<i64>order(n,0);
    iota(all(order), 1);
    sort(all(order), [&](int i, int j) {
        return a[i-1].x < a[j-1].x;
        });

    sort(order.begin(),order.begin() + n / 2, [&](int i, int j) {
        return a[i-1].y < a[j-1].y;
        });
    
    sort(order.begin()+n/2,order.end(), [&](int i, int j) {
        return a[i-1].y < a[j-1].y;
        });

    for (int i = 0,j = n-1;i < n / 2;j--,i ++) {
        cout << order[i] <<" "<< order[j] << endl;
    }
    
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