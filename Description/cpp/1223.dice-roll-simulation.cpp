// Created by Bob at 2023/03/03 16:48
// https://leetcode.cn/problems/dice-roll-simulation/

/*
1223. 掷骰子模拟 (Hard)

有一个骰子模拟器会每次投掷的时候生成一个 1 到 6 的随机数。

不过我们在使用它时有个约束，就是使得投掷骰子时， **连续** 掷出数字 `i` 的次数不能超过
`rollMax[i]`（ `i` 从 1 开始编号）。

现在，给你一个整数数组 `rollMax` 和一个整数 `n`，请你来计算掷 `n` 次骰子可得到的不同点数序列的数量。

假如两个序列中至少存在一个元素不同，就认为这两个序列是不同的。由于答案可能很大，所以请返回 **模 `10^9 +
7`** 之后的结果。

**示例 1：**

```
输入：n = 2, rollMax = [1,1,2,2,2,3]
输出：34
解释：我们掷 2 次骰子，如果没有约束的话，共有 6 * 6 = 36 种可能的组合。但是根据 rollMax
数组，数字 1 和 2 最多连续出现一次，所以不会出现序列 (1,1) 和 (2,2)。因此，最终答案是 36-2 =
34。

```

**示例 2：**

```
输入：n = 2, rollMax = [1,1,1,1,1,1]
输出：30

```

**示例 3：**

```
输入：n = 3, rollMax = [1,1,1,2,2,3]
输出：181

```

**提示：**

- `1 <= n <= 5000`
- `rollMax.length == 6`
- `1 <= rollMax[i] <= 15`
*/

// @lc code=begin
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    long dfs(int idx, vector<int> &rollMax, int max_len, int last_num, vector<vector<vector<long>>> &cache, int mod) {
        if (idx == 0) {
            return 1;
        }
        if (cache[idx][max_len][last_num] >= 0) {
            return cache[idx][max_len][last_num] % mod;
        }
        long res = 0;
        if (max_len < rollMax[last_num]) {
            for (int i = 0; i < 6; ++i) {
                if (i == last_num) {
                    res += dfs(idx - 1, rollMax, max_len + 1, i, cache, mod);
                    res %= mod;
                } else {
                    res += dfs(idx - 1, rollMax, 1, i, cache, mod);
                    res %= mod;
                }
            }
        } else {
            for (int i = 0; i < 6; ++i) {
                if (i != last_num) {
                    res += dfs(idx - 1, rollMax, 1, i, cache, mod);
                    res %= mod;
                }
            }
        }
        cache[idx][max_len][last_num] = res % mod;
        return cache[idx][max_len][last_num];
    }
    int dieSimulator(int n, vector<int> &rollMax) {
        // 尝试记忆化搜索
        vector<vector<vector<long>>> cache(n + 1, vector<vector<long>>(16, vector<long>(6, -1)));
        int mod = 1000000007;
        return dfs(n, rollMax, 0, 6, cache, mod);
    }
};

// @lc code=end
