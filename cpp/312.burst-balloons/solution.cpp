// Created by zwyyy456 at 2023/08/10 23:00
// leetgo: 1.3.5
// https://leetcode.com/problems/burst-balloons/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);
        for (int i = 1; i < n + 1; ++i) {
            balloons[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 0; i < n + 2; ++i) {
            dp[i][i] = balloons[i];
            if (i < n + 1) {
                dp[i][i + 1] = balloons[i] * balloons[i + 1];
            }
        }
        for (int l = n + 1; l >= 0; --l) {
            for (int r = l + 2; r < n + 2; ++r) {
                for (int i = l + 1; i < r; ++i) {
                    dp[l][r] = max(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + balloons[i] * balloons[i + 1] * balloons[i - 1]);
                }
            }
        }
        return dp[0][n + 1];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->maxCoins(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
