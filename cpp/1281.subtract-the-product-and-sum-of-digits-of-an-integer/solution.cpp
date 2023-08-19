// Created by zwyyy456 at 2023/08/09 08:56
// leetgo: 1.3.1
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        if (n == 0) {
            return 0;
        }
        while (n != 0) {
            int tmp = n % 10;
            product *= tmp;
            sum += tmp;
            n /= 10;
        }
        return product - sum;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->subtractProductAndSum(n);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
