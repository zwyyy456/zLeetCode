// Created by zwyyy456 at 2023/02/26 19:52
// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/

/*
2170. Minimum Operations to Make the Array Alternating (Medium)

You are given a **0-indexed** array `nums` consisting of `n` positive integers.

The array `nums` is called **alternating** if:

- `nums[i - 2] == nums[i]`, where `2 <= i <= n - 1`.
- `nums[i - 1] != nums[i]`, where `1 <= i <= n - 1`.

In one **operation**, you can choose an index `i` and **change** `nums[i]` into **any** positive
integer.

Return the **minimum number of operations** required to make the array alternating.

**Example 1:**

```
Input: nums = [3,1,3,2,4,3]
Output: 3
Explanation:
One way to make the array alternating is by converting it to [3,1,3,1,3,1].
The number of operations required in this case is 3.
It can be proven that it is not possible to make the array alternating in less than 3 operations.

```

**Example 2:**

```
Input: nums = [1,2,2,2,2]
Output: 2
Explanation:
One way to make the array alternating is by converting it to [1,2,1,2,1].
The number of operations required in this case is 2.
Note that the array cannot be converted to [2,2,2,2,2] because in this case nums[0] == nums[1] which
violates the conditions of an alternating array.

```

**Constraints:**

- `1 <= nums.length <= 10⁵`
- `1 <= nums[i] <= 10⁵`
*/

// @lc code=begin
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
using std::pair;
using std::priority_queue;
using std::vector;
using std::unordered_map;
class Solution {
  public:
    // map，内部元素为pair<int, int> 数字以及数字出现个数
    int minimumOperations(vector<int> &nums) {
        auto cmp = [&](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.second < p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq1(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq2(cmp);
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < nums.size(); i += 2) {
            mp1[nums[i]]++;
            if (i + 1 < nums.size()) {
                mp2[nums[i + 1]]++;
            }
        }
        int max_1 = 0, second_1 = 0;
        int max_num1 = 0, second_num1 = 0;
        int max_2 = 0, second_2 = 0;
        int max_num2 = 0, second_num2 = 0;
        for (auto &p1 : mp1) {
            if (p1.second >= max_1) {
                second_1 = max_1;
                second_num1 = max_num1;
                max_1 = p1.second;
                max_num1 = p1.first;
            } else if (p1.second >= second_1) {
                second_1 = p1.second;
                second_num1 = p1.first;
            }
        }
        for (auto &p2 : mp2) {
            if (p2.second >= max_2) {
                second_2 = max_2;
                second_num2 = max_num2;
                max_2 = p2.second;
                max_num2 = p2.first;
            } else if (p2.second >= second_2) {
                second_2 = p2.second;
                second_num2 = p2.first;
            }
        }
        if (max_num1 != max_num2) {
            return nums.size() - max_1 - max_2;
        }
        return std::min(nums.size() - max_1 - second_2, nums.size() - max_2 - second_1);
    }
};

// @lc code=end
