#include<bits/stdc++.h>

#define de(x) cerr<<#x << " " <<x <<" "
// 2025.08.02——12:44:06
using namespace std;

int main() {
    int data[3][4] = {{1,2,3,4},{5,6,7,8},{1,3,4,7}};
    int c = 1;
    cout << **(data + c) << endl;
    return 0;
}