/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <algorithm>
#include <deque>
#include <vector>
using std::deque;
using std::vector;
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        deque<int> dq;
        int len;
        std::sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            int l = i;
            while (nums[i] == nums[l]) {
                i++;
            }
            len = i - l;
            while (!dq.empty() && len > dq.back()) {
                dq.push_back(1);
            }
        }
    }
};
// @lc code=end
