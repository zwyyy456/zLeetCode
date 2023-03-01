// Created by Bob at 2023/02/27 16:01
// https://leetcode.cn/problems/stone-game-ii/

/*
1140. 石子游戏 II (Medium)

爱丽丝和鲍勃继续他们的石子游戏。许多堆石子 **排成一行**，每堆都有正整数颗石子
`piles[i]`。游戏以谁手中的石子最多来决出胜负。

爱丽丝和鲍勃轮流进行，爱丽丝先开始。最初， `M = 1`。

在每个玩家的回合中，该玩家可以拿走剩下的 **前** `X` 堆的所有石子，其中 `1 <= X <= 2M`。然后，令
`M = max(M, X)`。

游戏一直持续到所有石子都被拿走。

假设爱丽丝和鲍勃都发挥出最佳水平，返回爱丽丝可以得到的最大数量的石头。

**示例 1：**

```
输入：piles = [2,7,9,4,4]
输出：10
解释：如果一开始Alice取了一堆，Bob取了两堆，然后Alice再取两堆。爱丽丝可以得到2 + 4 + 4 =
10堆。如果Alice一开始拿走了两堆，那么Bob可以拿走剩下的三堆。在这种情况下，Alice得到2 + 7 =
9堆。返回10，因为它更大。

```

**示例 2:**

```
输入：piles = [1,2,3,4,5,100]
输出：104

```

**提示：**

- `1 <= piles.length <= 100`
- `1 <= piles[i] <= 10⁴`
*/

// @lc code=begin
#include <climits>
#include <vector>
using std::vector;
class Solution {
  public:
    int stoneGameII(vector<int> &piles) {
        int n = piles.size();
        vector<int> postfix(n + 1, 0);
        // 后缀和数组
        for (int i = n - 1; i >= 0; i--) {
            postfix[i] = postfix[i + 1] + piles[i];
        }
        // dp[i][j]表示从坐标`i`开始拿`j`个所能获得的最大石子数
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= i / 2 + 1; M++) {
                if (i + 2 * M >= n) { // 说明可以直接拿走剩余的石子
                    dp[i][M] = postfix[i];
                } else {
                    int min_num = INT_MAX;
                    for (int x = 1; x <= 2 * M; x++) {
                        // 因为从dp[i + x]递推到dp[i]，所以`i`要倒序循环
                        min_num = std::min(min_num, dp[i + x][std::max(M, x)]);
                    }
                    dp[i][M] = postfix[i] - min_num;
                }
            }
        }
        return dp[0][1];
    }
};

// @lc code=end
