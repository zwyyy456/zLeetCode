// Created by zwyyy456 at 2023/05/29 12:53
// https://leetcode.com/problems/power-of-heroes/

/*
2681. Power of Heroes (Hard)
You are given a **0-indexed** integer array `nums` representing the strength of some heroes. The
**power** of a group of heroes is defined as follows:

- Let `i₀`, `i₁`, ... , `iₖ` be the indices of the heroes in a group. Then, the power of this group
is `max(nums[i₀], nums[i₁], ... ,nums[iₖ])² * min(nums[i₀], nums[i₁], ... ,nums[iₖ])`.

Return the sum of the **power** of all **non-empty** groups of heroes possible. Since the sum could
be very large, return it **modulo** `10⁹ + 7`.

**Example 1:**

```
Input: nums = [2,1,4]
Output: 141
Explanation:
1st group: [2] has power = 2² * 2 = 8.
2ⁿd group: [1] has power = 1² * 1 = 1.
3rd group: [4] has power = 4² * 4 = 64.
4th group: [2,1] has power = 2² * 1 = 4.
5th group: [2,4] has power = 4² * 2 = 32.
6th group: [1,4] has power = 4² * 1 = 16.
7th group: [2,1,4] has power = 4² * 1 = 16.
The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.

```

**Example 2:**

```
Input: nums = [1,1,1]
Output: 7
Explanation: A total of 7 groups are possible, and the power of each group will be 1. Therefore, the
sum of the powers of all groups is 7.

```

**Constraints:**

- `1 <= nums.length <= 10⁵`
- `1 <= nums[i] <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int sumOfPower(vector<int> &nums) {
        int mod = 1000000007;
        sort(nums.begin(), nums.end());
        long res = 0;
        long s = 0;
        int n = nums.size();
        for (long num : nums) {
            res = (res + ((num * num) % mod) * ((num + s) % mod)) % mod;
            s = (2 * s + num) % mod;
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

    Solution *obj = new Solution();

    auto res = obj->sumOfPower(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
