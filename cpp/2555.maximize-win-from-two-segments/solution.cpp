// Created by zwyyy456 at 2023/02/05 19:56
// https://leetcode.com/problems/maximize-win-from-two-segments/

/*
2555. Maximize Win From Two Segments (Medium)

There are some prizes on the **X-axis**. You are given an integer array
`prizePositions` that is
**sorted in non-decreasing order**, where `prizePositions[i]` is the position of
the `ith` prize. There could be different prizes at the same position on the
line. You are also given an integer `k`. You are allowed to select two segments
with integer endpoints. The length of each segment must be `k`. You will collect
all prizes whose position falls within at least one of the two selected segments
(including the endpoints of the segments). The two selected segments may
intersect.
- For example if `k = 2`, you can choose segments `[1, 3]` and `[2, 4]`, and you
will win any prize i that satisfies `1 <= prizePositions[i] <= 3` or `2 <=
prizePositions[i] <= 4`. Return the **maximum** number of prizes you can win if
you choose the two segments optimally.
**Example 1:**
```
Input: prizePositions = [1,1,2,2,3,3,5], k = 2
Output: 7
Explanation: In this example, you can win all 7 prizes by selecting two segments
[1, 3] and [3, 5].
```
**Example 2:**
```
Input: prizePositions = [1,2,3,4], k = 0
Output: 2
Explanation: For this example, one choice for the segments is [3, 3] and [4, 4],
and you will be able to get 2 prizes.
```
**Constraints:**
- `1 <= prizePositions.length <= 10⁵`
- `1 <= prizePositions[i] <= 10⁹`
- `0 <= k <= 10⁹ `
- `prizePositions` is sorted in non-decreasing order.
*/

// @lc code=begin
#include <map>
#include <vector>
using std::map;
using std::vector;
class Solution {
  public:
    int maximizeWin(vector<int> &prizePositions, int k) {
        map<int, int> pos;
        for (int i : prizePositions)
            pos[i]++;
        // vector<int> pre(prizePositions[prizePositions.size() - 1] + 1, 0);
        // for (int i = 1; i <= k; i++) {
        //     if (pos.find(i) != pos.end())
        //         pre[i] = pre[i - 1] + pos[i];
        //     else
        //         pre[i] = pre[i - 1];
        // }
        vector<int> pre(pos.size() + 1, 0);
        int ans = 0;
        int i = 1;
        for (auto iter = pos.begin(); iter != pos.end(); iter++, i++) {
            if (iter->first <= k) {
                pre[i] = pre[i - 1] + iter->second;
            }
        }
    }
};

// @lc code=end
