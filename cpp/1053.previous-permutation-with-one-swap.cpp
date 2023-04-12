// Created by zwyyy456 at 2023/04/03 09:50
// https://leetcode.com/problems/previous-permutation-with-one-swap/

/*
1053. Previous Permutation With One Swap (Medium)

Given an array of positive integers `arr` (not necessarily distinct), return the lexicographically
largest permutation that is smaller than `arr`, that can be **made with exactly one swap**. If it
cannot be done, then return the same array.

**Note** that a swap exchanges the positions of two numbers `arr[i]` and `arr[j]`

**Example 1:**

```
Input: arr = [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.

```

**Example 2:**

```
Input: arr = [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.

```

**Example 3:**

```
Input: arr = [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.

```

**Constraints:**

- `1 <= arr.length <= 10⁴`
- `1 <= arr[i] <= 10⁴`
*/

// @lc code=begin
#include <vector>
#include <string>
#include <stack>
using std::stack;
using std::string;
using std::vector;
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        // 从右往左遍历，交换小的与第一个比它大的
        int left = 0, right = 0;
        stack<int> stk; // 存放索引
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[i] > arr[stk.top()]) {
                left = i;
                right = stk.top();
                stk.pop();
            }
            if (left < right) {
                std::swap(arr[left], arr[right]);
                return arr;
            }
            if (stk.empty()) {
                stk.push(i);
            } else {
                if (arr[i] == arr[stk.top()]) {
                    stk.pop();
                }
                stk.push(i);
            }
        }
        std::swap(arr[left], arr[right]);
        return arr;
    }
};


// @lc code=end
