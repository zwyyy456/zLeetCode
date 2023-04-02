// Created by zwyyy456 at 2023/03/31 14:29
// https://leetcode.com/problems/nim-game/

/*
292. Nim Game (Easy)

You are playing the following Nim Game with your friend:

- Initially, there is a heap of stones on the table.
- You and your friend will alternate taking turns, and **you go first**.
- On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
- The one who removes the last stone is the winner.

Given `n`, the number of stones in the heap, return `true` if you can win the game assuming both you
and your friend play optimally, otherwise return  `false`.

**Example 1:**

```
Input: n = 4
Output: false
Explanation: These are the possible outcomes:
1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
In all outcomes, your friend wins.

```

**Example 2:**

```
Input: n = 1
Output: true

```

**Example 3:**

```
Input: n = 2
Output: true

```

**Constraints:**

- `1 <= n <= 2³¹ - 1`
*/

// @lc code=begin
#include <vector>
using std::vector;
// class Solution {
// public:
//     bool dfs(int cnt, vector<int> &cach) {
//         if (cnt <= 0) {
//             return false;
//         }
//         if (cach[cnt] != -1) {
//             return cach[cnt];
//         }
//         cach[cnt] = (!dfs(cnt - 1, cach) || !dfs(cnt - 2, cach) || !dfs(cnt - 3, cach));
//         return cach[cnt];
//     }
//     bool canWinNim(int n) {
//         vector<int> cach(n + 1, -1);
//         return dfs(n, cach);
//     }
// };

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3) {
            return true;
        }
        bool res1 = true, res2 = true, res3 = true;
        bool res4;
        for (int i = 4; i < n; ++i) {
            res4 = (!res1 || !res2 || !res3);
            res1 = res2;
            res2 = res3;
            res3 = res4;
        }
        return res4;
    }
};

// @lc code=end
