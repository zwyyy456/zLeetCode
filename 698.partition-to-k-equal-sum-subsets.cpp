/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    bool dfs(vector<int> &nums, int index, int sum, int target, int cnt, int k, vector<int> used, int total_idx) {
        if (cnt == k)
            return true;
        if (sum == target) {
            return dfs(nums, total_idx - 1, 0, target, cnt + 1, k, used, total_idx - 1); // 一定要注意这里不是index - 1
        }

        for (int i = index; i >= 0; i--) {
            if (used[i] || sum + nums[i] > target)
                continue;
            used[i] = 1;
            if (dfs(nums, i - 1, sum + nums[i], target, cnt, k, used, total_idx))
                return true;
            used[i] = 0;
            if (sum == 0)
                return false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum % k != 0)
            return false;
        std::sort(nums.begin(), nums.end());
        if (nums.back() > sum / k)
            return false;
        vector<int> used(nums.size(), 0);
        return dfs(nums, nums.size() - 1, 0, sum / k, 0, k, used, nums.size() - 1);
    }
};
// @lc code=end
