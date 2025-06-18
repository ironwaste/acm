#include<iostream>
using namespace std;
const int Cities = 5;
const int Years = 4;

int main() {
    char c;
    c = cin.get();
    cout << "eof is : " << cin.eof() << "  |  fail is :" << cin.fail() << endl;

    const char* cities[Cities] = {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble", "Gribble Vista"
    };

    int maxtemps[Years][Cities] = // 2-D array
    {
        {96, 100, 87, 101, 105}, // values for maxtemps [0]
        {96, 98, 91, 107, 104}, // values for maxtemps [1]
        {97, 101, 93, 108, 107}, // values for maxtemps [2]
        {98, 103, 95, 109, 108} // values for maxtemps [3]
    };
    cout << "Maximum temperatures for 2008 - 2011\n\n";
    for (int city = 0; city < Cities; ++city) {
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";
        cout << endl;
    }
    // cin.get();
    /* 输出结果
        Maximum temperatures for 2008 - 2011

        Gribble City: 96 96 97 98
        Gribbletown: 100 98 101 103
        New Gribble: 87 91 93 95
        San Gribble: 101 107 108 109
        Gribble Vista: 105 104 107 108
    */
    char citiess[Cities][26] = {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };

    for (int city = 0;city < 3;city ++) {
        cout << citiess[city] << endl;
    }
    // 这个时候 cout 输出的结束是根据最后的'\0' 来判断  

    
    return 0;
}

