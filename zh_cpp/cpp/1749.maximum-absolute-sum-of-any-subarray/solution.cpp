// Created by zwyyy456 at 2023/08/08 09:11
// leetgo: 1.3.5
// https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxAbsoluteSum(vector<int> &nums) {
        int n = nums.size();
        vector<int> dpmax(n);
        dpmax[0] = nums[0];
        int res = 0;
        for (int i = 1; i < n; ++i) {
            dpmax[i] = max(dpmax[i - 1] + nums[i], nums[i]);
            res = max(res, abs(dpmax[i]));
        }
        vector<int> dpmin(n);
        dpmin[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dpmin[i] = min(dpmin[i - 1] + nums[i], nums[i]);
            res = max(res, abs(dpmin[i]));
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->maxAbsoluteSum(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
