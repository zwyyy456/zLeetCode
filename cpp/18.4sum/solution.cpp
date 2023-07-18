// Created by zwyyy456 at 2023/07/15 23:07
// leetgo: 1.3.2
// https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) {
                        ++k;
                        continue;
                    }
                    long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        --l;
                    } else if (sum < target) {
                        ++k;
                    } else {
                        --l;
                    }
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
    int target;
    LeetCodeIO::scan(cin, target);

    Solution *obj = new Solution();

    auto res = obj->fourSum(nums, target);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
