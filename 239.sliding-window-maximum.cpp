/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <deque>
#include <vector>
using std::deque;
using std::vector;
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        for (int i = 1; i < nums.size() - k + 1; i++) {
            if (!dq.empty() && nums[i - 1] == dq.front()) {
                dq.pop_front();
                while (!dq.empty() && nums[i + k - 1] > dq.back())
                    dq.pop_back();
                dq.push_back(nums[i + k - 1]);
                res.push_back(dq.front());
            } else {
                while (!dq.empty() && nums[i + k - 1] > dq.back())
                    dq.pop_back();
                dq.push_back(nums[i + k - 1]);
                res.push_back(dq.front());
            }
        }
        return res;
    }
};
// @lc code=end
