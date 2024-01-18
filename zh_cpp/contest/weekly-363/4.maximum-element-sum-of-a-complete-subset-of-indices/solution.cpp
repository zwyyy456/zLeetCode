// Created by zwyyy456 at 2023/09/17 10:33
// leetgo: 1.3.5
// https://leetcode.cn/problems/maximum-element-sum-of-a-complete-subset-of-indices/
// https://leetcode.cn/contest/weekly-contest-363/problems/maximum-element-sum-of-a-complete-subset-of-indices/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    long long maximumSum(vector<int> &nums) {
        // 完全子集，要么都是完全平方数，要么都不是
        int n = nums.size();
        long long res = 0;
        // 单子集的情况
        for (int i = 1; i * i <= n; ++i) {
            res = max(res, static_cast<long long>(nums[i * i - 1]));
        }
        // 多个子集
        for (int i = 1; 4 * i <= n; ++i) {
            long long tmp = 0;
            for (int j = 1; i * (j * j) <= n; ++j) {
                tmp += nums[i * j * j - 1];
            }
            res = max(tmp, res);
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
    auto res = obj->maximumSum(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
