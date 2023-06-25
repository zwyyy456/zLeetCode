// Created by zwyyy456 at 2023/03/02 16:54
// https://leetcode.com/problems/can-i-win/

/*
464. Can I Win (Medium)

In the "100 game" two players take turns adding, to a running total, any integer from `1` to `10`.
The player who first causes the running total to **reach or exceed** 100 wins.

What if we change the game so that players **cannot** re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without
replacement until they reach a total >= 100.

Given two integers `maxChoosableInteger` and `desiredTotal`, return `true` if the first player to
move can force a win, otherwise, return `false`. Assume both players play **optimally**.

**Example 1:**

```
Input: maxChoosableInteger = 10, desiredTotal = 11
Output: false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

```

**Example 2:**

```
Input: maxChoosableInteger = 10, desiredTotal = 0
Output: true

```

**Example 3:**

```
Input: maxChoosableInteger = 10, desiredTotal = 1
Output: true

```

**Constraints:**

- `1 <= maxChoosableInteger <= 20`
- `0 <= desiredTotal <= 300`
*/

// @lc code=begin
#include <unordered_map>
using std::unordered_map;
class Solution {
  public:
    // 改写成位运算的形式
    bool dfs(int desired_total, int cur_total, int bit20, int max_int, unordered_map<int, int> &ump) {
        if (desired_total <= 0) {
            return false;
        }
        if (bit20 == 0) {
            return true;
        }
        if (ump.find(bit20) != ump.end()) {
            return ump[bit20];
        }
        bool tmp = false;
        int cnt = 1;
        for (int i = max_int - 1; i >= 0; --i) {
            if ((bit20 & (1 << i)) != 0) { // 说明数i + 1还没有被选
                int mask = (bit20 ^ (1 << i));
                tmp = tmp || (!dfs(desired_total - i - 1, cur_total + i + 1, mask, max_int, ump));
            }
            if (tmp) {
                ump[bit20] = true;
                return ump[bit20];
            }
        }
        ump[bit20] = false;
        return ump[bit20];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) {
            return true;
        }
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        unordered_map<int, int> ump;
        int bit20 = (1 << maxChoosableInteger) - 1;
        return dfs(desiredTotal, 0, bit20, maxChoosableInteger, ump);
    }
};

// @lc code=end
