/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
// to improve! binary_search to find left bound and right round
#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        vector<int> result;
        while (left <= right){
            mid = left + (right - left ) / 2;
            if (nums[mid] < target){
                left = mid + 1;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
            else{
                while (nums[left] != target)
                    left++;
                result.push_back(left);
                while (nums[right] != target)
                    right--;
                result.push_back(right);
                return result;
            }
        }
        result = {-1, -1};
        return result;  
    }
};
// @lc code=end

