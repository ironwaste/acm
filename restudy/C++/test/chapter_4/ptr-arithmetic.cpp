#include<bits/stdc++.h>
#include<typeinfo>

#define de(x) cerr<<#x << " " <<x <<" "

using namespace std;

int main() {
    double wages[3]={10.0,20.0,30.0};
    short stack[3] = { 3,2,1 };
    double* pw = wages;
    short* ps = &stack[0];
    // double* pwn, * pd;
    // if like double *pwn,pd; 
    // then the *pwn is ptr but pd is double type value;

    // cout << pwn << " : " << pd << endl;
    cout << pw << endl;

    // short *a;
    // wages = &wages[0];
    // pw == wages == &wages[0];
    cout << "wages  :" << wages << endl;

    // pw + 1  = pw + sizeof(*pw) ;
    // decltype()


    cout << typeid(pw).name() << endl;
    cout << sizeof(*pw) << endl;

    // cout << sizeof(*a) << endl;
    // cout << sizeof(typeid(a).name()) << endl;

    
    cout << "pw + 1 : " << pw + 1 << endl;

    // stack[1] is equal *(stack + 1)
    cout << endl << "stack[1]  : is " << stack[1] << " ---- *(ps+1) is : " << *(ps + 1) << endl;
    cout << "(stack + 1) is : " << *(stack + 1) << endl;

    int kk[20];
    cout << kk << endl;
    cout << &kk[0] << endl;
    cout << &kk << endl;

    int* pt = new int[10];
    *pt = 5;
    // new int init value is (zero) 0; 
    cout << " *pt is :" << *pt << "  |  pt[0] : " << pt[0]<< endl;
    cout << pt[9] << endl;
    pt[0] = 11;
    pt[9] = 22;
    cout << pt[9] << endl;
    cout << " *pt is :" << *pt << "  |  pt[0] : " << pt[0] << endl;
    return 0;
}


/*
    1、声明
        typename * ptrname;
        created by new
        typename * ptrname = new typename ;
        typename * ptrname = new typename[size] ;    

    2、给指针赋值

        created by new and assign a value for ptr 
        typename * ptrname = new typename ;
        typename * ptrname = new typename[size] ;

        or &

        double *pn,*pa;
        double bubble = 2.3333;
        pn = & bubble;
        



    3、对指针解除引用
    like cout << * pn <<endl;
    the * symbol is Dequote 

    4、区分指针 和 指针所指向的值
    int * ptr = new int; // assign an address to the pointer pt
    \*pt = 5 // stores the value 5 at that address
    store is 存储 memory / storage



    5、数组名 ： 数组名 代表 着第一个元素的地址

    6、指针算术 ：指针的算术 相当于 指针地址 根据其类型进行加减相应的字节数

    7、数组的动态联编 和 静态联编 ：
        like int arr[20]; is 静态联编 static co-editing 
        使用数组声明 来创建数组时，将采用静态联编，即数组的长度在编译时的设置

        使用new 创建的时候， 则使用的是 动态联编 在运行时进行内存的分配

    8、数组表示法 和 指针表示法
        int * pt = new int[10];
        \*pt = 5;
*/
