// Created by zwyyy456 at 2023/07/09 22:30
// leetgo: 1.3.1
// https://leetcode.com/problems/subsets-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void dfs(vector<vector<int>> &res, int idx, bool pre_choose, int n, vector<int> &choosed, vector<int> &nums) {
        // 枚举选或者不选
        if (idx == n) {
            res.push_back(choosed);
        }
        dfs(res, idx + 1, false, n, choosed, nums);
        if (!pre_choose && idx >= 1 && nums[idx] == nums[idx - 1]) {
            return;
        }
        choosed.push_back(nums[idx]);
        dfs(res, idx = 1, true, n, choosed, nums);
        choosed.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> choosed;
        dfs(res, 0, true, n, choosed, nums);
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

    auto res = obj->subsetsWithDup(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
