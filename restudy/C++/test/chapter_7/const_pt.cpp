#include<bits/stdc++.h>
#define de(x) cerr<<#x << " " <<x <<" ";
#define deb(x) cerr<<#x << " " <<x <<" \n";

using namespace std;

const int mouths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int sum_arr(const int arr[],int n);
int main() {
    int age = 39;
    const int *pt = &age; 
    deb(pt);
    // *pt += 1;// 是会被禁止的，因为 pt指针是一个常量
    // cin >> *pt; // 也是会被禁止的
    pt ++; // 也是被禁止的
    deb(pt);
    int j = sum_arr(mouths, 12);
    deb(j);

    return 0;
}
// int sum_arr(int arr[],int n);
int sum_arr(const int arr[], int n) {
    int res = 0;
    for (int i = 0;i < n;i++) {
        res += arr[i];
    }
    return res;
}