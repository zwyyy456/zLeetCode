// Created by zwyyy456 at 2023/02/22 10:53
// https://leetcode.com/problems/stone-game-ii/

/*
1140. Stone Game II (Medium)

Alice and Bob continue their games with piles of stones.  There are a number of piles **arranged in
a row**, and each pile has a positive integer number of stones `piles[i]`.  The objective of the
game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.  Initially, `M = 1`.

On each player's turn, that player can take **all the stones** in the **first** `X` remaining piles,
where `1 <= X <= 2M`.  Then, we set `M = max(M, X)`.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

**Example 1:**

```
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2
piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning,
then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we
return 10 since it's larger.

```

**Example 2:**

```
Input: piles = [1,2,3,4,5,100]
Output: 104

```

**Constraints:**

- `1 <= piles.length <= 100`
- `1 <= piles[i] <= 10⁴`
*/

// @lc code=begin
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
public:
    int dfs(vector<int> &piles, int idx_start, int M, bool flag, vector<int> &prefix) {
        if (idx_start >= piles.size())
            return 0;
        if (flag) {  // flag为true表示由Alice选
            int maxnum = 0;
            for (int X = 1; X <= 2 * M && idx_start + X <= piles.size(); X++) {
                maxnum = std::max(maxnum, prefix[idx_start + X] - prefix[idx_start] + dfs(piles, idx_start + X, std::max(M, X), !flag, prefix));  
                return maxnum;
            }
        } else {
            int maxnum = 0;
            for (int X = 1; X <= 2 * M && idx_start + X <= piles.size(); X++) {
                maxnum = std::max(maxnum, dfs(piles, idx_start + X, std::max(M, X), !flag, prefix));
                return maxnum;
            }
        }
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> prefix(n + 1, 0); // 前缀和
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + piles[i - 1];
        }
        // 是否是类似背包的问题？
        return dfs(piles, 0, 1, true, prefix);
    }
};

// @lc code=end
