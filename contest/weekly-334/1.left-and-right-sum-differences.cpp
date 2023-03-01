// Created by zwyyy456 at 2023/02/26 14:41
// https://leetcode.com/problems/left-and-right-sum-differences/
// https://leetcode.com/contest/weekly-contest-334/problems/left-and-right-sum-differences/

/*
2574. Left and Right Sum Differences (Easy)

Given a **0-indexed** integer array `nums`, find a **0-indexed** integer array `answer` where:

- `answer.length == nums.length`.
- `answer[i] = |leftSum[i] - rightSum[i]|`.

Where:

- `leftSum[i]` is the sum of elements to the left of the index `i` in the array `nums`. If there is
no such element, `leftSum[i] = 0`.
- `rightSum[i]` is the sum of elements to the right of the index `i` in the array `nums`. If there
is no such element, `rightSum[i] = 0`.

Return the array `answer`.

**Example 1:**

```
Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

```

**Example 2:**

```
Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].

```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 10⁵`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n + 1, 0);
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i + 1];
        }
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            answer[i] = abs(prefix[i] - suffix[i]);
        }
        return answer;
    }
};

// @lc code=end
