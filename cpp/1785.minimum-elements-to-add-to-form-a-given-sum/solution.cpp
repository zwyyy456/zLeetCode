/*
 * @lc app=leetcode id=1785 lang=cpp
 *
 * [1785] Minimum Elements to Add to Form a Given Sum
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int minElements(vector<int> &nums, int limit, int goal) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        int target = goal - sum;
        if (target == 0)
            return 0;
        else if (target > 0) {
            if (target % limit == 0)
                return target / limit;
            else
                return target / limit + 1;
        } else {
            if (-target % (limit) == 0)
                return -target / limit;
            else
                return -target / limit + 1;
        }
    }
};
// @lc code=end
