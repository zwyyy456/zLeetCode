// Created by zwyyy456 at 2023/08/02 13:50
// leetgo: 1.3.1
// https://leetcode.cn/problems/1fGaJU/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int l, mid, r;
        int n = nums.size();
        for (l = 0; l < n - 2; ++l) {
            if (l > 0 && nums[l] == nums[l - 1]) {
                continue;
            }
            mid = l + 1, r = n - 1;
            while (mid < r) {
                if (mid > 1 && nums[mid] == nums[mid - 1]) {
                    ++mid;
                    continue;
                }
                if (r < n - 1 && nums[r] == nums[r + 1]) {
                    --r;
                    continue;
                }
                if (nums[l] + nums[mid] + nums[r] == 0) {
                    res.emplace_back(nums[l], nums[mid], nums[r]);
                    ++mid;
                    --r;
                } else if (nums[l] + nums[mid] + nums[r] > 0) {
                    --r;
                } else {
                    ++mid;
                }
            }
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
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
