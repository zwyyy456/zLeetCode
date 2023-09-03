// Created by zwyyy456 at 2023/08/29 14:10
// leetgo: 1.3.5
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <bits/stdc++.h>
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool dfs(vector<int> &nums, int state, int sum, int target, vector<int> &cache) {
        if (state == (1 << nums.size()) - 1) {
            return sum == 0;
        }
        if (cache[state] >= 0) {
            return cache[state] == 1;
        }
        int n = nums.size();
        bool res = false;
        for (int i = 0; i < n; ++i) {
            if ((state & (1 << i)) != 0) {
                continue;
            }
            if (sum + nums[i] > target) {
                continue;
            }
            if (sum + nums[i] == target) {
                res |= dfs(nums, state | (1 << i), 0, target, cache);
            } else {
                res |= dfs(nums, state | (1 << i), sum + nums[i], target, cache);
            }
        }
        cache[state] = res ? 1 : 0;
        return res;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 状压 dp
        int can = (1 << n) - 1;
        vector<int> cache(1 << n, -1);
        return dfs(nums, 0, 0, sum / k, cache);
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
    auto res = obj->canPartitionKSubsets(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
