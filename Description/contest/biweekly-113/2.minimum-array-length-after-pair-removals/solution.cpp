// Created by zwyyy456 at 2023/09/16 22:30
// leetgo: 1.3.5
// https://leetcode.cn/problems/minimum-array-length-after-pair-removals/
// https://leetcode.cn/contest/biweekly-contest-113/problems/minimum-array-length-after-pair-removals/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minLengthAfterRemovals(vector<int> &nums) {
        // 二分答案?
        // 栈底到栈顶单调递增
        map<int, int> recs;
        int maxnum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->minLengthAfterRemovals(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
