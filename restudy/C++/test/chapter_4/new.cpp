#include<bits/stdc++.h>

#define de(x) cerr<<#x << " " <<x <<" "

using namespace std;

int main(){
    int* pn = new int;
    cout << "pn :"<< pn << endl;
    cout << "*pn :"<<*pn << endl;
    delete pn;
    cout << "pn :"<< pn << endl;// is exited
    //  cout << *pn <<endl; is wrong beacuse *pn is deleted
    // delete pn 指针所指向的值的内存块删除
    // 动态数组
    int* psv = new int[30];
    cout << psv << endl;
    cout <<"pre : " <<psv[0] << endl;
    // 如何使用动态数组
    // 在c和c++ 中 指针和数组的使用几乎等价，数组就是以指针形式实现
    psv[0] = 1;
    cout << "after : " <<psv[0] << endl;
    // 根本区别在于，数组名不可修改，但是指针变量是可以进行修改的，指针变量的修改，相当于地址的修改
    // 其加减 相当于数组内移位

    // 对应于 delete []
    delete[] psv;

    return 0;
}


// arraynew.cpp -- using the new operator for arrays
// #include <iostream>
// int main()
// {
//     using namespace std;
//     double * p3 = new double [3]; // space for 3 doubles
//     p3[0] = 0.2;                  // treat p3 like an array name
//     p3[1] = 0.5;
//     p3[2] = 0.8;
    // 根本区别在于，数组名不可修改，但是指针变量是可以进行修改的，指针变量的修改，相当于地址的修改
    // 其加减 相当于数组内移位
    
//     cout << "p3[1] is " << p3[1] << ".\n";
//     p3 = p3 + 1;                  // increment the pointer
//     cout << "Now p3[0] is " << p3[0] << " and ";
//     cout << "p3[1] is " << p3[1] << ".\n";
//     p3 = p3 - 1;                  // point back to beginning
//     delete [] p3;                 // free the memory
//     return 0; 
// }
