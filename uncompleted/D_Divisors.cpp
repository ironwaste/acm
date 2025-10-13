#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 计算最大公约数
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 质因数分解，返回质因数及其对应的指数
map<int, int> prime_factors(int n) {
    map<int, int> factors;
    for (int d = 2; d * d <= n; ++d) {
        while (n % d == 0) {
            factors[d]++;
            n /= d;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

// 计算约数个数
int num_divisors(const map<int, int>& factors) {
    int divisors = 1;
    for (auto& p : factors) {
        divisors *= (p.second + 1);
    }
    return divisors;
}

int main() {
    int n;
    cin >> n;  // 输入整数的个数

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];  // 输入所有的整数
    }

    int total_divisors = 1;

    // 计算所有整数对的 gcd，并提取共享的质因子
    for (int i = 0; i < n; ++i) {
        map<int, int> factors = prime_factors(nums[i]);
        total_divisors *= num_divisors(factors);  // 计算约数个数并乘上
    }

    // 输出结果
    cout << total_divisors << endl;
    return 0;
}
