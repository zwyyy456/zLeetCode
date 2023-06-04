// Created by zwyyy456 at 2023/05/21 11:44
// https://leetcode.com/problems/sum-of-subarray-ranges/

/*
2104. Sum of Subarray Ranges (Medium)
You are given an integer array `nums`. The **range** of a subarray of `nums` is the difference
between the largest and smallest element in the subarray.

Return the **sum of all** subarray ranges of  `nums`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
```

**Example 2:**

```
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

```

**Example 3:**

```
Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.

```

**Constraints:**

- `1 <= nums.length <= 1000`
- `-10⁹ <= nums[i] <= 10⁹`

**Follow-up:** Could you find a solution with `O(n)` time complexity?

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    long long subArrayRanges(vector<int> &nums) {
        // 结果可以表示为所有子数组的最大值的和减去最小值的和
        // 对 nums[i]，假设有 nums[idx] <= nums[i] 小且 idx <= i 的最大 idx 为 l，
        // 同理最小 idx 为 r，则以 nums[idx] 为最大值的子数组共有 (r - idx + 1) * (idx - l + 1)；
        // 可以用单调递减栈来解决，从栈底到栈顶单调递减
        stack<int> stk;
        int n = nums.size();
        long sum_max = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                int len1 = i - stk.top();
                int idx = stk.top();
                long val = nums[idx];
                stk.pop();
                int len2 = stk.empty() ? idx + 1 : idx - stk.top();
                sum_max += val * len1 * len2;
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int idx = stk.top();
            int len1 = n - idx;
            long val = nums[idx];
            stk.pop();
            int len2 = stk.empty() ? idx + 1 : idx - stk.top();
            sum_max += val * len1 * len2;
        }
        long sum_min = 0;
        stack<int> stk_min;
        for (int i = 0; i < n; ++i) {
            while (!stk_min.empty() && nums[i] < nums[stk_min.top()]) {
                int idx = stk_min.top();
                int len1 = i - idx;
                long val = nums[idx];
                stk_min.pop();
                int len2 = stk_min.empty() ? idx + 1 : idx - stk_min.top();
                sum_min += val * len1 * len2;
            }
            stk_min.push(i);
        }
        while (!stk_min.empty()) {
            int idx = stk_min.top();
            int len1 = n - idx;
            long val = nums[idx];
            stk_min.pop();
            int len2 = stk_min.empty() ? idx + 1 : idx - stk_min.top();
            sum_min += val * len1 * len2;
        }
        return sum_max - sum_min;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();

    auto res = obj->subArrayRanges(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
