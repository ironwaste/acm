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
#define de(x) cerr << #x << " " << x <<" ";
#define deb(x) cerr << #x << " " << x <<endl;

using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;
i64 n, u, k, hq;
struct enemy {
    i64 id, a, h, time, beattack;
    // h is life 
    // a is attack 
    // id is num 
    // time is 次数
    // beattack 是否被攻击
    bool ch(i64 u) {
        this->h -= u;
        this->beattack = 1;
        // this->time = (this->h - 1LL) / u;
        if (this->h <= 0)return 1;
        else { return 0; }
    }
    // enemy(i64 u) : h(this.h-u), beaatck(1), time((this.h - 1LL) / u) {};
    friend bool operator<(const enemy a, const enemy b) {
        // if (a.time != b.time) return a.time < b.time;
        if (a.h != b.h) return a.h > b.h;
        else if (a.a != b.a) return a.a > b.a;
        else return a.id > b.id;
    }
};
void solve() {
    cin >> n >> u >> k >> hq;
    i64 tmpn = n;
    vector<enemy> stu(n);
    priority_queue<enemy>q;
    multiset<i64>mx;
    for (i64 i = 0;i < n;i++) {
        cin >> stu[i].a >> stu[i].h;
        mx.insert(stu[i].a);
        stu[i].beattack = 0;
        stu[i].id = i;
        stu[i].time = (stu[i].h + u - 1LL )/ u;
        if (stu[i].time <= k)q.push(stu[i]);
        else { tmpn--; }
    }
    sort(all(stu));
    // for (auto k : stu) {
    //     de(k.id)de(k.h)deb(k.a);
    // }
    // for (auto x: mx) {
    //     deb(x)
    // }

    while (hq && !q.empty()) {

        enemy p = q.top();
        q.pop();
        auto iter = mx.end();
        iter--;
        // de(p.h)de(p.a)deb(p.id);
        i64 k;
        if (p.h <= u) {
            mx.erase(mx.find(p.a));
            i64 v = 0;
            if (!mx.empty()) {
                iter = mx.end();
                iter--;
                v = *iter;
            }
            hq -= v;
            // de(v)deb(hq)
            continue;
        }
        k = (p.h - u + (u/2)- 1LL) / (u / 2) + 1LL;
        i64 tmpu = (u / 2);
        i64 dhqh = (k - 1LL) * (*iter);
        // de(k)de(hq)de(k*(*iter))deb(dhqh)
        mx.erase(mx.find(p.a));
        i64 v = 0;
        if (!mx.empty()) {
            iter = mx.end();
            iter--;
            v = *iter;
        }
        if (hq > dhqh) {
            hq -= dhqh;
            // auto iter1 = mx.end();
            // iter1--;
            hq -= v;
        } else {
            q.push(p);
            break;
        }
    }
    cout << tmpn - q.size() << endl;
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