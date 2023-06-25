// Created by zwyyy456 at 2023/06/17 20:01
// leetgo: 1.3.1
// https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numberOfCuts(int n) {
        if (n % 2 == 1) {
            return n;
        }
        return n / 2;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->numberOfCuts(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
