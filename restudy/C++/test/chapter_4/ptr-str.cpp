#include<iostream>

using namespace std;

struct inflaatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    inflaatable* ps = new inflaatable;
    cout << "ps is :  "<<ps << endl;
    // cout << "*ps is :  "<<(*ps) << endl;
    cout << "please input the name : " << endl;
    cin.get(ps->name, 20);
    cout << "the ps's name is : " << ps->name << endl;
    cout << "please input the volume : " << endl;

    // difference is the member operator  which is . and ->
    cin >> ps->volume
    cout << "the ps's volume is : " << (*ps).volume << endl;
    

    delete ps;
    // new 和 delete 需要搭配使用。

    // cout << 0 << endl;
    return 0;
}