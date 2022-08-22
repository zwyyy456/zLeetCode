/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        // vector<long long> nums;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        long long mtarget = target;
        if (nums.size() < 4)
            return res;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right] < mtarget) {
                        left++;
                        while (nums[left - 1] == nums[left] && left < right - 1)
                            left++;
                    } else if ((long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right] > mtarget) {
                        right--;
                        while (nums[right + 1] == nums[right] && left < right - 1)
                            right--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        while (nums[left - 1] == nums[left] && left < right - 1)
                            left++;
                        right--;
                        while (nums[left - 1] == nums[left] && left < right - 1)
                            right--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
