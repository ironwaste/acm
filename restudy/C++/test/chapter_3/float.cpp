#include<bits/stdc++.h>

#define de(x) cerr<<#x << " " <<x <<" ";
#define deb(x) cerr<<#x << " " <<x <<"\n";

using namespace std;

int main(){

    // cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout.precision(12);

    const float million = 1.0e6;

    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;

    cout << 9 / 5 << endl;
    cout << 9.0 / 5 << endl;
    cout << 9.0 / 5.0 << endl;

    // 未定义的转换形式 所以出现的 结果可能 各个系统等都不大相同
    float mx = 7.2e12;
    int trans = mx;
    long long transll = mx;
    cout << mx << endl;
    deb(trans);
    deb(transll);

    // cout << ", a million tubs = " << million * tub;
    // de(tub);
    // de(mint);
    // cout << tub * million << endl;
    // tub *= million;
    // mint *= million;
    
    // int bb = 100;
    // bb *= 10000 %= 999999;
    // cout << bb << endl;

    
    cout << tub << endl;
    return 0;
}