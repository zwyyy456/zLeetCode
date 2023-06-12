// Created by zwyyy456 at 2023/06/01 09:37
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

/*
1283. Find the Smallest Divisor Given a Threshold (Medium)
Given an array of integers `nums` and an integer `threshold`, we will choose a positive integer
`divisor`, divide all the array by it, and sum the division's result. Find the **smallest**
`divisor` such that the result mentioned above is less than or equal to `threshold`.

Each result of the division is rounded to the nearest integer greater than or equal to that element.
(For example: `7/3 = 3` and `10/2 = 5`).

The test cases are generated so that there will be an answer.

**Example 1:**

```
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5
(1+1+1+2).

```

**Example 2:**

```
Input: nums = [44,22,33,11,1], threshold = 5
Output: 44

```

**Constraints:**

- `1 <= nums.length <= 5 * 10⁴`
- `1 <= nums[i] <= 10⁶`
- `nums.length <= threshold <= 10⁶`

*/

#include <bits/stdc++.h>
#include <numeric>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool Check(int mid, vector<int> &nums, int threshold) {
        long sum = 0;
        for (int num : nums) {
            sum += (num - 1) / mid + 1;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int> &nums, int threshold) {
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        long right = (sum / max(1, threshold / 2)) + 100;
        // cout << right << endl;
        long left = 1;
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (!Check(mid, nums, threshold)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int threshold;
    LeetCodeIO::scan(cin, threshold);

    Solution *obj = new Solution();

    auto res = obj->smallestDivisor(nums, threshold);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
