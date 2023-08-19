// Created by zwyyy456 at 2023/08/19 14:11
// leetgo: 1.3.1
// https://leetcode.com/problems/add-two-integers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int num1;
    LeetCodeIO::scan(cin, num1);
    int num2;
    LeetCodeIO::scan(cin, num2);

    Solution *obj = new Solution();

    auto res = obj->sum(num1, num2);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
