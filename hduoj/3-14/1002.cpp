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


// j.y.b.d.w.g.x.r

// z.c.y.m.w.s.x.h

// b.d.j.w.r.x.y
// c.m.h.s.x.y.z
// c.m.h.s.x.y.z

// const char tiangan[] = {"","","",""}

void solve() {
    string s;
    cin >> s;
    map<string, int>mp,mmp;
    mp["jia"] = 1;
    mp["yi"] = 2;
    mp["bing"] = 3;
    mp["ding"] = 4;
    mp["wu"] = 5;
    mp["ji"] = 6;
    mp["geng"] = 7;
    mp["xin"] = 8;
    mp["ren"] = 9;
    mp["gui"] = 10;

    mmp["zi"] = 1;
    mmp["chou"] = 2;
    mmp["yin"] = 3;
    mmp["mao"] = 4;
    mmp["chen"] = 5;
    mmp["si"] = 6;
    mmp["wu"] = 7;
    mmp["wei"] = 8;
    mmp["shen"] = 9;
    mmp["you"] = 10;

    mmp["xu"] = 11;
    mmp["hai"] = 12;

    string tian = "", di = "";
    tian += s[0];
    int sz = s.size();
// c.m.h.s.x.y.z
    int index = 0;
    for (int i = 1;i < sz;i++) {
        if (s[i]=='w'||s[i] == 'c' || s[i] == 'm' || s[i] == 'h' || s[i] == 's' || s[i] == 'x' || s[i] == 'y' || s[i] == 'z') {
            index = i;break;
        } else {
            tian += s[i];
        }
    }
    di = s.substr(index, sz - index);
    // de(tian)deb(di)
    int t = mp[tian], d = mmp[di];
    // de(t)deb(d)
    if (t == d) {
        cout << 1983 + t << endl;
    } else if (t > d) {
        int tmp = t - d;
        tmp /= 2;
        tmp *= 10;
        cout << 1983 + tmp + t<< endl;
    } else {
        int tmp = 12 - d + t;
        tmp /= 2;
        tmp *= 10;
        cout << 1983 + tmp + t << endl;
    
    }


    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}