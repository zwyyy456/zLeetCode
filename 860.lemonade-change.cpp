/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    bool lemonadeChange(vector<int> &bills) {
        vector<int> num(3, 0);
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                num[0]++;
            else if (bills[i] == 10) {
                if (num[0] > 0) {
                    num[0]--;
                    num[1]++;
                } else {
                    return false;
                }
            } else {
                if (num[1] > 0) {
                    if (num[0] > 0) {
                        num[1]--;
                        num[0]--;
                    } else
                        return false;
                } else {
                    if (num[0] > 2)
                        num[0] -= 3;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
