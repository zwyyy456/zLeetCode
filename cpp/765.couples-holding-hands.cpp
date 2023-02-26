// Created by zwyyy456 at 2023/02/24 11:31
// https://leetcode.com/problems/couples-holding-hands/

/*
765. Couples Holding Hands (Hard)

There are `n` couples sitting in `2n` seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array `row` where `row[i]` is the ID of the
person sitting in the `ith` seat. The couples are numbered in order, the first couple being `(0,
1)`, the second couple being `(2, 3)`, and so on with the last couple being `(2n - 2, 2n - 1)`.

Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of
choosing any two people, then they stand up and switch seats.

**Example 1:**

```
Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

```

**Example 2:**

```
Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.

```

**Constraints:**

- `2n == row.length`
- `2 <= n <= 30`
- `n` is even.
- `0 <= row[i] < 2n`
- All the elements of `row` are **unique**.
*/

// @lc code=begin
#include <unordered_map>
#include <vector>
using std::vector;
class Solution {
  public:
    int minSwapsCouples(vector<int> &row) {
        std::unordered_map<int, int> ump; // row[i]为键，i为值
        for (int i = 0; i < row.size(); i++) {
            ump[row[i]] = i;
        }
        int cnt = 0;
        for (int i = 0; i < row.size(); i += 2) {
            // 应该还是要遍历row才对
            if (row[i] % 2 == 0) { // 偶数
                if (row[i + 1] != row[i] + 1) {
                    cnt++;
                    int tmp = ump[row[i] + 1]; // 原先的位置
                    int tmp_per = row[i + 1];  // i + 1座位上原先那个人的id
                    // 交换了row
                    row[i + 1] = row[i] + 1;
                    row[tmp] = tmp_per;
                    // 交换ump
                    ump[row[i] + 1] = i + 1;
                    ump[tmp_per] = tmp;
                }
            } else {
                if (row[i + 1] != row[i] - 1) {
                    cnt++;
                    int tmp = ump[row[i] - 1]; // 原先的位置
                    int tmp_per = row[i + 1];  // i + 1座位上原先那个人的id
                    // 交换了row
                    row[i + 1] = row[i] - 1;
                    row[tmp] = tmp_per;
                    // 交换ump
                    ump[row[i] - 1] = i + 1;
                    ump[tmp_per] = tmp;
                }
            }
        }
        return cnt;
    }
};

// @lc code=end
