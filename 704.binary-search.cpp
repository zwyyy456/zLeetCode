/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto small = nums.cbegin();
        auto big = nums.cend();
        if (target < *small || target > *(big - 1) || small == big + 1)
            return -1;
        else{
            auto iter = small + (big - small) / 2;
            while ( small != big){
                if (target == *iter){
                    return iter - nums.cbegin();
                }
                else if (target < *iter){
                    big = iter ;
                    iter = small + (big - small) / 2;
                }
                else
                    small = iter + 1;
                    iter = small + (big - small) / 2;
            }
            return -1;
        }
    }
};

int main()
{
    Solution zwy;
    vector<int> test_num{-1, 0, 3, 5, 9, 12};
    std::cout << zwy.search(test_num, 9) << std::endl;
}
// @lc code=end

