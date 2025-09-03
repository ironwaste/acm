#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// 编译并运行j-makeup.cpp，生成可执行文件
void compileProgram() {
    system("g++ j-makeup.cpp -o j-makeup.exe -std=c++17 -O2");
}

// 运行程序并比较输出
bool runTest(int testId) {
    string inFile = to_string(testId) + ".in";
    string outFile = to_string(testId) + ".out";
    string myOut = "tmp_" + to_string(testId) + ".out";
    
    // 检查输入文件是否存在
    ifstream testIn(inFile);
    if (!testIn.is_open()) {
        return false; // 输入文件不存在，停止测试
    }
    testIn.close();
    
    // 运行程序
    string command = "j-makeup.exe < " + inFile + " > " + myOut;
    system(command.c_str());
    
    // 比较输出
    ifstream expected(outFile);
    ifstream actual(myOut);
    
    if (!expected.is_open() || !actual.is_open()) {
        cout << "无法打开输出文件!" << endl;
        return false;
    }
    
    string line1, line2;
    int lineNum = 1;
    bool diff = false;
    
    while (getline(expected, line1) && getline(actual, line2)) {
        if (line1 != line2) {
            cout << "第 " << lineNum << " 行不一致:" << endl;
            cout << "期望: " << line1 << endl;
            cout << "实际: " << line2 << endl;
            diff = true;
        }
        lineNum++;
    }
    
    // 检查文件是否同时结束
    if (getline(expected, line1) || getline(actual, line2)) {
        cout << "输出行数不一致!" << endl;
        diff = true;
    }
    
    expected.close();
    actual.close();
    
    // 删除临时文件
    string rmCmd = "del " + myOut;
    system(rmCmd.c_str());
    
    return !diff;
}

int main() {
    cout << "正在编译 j-makeup.cpp..." << endl;
    compileProgram();
    
    cout << "开始对拍测试..." << endl;
    
    int passed = 0;
    int total = 0;
    
    // 测试数据编号从80开始（根据您的文件列表）
    for (int i = 1; i < 83; i++) {
        cout << "测试用例 #" << i << ": ";
        
        if (runTest(i)) {
            cout << "通过!" << endl;
            passed++;
        } else {
            cout << "失败或文件不存在!" << endl;
            // break; // 如果文件不存在，停止测试
        }
        
        total++;
        
        // 添加短暂延迟，避免输出混乱
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
    cout << "对拍完成!" << endl;
    cout << "通过: " << passed << "/" << total << endl;
    
    if (passed == total) {
        cout << "所有测试用例通过!" << endl;
    } else {
        cout << "有测试用例未通过!" << endl;
    }
    
    return 0;
}