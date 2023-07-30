// Created by zwyyy456 at 2023/07/22 17:57
// leetgo: 1.3.2
// https://leetcode.com/problems/find-pivot-index/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int sum = 0;
        if (total - nums[0] == 0) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            sum += nums[i - 1];
            if (2 * sum + nums[i] == total) {
                return i;
            }
        }
        return -1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();

    auto res = obj->pivotIndex(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
