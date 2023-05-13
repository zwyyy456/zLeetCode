// Created by zwyyy456 at 2023/04/30 17:13
// https://leetcode.com/problems/moving-stones-until-consecutive/

/*
1033. Moving Stones Until Consecutive (Medium)
There are three stones in different positions on the X-axis. You are given three integers `a`, `b`,
and `c`, the positions of the stones.

In one move, you pick up a stone at an endpoint (i.e., either the lowest or highest position stone),
and move it to an unoccupied position between those endpoints. Formally, let's say the stones are
currently at positions `x`, `y`, and `z` with `x < y < z`. You pick up the stone at either position
`x` or position `z`, and move that stone to an integer position `k`, with `x < k < z` and `k != y`.

The game ends when you cannot make any more moves (i.e., the stones are in three consecutive
positions).

Return an integer array  `answer` of length  `2` where:

- `answer[0]`is the minimum number of moves you can play, and
- `answer[1]`is the maximum number of moves you can play.

**Example 1:**

```
Input: a = 1, b = 2, c = 5
Output: [1,2]
Explanation: Move the stone from 5 to 3, or move the stone from 5 to 4 to 3.

```

**Example 2:**

```
Input: a = 4, b = 3, c = 2
Output: [0,0]
Explanation: We cannot make any moves.

```

**Example 3:**

```
Input: a = 3, b = 5, c = 1
Output: [1,2]
Explanation: Move the stone from 1 to 4; or move the stone from 1 to 2 to 4.

```

**Constraints:**

- `1 <= a, b, c <= 100`
- `a`, `b`, and `c` have different values.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> vec{a, b, c};
        sort(vec.begin(), vec.end());
        if (vec[2] - vec[0] == 2) {
            return {0, 0};
        }
        vector<int> len{b - a, c - b};
        int max_num = max(vec[1] - vec[0], vec[2] - vec[1]) - 1;
        int min_num = 0;
        while (max(len[0], len[1]) > 1) {
            ++min_num;
            len[1] = len[0] - len[0] / 2;
            len[0] = len[0] / 2;
        }
        return {min_num, max_num};
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int a;
    LeetCodeIO::scan(cin, a);
    int b;
    LeetCodeIO::scan(cin, b);
    int c;
    LeetCodeIO::scan(cin, c);

    Solution *obj = new Solution();

    auto res = obj->numMovesStones(a, b, c);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
