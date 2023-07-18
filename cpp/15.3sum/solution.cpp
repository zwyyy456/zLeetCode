// Created by zwyyy456 at 2023/07/09 21:54
// leetgo: 1.3.1
// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void two_sum(vector<vector<int>> &res, int left, int right, vector<int> &nums, int target, int first) {
        // 左闭右闭
        int l = left, r = right;
        while (l < r) {
            if (l > left && nums[l] == nums[l - 1]) {
                l++;
                continue;
            }
            if (r < right && nums[r] == nums[r + 1]) {
                r--;
                continue;
            }
            if (nums[l] + nums[r] == target) {
                res.push_back({first, nums[l], nums[r]});
                l++;
                r--;
            } else if (nums[l] + nums[r] > target) {
                r--;
            } else {
                l++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int l = 0, mid = 1, r = n - 1;
        for (l = 0; l < n - 2; ++l) {
            // 去重
            if (l >= 1 && nums[l] == nums[l - 1]) {
                continue;
            }
            two_sum(res, l + 1, n - 1, nums, -nums[l], nums[l]);
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

    auto res = obj->threeSum(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
