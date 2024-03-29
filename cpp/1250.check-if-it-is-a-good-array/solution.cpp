// Created by Bob at 2023/02/15 14:54
// https://leetcode.com/problems/check-if-it-is-a-good-array/

/*
1250. Check If It Is a Good Array (Hard)

Given an array `nums` of positive integers. Your task is to select some subset of `nums`, multiply
each element by an integer and add all these numbers. The array is said to be **good** if you can
obtain a sum of `1` from the array by any possible subset and multiplicand.
Return `True` if the array is **good** otherwise return `False`.
**Example 1:**
```
Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1
```
**Example 2:**
```
Input: nums = [29,6,10]
Output: true
Explanation: Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1
```
**Example 3:**
```
Input: nums = [3,6]
Output: false
```
**Constraints:**
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int gcd(int a, int b) {
        // 其中b^=a,a^=b,b^=a相当于swap(a,b)
        while (b ^= (a ^= (b ^= (a %= b))))
            ;
        return a;
    }
    bool isGoodArray(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0] == 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            int tmp = gcd(nums[i], nums[i + 1]);
            if (tmp == 1) // 最大公因数已经是1了
                return true;
            nums[i + 1] = tmp;
        }
        return true;
    }
};

// @lc code=end
