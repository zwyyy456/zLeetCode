// Created by zwyyy456 at 2023/10/17 09:37
// leetgo: 1.3.8
// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 3) {
            return 0;
        }
        int n = nums.size();
        int res = 0;
        vector<unordered_map<long, long>> dp(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)nums[i] - nums[j];
                dp[i][diff] += 1 + dp[j][diff];
                res += 1 + dp[j][diff];
            }
        }
        return res - n * (n - 1) / 2;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->numberOfArithmeticSlices(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
