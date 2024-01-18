// Created by zwyyy456 at 2024/01/16 13:40
// leetgo: 1.3.8
// https://leetcode.com/problems/count-of-integers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int DigitDp(string &num, int sum, int flag) {
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        // 求 <= a 的数中，sum_digit <= b 的数的个数
        // 数位 dp
        return DigitDp(num2, max_sum, 0) - DigitDp(num1, max_sum, 1) - DigitDp(num2, min_sum - 1, 0) + DigitDp(num1, min_sum - 1, 1);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string num1;
    LeetCodeIO::scan(cin, num1);
    string num2;
    LeetCodeIO::scan(cin, num2);
    int min_sum;
    LeetCodeIO::scan(cin, min_sum);
    int max_sum;
    LeetCodeIO::scan(cin, max_sum);

    Solution *obj = new Solution();
    auto res = obj->count(num1, num2, min_sum, max_sum);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
