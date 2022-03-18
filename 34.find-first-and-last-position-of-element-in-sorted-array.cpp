/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = left + (right - left) / 2;
        vector<int> result;
        while (left < right){
            if (nums[mid] < target){
                left = mid + 1;
                mid = left + (right - left ) / 2;
            }
            else if (nums[mid] > target){
                right = mid - 1;
                mid = left + (right - left ) / 2;
            }
            else{
                int rmid = mid;
                while (nums[mid] == target)
                    mid--;
                result.push_back(mid + 1);
                while (nums[rmid] == target)
                    rmid++;
                result.push_back(rmid - 1);
                return result;
            }
        }
        result = {-1, -1};
        return result;  
    }
};
// @lc code=end

