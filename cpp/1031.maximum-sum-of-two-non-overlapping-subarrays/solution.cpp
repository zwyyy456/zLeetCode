// Created by zwyyy456 at 2023/04/26 09:44
// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

/*
1031. Maximum Sum of Two Non-Overlapping Subarrays (Medium)
Given an integer array `nums` and two integers `firstLen` and `secondLen`, return the maximum sum of
elements in two non-overlapping **subarrays** with lengths  `firstLen` and  `secondLen`.

The array with length `firstLen` could occur before or after the array with length `secondLen`, but
they have to be non-overlapping.

A **subarray** is a **contiguous** part of an array.

**Example 1:**

```
Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

```

**Example 2:**

```
Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

```

**Example 3:**

```
Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.

```

**Constraints:**

- `1 <= firstLen, secondLen <= 1000`
- `2 <= firstLen + secondLen <= 1000`
- `firstLen + secondLen <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int res = 0;
        int tmp = 0;
        for (int i = 0; i <= n - firstLen - secondLen; ++i) {
            tmp = max(tmp, prefix[i + firstLen] - prefix[i]);
            res = max(res, tmp + prefix[i + firstLen + secondLen] - prefix[i + firstLen]);
        }
        tmp = 0;
        for (int i = 0; i <= n - firstLen - secondLen; ++i) {
            tmp = max(tmp, prefix[i + secondLen] - prefix[i]);
            res = max(res, tmp + prefix[i + secondLen + firstLen] - prefix[i + secondLen]);
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
    int firstLen;
    LeetCodeIO::scan(cin, firstLen);
    int secondLen;
    LeetCodeIO::scan(cin, secondLen);

    Solution *obj = new Solution();

    auto res = obj->maxSumTwoNoOverlap(nums, firstLen, secondLen);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
