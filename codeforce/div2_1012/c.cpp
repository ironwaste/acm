// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#include<bits/stdc++.h>
#include<climits>
#include<queue>

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
vector<pll>xy;
vector<i64>num;
const int N = 1e3 + 100;
void init() {
    for (int sum = 0;sum < N;sum ++) {
        for (int x = 0;x <= sum;x ++) {
            xy.pb(make_pair(x, sum - x));
        }
    }
    i64 ans = 0;
    for (int i = 1;i <= N + 1;i++) {
        ans += i;
        num.pb(ans);
    }
}
struct Node {
    i64 x, y;
    i64 dis;
};

bool operator==(Node a, Node b) {
    if (a.dis == b.dis && a.x == b.x && a.y == b.y)return true;
    return false;
}
bool operator<(Node a, Node b) {
    if (a.dis != b.dis) { return a.dis > b.dis; } 
    else if (a.x != b.x) { return a.x > b.x; }
    else { return a.y > b.y; }
}
Node make_Node(i64 x, i64 y,i64 dis) {
    Node tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.dis = dis;
    return tmp;
}

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    i64 sum0 = 0;
    for (auto& x : a) {
        cin >> x;
        sum0 += (x == 0);
    }
    // 1 、维护所有的空位
    // 2、 维护未被占据的桌子的 空位  or 维护占据的桌子
    i64 mx = num.size() - 1LL;
    i64 lim = num[min(lower_bound(all(num), n) - num.begin() + 2LL,mx)];
    priority_queue<Node>q, q_occupy;

    // deb(lim)

    for (int i = 0;i <= lim;i++) {
        // de(xy[i].fi)deb(xy[i].se)
        q.push(make_Node(3LL * xy[i].fi + 1LL, 3LL * xy[i].se + 1LL,3LL * (xy[i].fi + xy[i].se) + 2LL));
        q.push(make_Node(3LL * xy[i].fi + 2LL, 3LL * xy[i].se + 1LL,3LL * (xy[i].fi +  xy[i].se) + 3LL));
        q.push(make_Node(3LL * xy[i].fi + 2LL, 3LL * xy[i].se + 2LL,3LL * (xy[i].fi +  xy[i].se) + 6LL));
        q.push(make_Node(3LL * xy[i].fi + 1LL, 3LL * xy[i].se + 2LL,3LL * (xy[i].fi +  xy[i].se) + 3LL));
    }

    set<pll>st;
    for (auto x : a) {
        if (x == 1) {
            Node tmp = q.top();
            // de(tmp.x)de(tmp.y)deb(tmp.dis)
            if (!q_occupy.empty()) {
                Node k = q_occupy.top();
                de(k.x)de(k.y)deb(k.dis)
                if (k < tmp) {
                    q.pop();
                } else {
                    tmp = k;
                    q_occupy.pop();
                }
            } else {
                // int cnt = 0;
                // Node tmk = q.top();
                // while (tmk == tmp) {
                //     cnt++;
                q.pop();
                //     tmk = q.top();
                //     // de(cnt);
                // }
            }
            cout << tmp.x << " " << tmp.y << endl;
            i64 nx = tmp.x  / 3, ny = tmp.y / 3;
            pll k = make_pair(nx, ny);
            st.insert(k);
        } else {
            while (!q.empty()) {
                Node tmp = q.top();
                i64 nx = q.top().x / 3, ny = q.top().y / 3;
                pll k = make_pair(nx, ny);
                if (st.count(k)) {
                    q_occupy.push(q.top());
                    q.pop();
                    // cout << "q_occupy: ";de(q.top().x)deb(q.top().y)
                } else {
                    // de(q.top().x)deb(q.top().y)
                    cout << q.top().x << " " << q.top().y << endl;
                    st.insert(k);
                    q.pop();
                    break;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init(); 
    // for (auto [x,y] : xy) {
    //     if (x + y >= 20)break;
    //     de(x)deb(y)
    // }
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}