// Created by zwyyy456 at 2023/10/20 10:47
// leetgo: 1.3.8
// https://leetcode.com/problems/largest-divisible-subset/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> ust(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1;
        int idx = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (res < dp[i]) {
                        idx = i;
                        res = dp[i];
                    }
                }
            }
        }
        vector<int> ans;
        ans.push_back(nums[idx]);
        for (int i = idx - 1; i >= 0; --i) {
            if (nums[idx] % nums[i] == 0 && dp[idx] == dp[i] + 1) {
                ans.push_back(nums[i]);
                idx = i;
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->largestDivisibleSubset(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
