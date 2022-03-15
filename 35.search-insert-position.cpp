/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto zbegin = nums.cbegin();
        auto zend = nums.cend();
        auto iter = zbegin + (zend - zbegin) / 2;
        while (zbegin < zend) {
            if (*iter == target)
                return (iter - zbegin);
            else if (target < *iter) {
                zend = iter;
                iter = zbegin + (zend - zbegin) / 2;
            }
            else {
                zbegin = iter + 1;
                iter = zbegin + (zend - zbegin) / 2;
            }
        }
        return (zend - nums.cbegin());
        
    }
};
// @lc code=end

