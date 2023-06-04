// Created by zwyyy456 at 2023/06/02 10:37
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

/*
1760. Minimum Limit of Balls in a Bag (Medium)
You are given an integer array `nums` where the `ith` bag contains `nums[i]` balls. You are also
given an integer `maxOperations`.

You can perform the following operation at most `maxOperations` times:

- Take any bag of balls and divide it into two new bags with a **positive** number of balls.

  - For example, a bag of `5` balls can become two new bags of `1` and `4` balls, or two new bags of
`2` and `3` balls.

Your penalty is the **maximum** number of balls in a bag. You want to **minimize** your penalty
after the operations.

Return the minimum possible penalty after performing the operations.

**Example 1:**

```
Input: nums = [9], maxOperations = 2
Output: 3
Explanation:
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.

```

**Example 2:**

```
Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.

```

**Constraints:**

- `1 <= nums.length <= 10⁵`
- `1 <= maxOperations, nums[i] <= 10⁹`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool Check(vector<int> &nums, int maxOperations, int num) {
        long cnt = 0;
        for (int i : nums) {
            cnt += (i - 1) / num;
        }
        return cnt <= maxOperations;
    }
    int minimumSize(vector<int> &nums, int maxOperations) {
        // 最小化最大值，考虑二分答案
        int left = 1;
        int right = 1000000001;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!Check(nums, maxOperations, mid)) {
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
    int maxOperations;
    LeetCodeIO::scan(cin, maxOperations);

    Solution *obj = new Solution();

    auto res = obj->minimumSize(nums, maxOperations);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
