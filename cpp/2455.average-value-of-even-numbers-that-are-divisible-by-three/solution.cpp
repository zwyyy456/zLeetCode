// Created by zwyyy456 at 2023/05/29 08:54
// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/

/*
2455. Average Value of Even Numbers That Are Divisible by Three (Easy)
Given an integer array `nums` of **positive** integers, return the average value of all even
integers that are divisible by `3` _._

Note that the **average** of `n` elements is the **sum** of the `n` elements divided by `n` and
**rounded down** to the nearest integer.

**Example 1:**

```
Input: nums = [1,3,6,10,12,15]
Output: 9
Explanation: 6 and 12 are even numbers that are divisible by 3. (6 + 12) / 2 = 9.

```

**Example 2:**

```
Input: nums = [1,2,4,7,10]
Output: 0
Explanation: There is no single number that satisfies the requirement, so return 0.

```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int averageValue(vector<int> &nums) {
        int sum = 0, cnt = 0;
        for (int num : nums) {
            if (num % 6 == 0) {
                sum += num;
                ++cnt;
            }
        }
        if (cnt == 0) {
            return 0;
        }
        return sum / cnt;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();

    auto res = obj->averageValue(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
