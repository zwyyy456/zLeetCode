/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
#include <unordered_set>
using std::unordered_set;
class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> happy;
        int sum = mysum(n);
        while (sum != 1) {
            if (happy.find(sum) != happy.end()) {
                return false;
            } else {
                happy.insert(sum);
                sum = mysum(sum);
            }
        }
        return true;
    }
    int mysum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
};
// @lc code=end
