// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
#include<bits/stdc++.h>
#include<climits>
#include<chrono>
#include<thread>

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


int main() {
    // system("dir");
    for(int i = 1;i < 81;i++){
        string stdexe = "j-makeup.exe ";
        string in,out,stdans;
        in = to_string(i) + ".in ";
        out = to_string(i) + ".out ";
        stdans = "std.out ";

        string output = stdexe + " < " + in + " > " + stdans;
        string fc = "fc " + stdans + out;
        char* p = (char*) output.data();
        system(p);
        cout << output << endl;

        p = (char*)fc.data();
        if (system(p)) //当 fc 返回 1 时，说明这时数据不一样
            break;
        else {
            printf("not diff \n\n\n ");
        }

        // sleep_for(nanoseconds(10));
        // sleep_until(system_clock::now() + seconds(1));
        // _sleep(100);
    }
    return 0;
}