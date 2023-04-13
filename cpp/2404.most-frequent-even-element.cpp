// Created by zwyyy456 at 2023/04/13 08:58
// https://leetcode.com/problems/most-frequent-even-element/

/*
2404. Most Frequent Even Element (Easy)

Given an integer array `nums`, return the most frequent even element.

If there is a tie, return the **smallest** one. If there is no such element, return `-1`.

**Example 1:**

```
Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.
```

**Example 2:**

```
Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.

```

**Example 3:**

```
Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.

```

**Constraints:**

- `1 <= nums.length <= 2000`
- `0 <= nums[i] <= 10⁵`
*/

// @lc code=begin
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (auto num : nums) {
            if (num % 2 == 0) {
                ++ump[num];
            }
        }
        int ans = -1, cnt = 0;
        for (auto &count : ump) {
            if (count.second > cnt) {
                cnt = count.second;
                ans = count.first;
            } else if (count.second == cnt) {
                ans = std::min(ans, count.first);
            }
        }
        return ans;
    }
};

// @lc code=end
