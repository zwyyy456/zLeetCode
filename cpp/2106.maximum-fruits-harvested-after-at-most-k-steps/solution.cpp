// Created by zwyyy456 at 2023/05/04 09:30
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/

/*
2106. Maximum Fruits Harvested After at Most K Steps (Hard)
Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array
`fruits` where `fruits[i] = [positionᵢ, amountᵢ]` depicts `amountᵢ` fruits at the position
`positionᵢ`. `fruits` is already **sorted** by `positionᵢ` in **ascending order**, and each
`positionᵢ` is **unique**.

You are also given an integer `startPos` and an integer `k`. Initially, you are at the position
`startPos`. From any position, you can either walk to the **left or right**. It takes **one step**
to move **one unit** on the x-axis, and you can walk **at most** `k` steps in total. For every
position you reach, you harvest all the fruits at that position, and the fruits will disappear from
that position.

Return the **maximum total number** of fruits you can harvest.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/11/21/1.png)

```
Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
Output: 9
Explanation:
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/11/21/2.png)

```
Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
Output: 14
Explanation:
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2021/11/21/3.png)

```
Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
Output: 0
Explanation:
You can move at most k = 2 steps and cannot reach any position with fruits.

```

**Constraints:**

- `1 <= fruits.length <= 10⁵`
- `fruits[i].length == 2`
- `0 <= startPos, positionᵢ <= 2 * 10⁵`
- `positionᵢ-₁ < positionᵢ` for any `i > 0` ( **0-indexed**)
- `1 <= amountᵢ <= 10⁴`
- `0 <= k <= 2 * 10⁵`

*/

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
        // 前缀和
        // 统计前缀和时先不考虑 startPos 处的水果
        int len = max(startPos, fruits.back()[0]) + 1;
        int start_num = 0;
        int max_idx = 0;
        unordered_map<int, int> fruit_num;
        for (auto &vec : fruits) {
            max_idx = max(vec[0], max_idx);
            if (vec[0] != startPos) {
                fruit_num[vec[0]] = vec[1];
            } else {
                start_num = vec[1];
            }
        }
        vector<int> prefix(len + 1);
        for (int i = 1; i <= len; ++i) {
            if (fruit_num.find(i - 1) != fruit_num.end()) {
                prefix[i] = prefix[i - 1] + fruit_num[i - 1];
            } else {
                prefix[i] = prefix[i - 1];
            }
        }
        // 先考虑左边重复两次
        int res = 0;
        for (int l = 0; l <= startPos && l <= k; ++l) {
            int left_num = prefix[startPos + 1] - prefix[startPos - l];
            int right_num = 0;
            if (k - 2 * l >= 0) {
                int r = k - 2 * l + startPos;
                r = min(r, max_idx);
                right_num = prefix[r + 1] - prefix[startPos];
            }
            res = max(res, left_num + right_num);
        }
        // 再考虑右边重复两次
        for (int r = 0; r <= max_idx - startPos && r <= k; ++r) {
            int right_num = prefix[startPos + r + 1] - prefix[startPos + 1];
            int left_num = 0;
            if (k - 2 * r >= 0) {
                int l = startPos - (k - 2 * r);
                l = max(l, 0);
                left_num = prefix[startPos + 1] - prefix[l];
            }
            res = max(res, left_num + right_num);
        }
        return res + start_num;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> fruits;
    LeetCodeIO::scan(cin, fruits);
    int startPos;
    LeetCodeIO::scan(cin, startPos);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->maxTotalFruits(fruits, startPos, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
