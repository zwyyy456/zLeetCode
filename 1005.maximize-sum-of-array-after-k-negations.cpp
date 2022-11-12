/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        vector<int> posti;
        vector<int> nega;
        int sum_pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                posti.push_back(nums[i]);
                sum_pos += nums[i];
            } else
                nega.push_back(nums[i]);
        }
        std::sort(nega.begin(), nega.end());
        if (k <= nega.size()) {
            for (int i = 0; i < k; i++)
                sum_pos += -nega[i];
            for (int i = k; i < nega.size(); i++)
                sum_pos += nega[i];
        } else {
            if ((k - nega.size()) % 2 == 1) {
                std::sort(posti.begin(), posti.end());
                if (nega.size() == 0 || (posti.size() > 0 && posti[0] <= -nega[nega.size() - 1])) {
                    sum_pos -= 2 * posti[0];
                    for (int i = 0; i < nega.size(); i++)
                        sum_pos += -nega[i];
                } else {
                    for (int i = 0; i < nega.size(); i++)
                        sum_pos += -nega[i];
                    sum_pos += 2 * nega[nega.size() - 1];
                }
            } else {
                for (int i = 0; i < nega.size(); i++)
                    sum_pos += -nega[i];
            }
        }
        return sum_pos;
    }
};
// @lc code=end
