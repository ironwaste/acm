#include<bits/stdc++.h>

#define de(x) cerr<<#x << " " <<x <<" "

using namespace std;

int main(){
    int dx = 10;
    double dy = 11.100;
    cout << "dx's value is : " << dx << endl;
    cout << "dx's address is(hex) : "<< &dx << endl;

    cout << endl;

    cout << "dy's value is : " << dy << endl;
    cout << "dy's address is(hex) : "<< &dy << endl;

    // indirect value(10000)
    int kz = 10000;
    int* kk = &kz;

    auto k = &dy;
    cout << *k << endl;
    cout << "*kk's value is : " << *kk <<endl;

    // declare and init pointor
    // p1 is pointor but p2 is int

    int* p1, p2;

    



    return 0;
}