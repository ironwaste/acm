#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define i64 long long

i64 pw(i64 a, i64 b) {
    i64 res = 1LL;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

i64 calc(i64 n) {
    if (n == 0) return 0;
    string s = to_string(n);
    i64 len = s.size();
    i64 p = pw(10LL, len - 1);
    i64 d = (i64)(s[0] - '0');
    i64 r = n % p;
    
    i64 current_ans = 0;
    current_ans += (d + 1) * d / 2 * p;
    current_ans += d * (r + 1);
    
    // 计算剩余数字的贡献
    for (i64 i = 1; i < len; i++) {
        i64 digit = (i64)(s[i] - '0');
        current_ans += digit;
    }
    
    return current_ans + calc(r);
}

i64 find_number(i64 k) {
    i64 len = 1;
    while (true) {
        i64 numbers_in_len = 9LL * pw(10LL, len - 1);
        i64 total_digits = numbers_in_len * len;
        
        if (k <= total_digits) {
            i64 start_num = pw(10LL, len - 1);
            i64 number_index = (k - 1) / len;
            i64 digit_index = (k - 1) % len;
            i64 target_num = start_num + number_index;
            
            // 返回指定数字的第几位
            string num_str = to_string(target_num);
            return (i64)(num_str[digit_index] - '0');
        }
        k -= total_digits;
        len++;
    }
}

void solve() {
    i64 k;
    cin >> k;
    i64 result = find_number(k);
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}