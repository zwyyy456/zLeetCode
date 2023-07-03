// Created by zwyyy456 at 2023/02/19 21:09
// https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/

/*
1713. Minimum Operations to Make a Subsequence (Hard)

You are given an array `target` that consists of **distinct** integers and another integer array
`arr` that **can** have duplicates.

In one operation, you can insert any integer at any position in `arr`. For example, if `arr =
[1,4,1,2]`, you can add `3` in the middle and make it `[1,4,3,1,2]`. Note that you can insert the
integer at the very beginning or end of the array.

Return the **minimum** number of operations needed to make  `target` a **subsequence** of  `arr`.

A **subsequence** of an array is a new array generated from the original array by deleting some
elements (possibly none) without changing the remaining elements' relative order. For example,
`[2,7,4]` is a subsequence of `[4,2,3,7,2,1,4]` (the underlined elements), while `[2,4,2]` is not.

**Example 1:**

```
Input: target = [5,1,3], arr = [9,4,2,3,4]
Output: 2
Explanation: You can add 5 and 1 in such a way that makes arr = [5,9,4,1,2,3,4], then target will be
a subsequence of arr.

```

**Example 2:**

```
Input: target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
Output: 3

```

**Constraints:**

- `1 <= target.length, arr.length <= 10⁵`
- `1 <= target[i], arr[i] <= 10⁹`
- `target` contains no duplicates.
*/

// @lc code=begin
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
class Solution {
  public:
    int Bfind(vector<int> &new_arr, int len, int target) {
        int left = 1, right = len;
        int mid = left + (right - left) / 2;
        while (left < right) {
            if (new_arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
            mid = left + (right - left) / 2;
        }
        return left;
    }
    int minOperations(vector<int> &target, vector<int> &arr) {
        unordered_map<int, int> ust;
        for (int i = 0; i < target.size(); i++) {
            ust[target[i]] = i;
        }
        vector<int> new_arr;
        for (int &num : arr) {
            if (ust.find(num) != ust.end()) {
                new_arr.push_back(ust[num]);
            }
        }
        // 问题就变成了找new_arr的最长递增子序列
        int len = 1;
        vector<int> tail_len(target.size() + 1, new_arr[0]);
        for (int i = 1; i < target.size(); i++) {
            if (new_arr[i] > tail_len[len]) {
                len++;
                tail_len[len] = new_arr[i];
            } else {
                int idx = Bfind(new_arr, len, new_arr[i]);
                tail_len[idx] = new_arr[i];
            }
        }
        return len;
    }
};

// @lc code=end