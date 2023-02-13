// Created by Bob at 2023/02/09 17:48
// https://leetcode.com/problems/maximum-length-of-pair-chain/

/*
646. Maximum Length of Pair Chain (Medium)

You are given an array of `n` pairs `pairs` where `pairs[i] = [leftᵢ, rightᵢ]` and `leftᵢ < rightᵢ`.
A pair `p2 = [c, d]` **follows** a pair `p1 = [a, b]` if `b < c`. A **chain** of pairs can be formed
in this fashion.
Return the length longest chain which can be formed.
You do not need to use up all the given intervals. You can select pairs in any order.
**Example 1:**
```
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
```
**Example 2:**
```
Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
```
**Constraints:**
- `n == pairs.length`
- `1 <= n <= 1000`
- `-1000 <= leftᵢ < rightᵢ <= 1000`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int findLongestChain(vector<vector<int>> &pairs) {
        std::sort(pairs.begin(), pairs.end(), [&](vector<int> vec1, vector<int> vec2) {
            if (vec1[1] == vec2[1]) {
                return vec1[0] < vec2[0];
            }
            return vec1[1] < vec2[1];
        });
        int r = pairs[0][1];
        int cnt = 1;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > r) {
                cnt++;
                r = pairs[i][1];
            }
        }
        return cnt;
    }
};

// @lc code=end
