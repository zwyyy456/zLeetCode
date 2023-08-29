// Created by zwyyy456 at 2023/08/03 09:17
// leetgo: 1.3.1
// https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int findNthDigit(int n) {
        if (n <= 9) {
            return n;
        }
        int i = 1;
        int sum = 10, pre_sum = 0;
        while (sum < n) {
            pre_sum = sum;
            ++i;
            sum += i * 9 * pow(10, i - 1);
        }
        int num = pow(10, i - 1) + (n - pre_sum) / i;
        int cnt = i - (n - pre_sum) % i;
        while (cnt-- != 0) {
            num /= 10;
        }
        return num % 10;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->findNthDigit(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
