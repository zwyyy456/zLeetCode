// Created by zwyyy456 at 2023/07/11 22:19
// leetgo: 1.3.2
// https://leetcode.com/problems/maximum-alternating-subsequence-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    long long maxAlternatingSum(vector<int> &nums) {
        int n = nums.size();
        vector<long> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + nums[i] - nums[i - 1];
            }
        }
        return dp[n - 1];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();

    auto res = obj->maxAlternatingSum(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
