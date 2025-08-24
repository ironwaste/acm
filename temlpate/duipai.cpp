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
    while (1) {

        system("data.exe > in.in");
        printf("data.exe > in.in\n");


        system("type in.in");
        printf("type in.in\n");
        system("baoli.exe < in.in > baoli.txt");
        printf("first cout << : \n");
        printf("baoli.exe < in.in > baoli.txt\n");

        // cout << 2 << endl;
        system("std.exe < in.in > std.txt");
        printf("second cout << : \n");
        // system("type in.txt");
        if (system("fc std.txt baoli.txt")) //当 fc 返回 1 时，说明这时数据不一样
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