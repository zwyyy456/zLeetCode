// Created by zwyyy456 at 2023/05/21 17:39
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

/*
795. Number of Subarrays with Bounded Maximum (Medium)
Given an integer array `nums` and two integers `left` and `right`, return the number of contiguous
non-empty **subarrays** such that the value of the maximum array element in that subarray is in the
range  `[left, right]`.

The test cases are generated so that the answer will fit in a **32-bit** integer.

**Example 1:**

```
Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].

```

**Example 2:**

```
Input: nums = [2,9,2,5,6], left = 2, right = 8
Output: 7

```

**Constraints:**

- `1 <= nums.length <= 10⁵`
- `0 <= nums[i] <= 10⁹`
- `0 <= left <= right <= 10⁹`

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
        // 单调栈，以 nums[i] 为最大值的子数组的个数
        // 栈底到栈顶单调递减
        int res = 0;
        stack<int> stk;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                int idx = stk.top();
                int len1 = i - idx;
                int val = nums[idx];
                stk.pop();
                int len2 = stk.empty() ? idx + 1 : idx - stk.top();
                if (val <= right && val >= left) {
                    res += len1 * len2;
                }
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int idx = stk.top();
            int len1 = n - idx;
            int val = nums[idx];
            stk.pop();
            int len2 = stk.empty() ? idx + 1 : idx - stk.top();
            if (val <= right && val >= left) {
                res += len1 * len2;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int left;
    LeetCodeIO::scan(cin, left);
    int right;
    LeetCodeIO::scan(cin, right);

    Solution *obj = new Solution();

    auto res = obj->numSubarrayBoundedMax(nums, left, right);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
