// Created by zwyyy456 at 2023/04/08 21:13
// https://leetcode.com/problems/sliding-puzzle/

/*
773. Sliding Puzzle (Hard)

On an `2 x 3` board, there are five tiles labeled from `1` to `5`, and an empty square represented
by `0`. A **move** consists of choosing `0` and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is `[[1,2,3],[4,5,0]]`.

Given the puzzle board `board`, return the least number of moves required so that the state of the
board is solved. If it is impossible for the state of the board to be solved, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/06/29/slide1-grid.jpg)

```
Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/06/29/slide2-grid.jpg)

```
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2021/06/29/slide3-grid.jpg)

```
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]

```

**Constraints:**

- `board.length == 2`
- `board[i].length == 3`
- `0 <= board[i][j] <= 5`
- Each value `board[i][j]` is **unique**.
*/

// @lc code=begin
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>
using std::vector;
using std::pair;
using std::queue;
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        std::string dst("123450");
        vector<vector<int>> move{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // 如何确定这个visited?
        std::unordered_set<std::string> vis;
        std::string start;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                start.push_back(board[i][j] + '0');
            }
        }
        queue<pair<std::string, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            auto [str, dis] = q.front();
            q.pop();
            if (str == dst) {
                return dis;
            }
            char arr[2][3] = {0};
            int x = 0, y = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 3; ++j) {
                    arr[i][j] = str[i * 3 + j];
                    if (arr[i][j] == '0') {
                        x = i;
                        y = j;
                    }
                }
            }
            for (int i = 0; i < 4; ++i) {
                int new_x = x + move[i][0];
                int new_y = y + move[i][1];
                if (new_x < 0 || new_x >= 2 || new_y < 0 || new_y >= 3) {
                    continue;
                }
                std::string tmp;
                std::swap(arr[x][y], arr[new_x][new_y]);
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        tmp.push_back(arr[i][j]);
                    }
                }
                std::swap(arr[x][y], arr[new_x][new_y]);
                if (vis.find(tmp) == vis.end()) {
                    vis.insert(tmp);
                    q.push({tmp, dis + 1});
                }
            }
        }
        return -1;
    }
};

// @lc code=end
