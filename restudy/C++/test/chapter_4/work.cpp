#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define de(x) cerr<<#x << " " <<x <<" ";
#define deb(x) cerr<<#x << " " <<x <<" \n";

using namespace std;

// 8 fish
struct fish {
    
    string ki;
    int weight;
    double inch;
};

enum Response { no = 0,yes = 1, maybe = 2 };

// enum 9 
int main() {
    // a. 
    vector<char>actor(30);
    vector<short>betsie(100);
    vector<float>chunk(13);
    vector<long double>dipsea(64);

    // array
    array<char, 30>actor1;
    array<short,100>betsie1;
    array<float,13>chunk1;
    array<long double, 64>dipsea1;

    array<int, 5>odd = { 1,3,5,7,9 };
    for (auto x : odd) { cout << x << endl; }

    // 4
    vector<int>even;
    even.pb(odd[0]);
    even.pb(odd.back());

    // 5
    vector<float>ideas(2);
    de(ideas[1]);
    // cout << ideas[1] << endl;

    // 6
    // vector<char>cha = { "cheeseburger" };
    char k[] = "cheeseburger";
    cout << k << endl;

    // 7
    string tmp = "Waldorf Salad";
    de(tmp);


    // 9
    fish f = { "haha",10,11.1 };
    de(f.inch);
    de(f.weight);
    deb(f.ki);

    // 10
    Response ck,ckyes,maybe;
    ck = Response(2);
    ckyes = yes;
    maybe = maybe;
    // cout << ck << endl;
    deb(ck);
    de(maybe);
    deb(ckyes);

    // 11
    double ted = 1000.00;
    double* tedp;
    tedp = &ted;
    // cout << tedp << " " << 
    de(tedp)deb(*tedp);

    // 12 
    double treacle[10] = {0,1,2,3,4,5,6,7,8,9};
    double* ps0 = &treacle[0], * ps10 = &treacle[9];
    de(*ps0)deb(*ps10);


    // 13 new 动态数组？？ 还真不会
    // cout << " 请输入 素组 的大小" << endl;
    // vector<int>vi;
    // int size;
    // cin >> size;
    // int * d = new int [size]; 
    // vi.resize(size);
    // vector<int>vi(siz);

    // 14  
    de("-------")de(14)deb("----------")
    cout << (int*)"Home of the jolly bytes" << endl;


    //15  note ： ！！ the new return's vlaue is pointor
    fish *fishk = new fish;
    fishk->inch = 10;
    fishk->weight = 10;
    de(fishk->inch)deb(fishk->weight);

    // 16 







    

    return 0;
}