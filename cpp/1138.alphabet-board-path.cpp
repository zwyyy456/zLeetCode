// Created by Bob at 2023/02/12 17:41
// https://leetcode.com/problems/alphabet-board-path/

/*
1138. Alphabet Board Path (Medium)

On an alphabet board, we start at position `(0, 0)`, corresponding to character `board[0][0]`.
Here, `board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]`, as shown in the diagram below.
![](https://assets.leetcode.com/uploads/2019/07/28/azboard.png)
We may make the following moves:
- `'U'` moves our position up one row, if the position exists on the board;
- `'D'` moves our position down one row, if the position exists on the board;
- `'L'` moves our position left one column, if the position exists on the board;
- `'R'` moves our position right one column, if the position exists on the board;
- `'!'` adds the character `board[r][c]` at our current position `(r, c)` to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)
Return a sequence of moves that makes our answer equal to `target` in the minimum number of moves.
You may return any path that does so.
**Example 1:**
```
Input: target = "leet"
Output: "DDR!UURRR!!DDD!"
```
**Example 2:**
```
Input: target = "code"
Output: "RR!DDRR!UUL!R!"
```
**Constraints:**
- `1 <= target.length <= 100`
- `target` consists only of English lowercase letters.
*/

// @lc code=begin
#include <string>
#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::string;

class Solution {
  public:
    string alphabetBoardPath(string target) {
        string res;
        vector<int> cur_loc{0, 0};
        vector<int> target_loc{0, 0};
        // 要注意边缘的存在
        for (auto &c : target) {
            target_loc[0] = (c - 'a') / 5;
            target_loc[1] = (c - 'a') % 5;
            int move_row = target_loc[0] - cur_loc[0];
            int move_col = target_loc[1] - cur_loc[1];
            cur_loc[0] = target_loc[0];
            cur_loc[1] = target_loc[1];
            if (move_col < 0) {
                res.insert(res.end(), -move_col, 'L');
                if (move_row >= 0)
                    res.insert(res.end(), move_row, 'D');
                else
                    res.insert(res.end(), -move_row, 'U');
            } else {
                if (move_row >= 0)
                    res.insert(res.end(), move_row, 'D');
                else
                    res.insert(res.end(), -move_row, 'U');
                res.insert(res.end(), move_col, 'R');
            }
            res.push_back('!');
        }
        return res;
    }
};

// @lc code=end
