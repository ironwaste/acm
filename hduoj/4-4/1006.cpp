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
#define double long double
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;

bool dis(i64 x, i64 y, i64 d, i64 r) {
    return x * x+ (y - d) * (y - d) <= r * r;
}
i64 ansdis(double x, double y, double d, double r) {
    return round(1.0*r - 1.0*sqrt(1.0*x * x + (y - d) * (y - d)));
}
i64 ansr(double x, double y, double d, double r) {
    return round(1.0*sqrt(1.0*x * x+ (y - d)*(y - d)) - 1.0*r);
}

void solve() {
    double d, r, x, y;
    cin >> d >> r >> x >> y;
    if (y <= d && y >= -d) { // 在 矩形上下空间内 
        cout << min(abs(r - x), abs(-r - x))<<endl;
        return;
    }
    if (y > d && x >= -r && x <= r && dis(x, y, d, r)) { //  上半圆内
        cout << (i64)ansdis(x,y,d,r) << endl;    
        return;
    }

    if (y < -d && x >= -r && x <= r && dis(x, y, -d, r)) {//  下半圆内
        cout << (i64)ansdis(x, y, -d, r) << endl;
        return;
    }
    if (y > d) { // 上半圆外
        cout << ansr(x,y,d,r) << endl;
    } else{ // 下半圆外
        cout << ansr(x, y,-d,r) << endl;
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