// Created by zwyyy456 at 2023/10/06 14:50
// leetgo: 1.3.8
// https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool checkArray(vector<int> &nums, int k) {
        // 等价于要求差分数组中每个元素都是 0
        // 子数组元素都减一，等价于使 diff[i] - 1, diff[j + 1] + 1
        // 其中有 [i, j]
        int n = nums.size();
        vector<int> diff(n + 1);
        diff[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            diff[i] = nums[i] - nums[i - 1];
        }
        diff[k] += diff[0];
        diff[0] = 0;
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            sum += diff[i];
            if (sum < 0) {
                return false;
            }
            if (i + k <= n) {
                diff[i + k] += diff[i];
                diff[i] = 0;
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->checkArray(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
