/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int sum = nums[0]; // 保存变换序列后的临时sum
        int max_sum = nums[0];
        int i = 0;
        while (i < nums.size()) { // 先找出第一个正整数，如果没有正整数，最大和就是数组中的最小值
            if (nums[i] <= 0) {
                if (sum <= nums[i]) {
                    sum = nums[i];
                    max_sum = nums[i];
                }

            } else if (nums[i] > 0) {
                sum = nums[i];
                max_sum = nums[i];
                break;
            }
            i++;
        }
        int j = i + 1;
        while (j < nums.size()) {
            if (nums[j] >= 0) {
                sum += nums[j];
                if (sum > max_sum)
                    max_sum = sum;
            } else {
                while (j < nums.size() && nums[j] <= 0) {
                    sum += nums[j];
                    j++;
                }
                if (j < nums.size()) {
                    if (sum <= 0) {
                        sum = nums[j];
                        if (sum > max_sum)
                            max_sum = sum;
                    } else {
                        sum += nums[j];
                        if (sum > max_sum)
                            max_sum = sum;
                    }
                } else
                    return max_sum;
            }
            j++;
        }
        return max_sum;
    }
};
// @lc code=end
