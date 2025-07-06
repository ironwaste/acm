#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define endl '\n'
#define i64 long long
#define fi first
#define se second
#define Endl endl
#define END endl
#define all(x) x.begin(),x.end()
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;


// 补题——题目链接:https://codeforces.com/contest/2119/problem/B
// 网址：https://www.desmos.com/geometry/xmwdunnjar?lang=zh-CN
// 2025.07.06——14:11:32
/*
该题目，按照顺序来进行，其实是可以更改为乱序进行，因为当我们将前面的向反方向排布
的时候，某种意义上即是可以通过不同方位的排布实现最后的乱序
关于点的 point tmplate<class T>类
*/

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};


void solve() {
    int N;
    cin >> N;
    Point<i64>p, q;
    cin >> p.x >> p.y >> q.x >> q.y;
    i64 d = (p - q).dist2();
    vector<i64>a(N);
    for (auto& x : a) { cin >> x; }
    sort(all(a));
    i64 l = a.back(),r= a.back();
    for (int i = 0;i < N - 1;i++) { l -= a[i]; r += a[i]; }
    l = max(l, 0LL);
    cout << ((d >= l * l && d <= r * r) ? "Yes\n" : "No\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
