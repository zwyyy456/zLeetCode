// Created by zwyyy456 at 2023/02/25 14:02
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
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    int dfs(int idx_start, int M, vector<int> &postfix, bool flag, int n, vector<vector<int>> &cach) {
        if (idx_start >= n)
            return 0;
        if (flag) {
            int minnum = 100001;
            for (int i = idx_start + 1; i <= idx_start +  2 * M && i <= n; i++) { // i表示下一个人拿石子的开始位置，所以i至少为idx_start+1
                if (cach[i][0] >= 0) {
                    if (minnum > cach[i][0]) {
                        minnum = cach[i][0];
                    }
                } else {
                    cach[i][0] = dfs(i, std::max(i - idx_start, M), postfix, false, n, cach);
                    if (minnum > cach[i][0]) {
                        minnum = cach[i][0];
                    }
                }
            }
            return postfix[idx_start] - minnum;
        } else {
            int minnum = 100001;
            for (int i = idx_start + 1; i <= idx_start +  2 * M && i <= n; i++) {
                if (cach[i][1] >= 0) {
                    if (minnum > cach[i][1]) {
                        minnum = cach[i][1];
                    }
                } else {
                    cach[i][1] = dfs(i, std::max(i - idx_start, M), postfix, true, n, cach);
                    if (minnum > cach[i][1]) {
                        minnum = cach[i][1];
                    }
                }
            }
            return postfix[idx_start] - minnum;
        }
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> postfix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            postfix[i] = postfix[i + 1] + piles[i];
        }
        vector<vector<int>> cach(n + 1, vector<int>(2, -1));
        return dfs(0, 1, postfix, true, n, cach);
    }
};

// @lc code=end
